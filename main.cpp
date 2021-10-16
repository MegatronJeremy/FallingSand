#include <iostream>
#include <windows.h>
#include "Particle.h"
using namespace std;

const int YELLOW = 14;
const int WHITE = 15;

void clearScreen(int characterLength) {
    for (int i = 0; i < characterLength; i++) {
        cout << "\b";
    }
}

void changeColour(int colour) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, colour);
}

void goToXY(int line, int column) {
    COORD coord;
    coord.X = static_cast<short>(column);
    coord.Y = static_cast<short>(line);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, coord);
}

void clearScreen(int width, int height) {
    for (int i = 0; i < height; i++) {
        goToXY(height - i, width * 3);
        for (int j = 0; j < 4 * width; j++)
            cout << "\b \b";
    }

}

void drawScreen(ParticleMap *mp, int width, int height) {
    for (int i = 1; i < height; i++) {
        for (int j = 0; j < width; j++) {
            changeColour(mp->get(i, j)->getId());
            cout << '*' << "  ";
        }
        cout << '\n';
    }
}

void update(ParticleMap *mp, int width, int height) {
    for (int i = 1; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mp->update(i, j);
        }
    }
}

void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
            console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
            console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

int main() {
    auto *mp = new ParticleMap(9, 8);
    mp->get(1, 4) = new Water();
    while (!mp->updateCnt()) {
        mp->get(0, 4) = new Water();
        drawScreen(mp, mp->getWidth(), mp->getHeight());
        Sleep(100);
        clear();
        for (int i = mp->getHeight() - 1; i >= 0; i--) {
            for (int j = 0; j < mp->getWidth(); j++)
                mp->update(i, j);
        }
    }
    delete mp;
    return 0;
}
