#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;
void gotoxy(short x, short y);
char getCharAtxy(short int x, short int y);

int ghostx = 5;
int ghosty = 5;

int pacmanX = 3;
int pacmanY = 5;

string ghostDirection = "Right";
char previous = ' ';

void movePacmanLeft();
void movePacmanRight();
void movePacmanUp();
void movePacmanDown();
void moveGhostHorizontal();
void printMaze();

int main()
{
    system("cls");
    bool gameRunning = true;

    printMaze();

    gotoxy(pacmanX, pacmanY);
    cout << "P";
    while (gameRunning)
    {
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePacmanLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePacmanRight();
        }

        if (GetAsyncKeyState(VK_UP))
        {
            movePacmanUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePacmanDown();
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameRunning = false;
        }

        moveGhostHorizontal();
        Sleep(100);
    }
}
void movePacmanUp()
{
    char next = getCharAtxy(pacmanX, pacmanY - 1);
    if (next == ' ' || next == '.')
    {
        gotoxy(pacmanX, pacmanY);
        cout << " ";
        pacmanY = pacmanY - 1;
        gotoxy(pacmanX, pacmanY);
        cout << "P";
    }
}
void movePacmanDown()
{
    char next = getCharAtxy(pacmanX, pacmanY + 1);
    if (next == ' ' || next == '.')
    {
        gotoxy(pacmanX, pacmanY);
        cout << " ";
        pacmanY = pacmanY + 1;
        gotoxy(pacmanX, pacmanY);
        cout << "P";
    }
}

void movePacmanRight()
{
    char next = getCharAtxy(pacmanX + 1, pacmanY);
    if (next == ' ' || next == '.')
    {
        gotoxy(pacmanX, pacmanY);
        cout << " ";
        pacmanX = pacmanX + 1;
        gotoxy(pacmanX, pacmanY);
        cout << "P";
    }
}
void movePacmanLeft()
{
    char next = getCharAtxy(pacmanX - 1, pacmanY);
    if (next == ' ' || next == '.')
    {
        gotoxy(pacmanX, pacmanY);
        cout << " ";
        pacmanX = pacmanX - 1;
        gotoxy(pacmanX, pacmanY);
        cout << "P";
    }
}

void moveGhostHorizontal()
{

    if (ghostDirection == "Left")
    {
        char next = getCharAtxy(ghostx - 1, ghosty);
        if (next == ' ' || next == '.')
        {
            gotoxy(ghostx, ghosty);
            cout << previous;
            previous = next;
            ghostx = ghostx - 1;
            gotoxy(ghostx, ghosty);
            cout << "G";
        }
        if (next == '%')
        {
            ghostDirection = "Right";
        }
    }

    if (ghostDirection == "Right")
    {
        char next = getCharAtxy(ghostx + 1, ghosty);
        if (next == ' ' || next == '.')
        {
            gotoxy(ghostx, ghosty);
            cout << previous;
            previous = next;
            ghostx = ghostx + 1;
            gotoxy(ghostx, ghosty);
            cout << "G";
        }
        if (next == '%')
        {
            ghostDirection = "Left";
        }
    }
}
void gotoxy(short x, short y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x, y};
    SetConsoleCursorPosition(hStdout, position);
}

void printMaze()
{
    cout << "%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "%      .           %" << endl;
    cout << "%      .           %" << endl;
    cout << "%      .           %" << endl;
    cout << "%      .           %" << endl;
    cout << "%      .           %" << endl;
    cout << "%      .           %" << endl;
    cout << "%      .           %" << endl;
    cout << "%      .           %" << endl;
    cout << "%%%%%%%%%%%%%%%%%%%%" << endl;
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
