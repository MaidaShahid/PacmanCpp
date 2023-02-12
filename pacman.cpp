#include <iostream>
#include <windows.h>

using namespace std;

// Global Variables
int ghostx = 5;
int ghosty = 5;

int pacmanX = 3;
int pacmanY = 5;

int randomGhostx = 2;
int randomGhosty = 2;
char randomPrevious = ' ';

string ghostDirection = "Right";
char horizontalPrevious = ' ';

int score = 0;

// Function Prototypes
void gotoxy(short x, short y);
char getCharAtxy(short int x, short int y);
void movePacmanLeft();
void movePacmanRight();
void movePacmanUp();
void movePacmanDown();
void moveGhostHorizontal();
void moveGhostRandom();
void printMaze();
void addScore();
void printScore();
bool stopGameIfCollision();
void pacmanCollisionFoodPallet();

// Function Definitions
int main()
{
    system("cls");
    bool gameRunning = true;

    printMaze();

    gotoxy(pacmanX, pacmanY);
    cout << "P";
    while (gameRunning)
    {
        printScore();
        gameRunning = stopGameIfCollision();

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
        moveGhostRandom();
        Sleep(100);
    }
}

// Player Movement

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
        if (next == '.')
        {
            addScore();
        }
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
        if (next == '.')
        {
            addScore();
        }
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
        if (next == '.')
        {
            addScore();
        }
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
        if (next == '.')
        {
            addScore();
        }
    }
}

// Ememy Movement
void moveGhostHorizontal()
{

    if (ghostDirection == "Left")
    {
        char next = getCharAtxy(ghostx - 1, ghosty);
        if (next == ' ' || next == '.')
        {
            gotoxy(ghostx, ghosty);
            cout << horizontalPrevious;
            horizontalPrevious = next;
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
            cout << horizontalPrevious;
            horizontalPrevious = next;
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

void moveGhostRandom()
{
    int randomValue = rand() % 4;
    if(randomValue == 0)        // 0 for moving Left
    {
        char next = getCharAtxy(randomGhostx - 1, randomGhosty);
        if (next == ' ' || next == '.')
        {
            gotoxy(randomGhostx, randomGhosty);
            cout << randomPrevious;
            randomPrevious = next;
            randomGhostx = randomGhostx - 1;
            gotoxy(randomGhostx, randomGhosty);
            cout << "R";
        }
    }
    if(randomValue == 1)        // 1 for moving Right
    {
        char next = getCharAtxy(randomGhostx + 1, randomGhosty);
        if (next == ' ' || next == '.')
        {
            gotoxy(randomGhostx, randomGhosty);
            cout << randomPrevious;
            randomPrevious = next;
            randomGhostx = randomGhostx + 1;
            gotoxy(randomGhostx, randomGhosty);
            cout << "R";
        }
    }
    if(randomValue == 2)        // 2 for moving Up
    {
        char next = getCharAtxy(randomGhostx, randomGhosty - 1);
        if (next == ' ' || next == '.')
        {
            gotoxy(randomGhostx, randomGhosty);
            cout << randomPrevious;
            randomPrevious = next;
            randomGhosty = randomGhosty - 1;
            gotoxy(randomGhostx, randomGhosty);
            cout << "R";
        }
    }
    if(randomValue == 3)        // 2 for moving Down
    {
        char next = getCharAtxy(randomGhostx, randomGhosty + 1);
        if (next == ' ' || next == '.')
        {
            gotoxy(randomGhostx, randomGhosty);
            cout << randomPrevious;
            randomPrevious = next;
            randomGhosty = randomGhosty + 1;
            gotoxy(randomGhostx, randomGhosty);
            cout << "R";
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
void printScore()
{
    gotoxy(30, 5);
    cout << "Score: " << score;
}

// Reward and Punishments
void addScore()
{
    score++;
}

// Collision Detection
bool stopGameIfCollision()
{
    char next;
    next = getCharAtxy(pacmanX + 1, pacmanY);
    if (next == 'G' || next == 'R')
    {
        return false;
    }
    next = getCharAtxy(pacmanX - 1, pacmanY);
    if (next == 'G' || next == 'R')
    {
        return false;
    }
    next = getCharAtxy(pacmanX, pacmanY + 1);
    if (next == 'G' || next == 'R')
    {
        return false;
    }
    next = getCharAtxy(pacmanX, pacmanY + 1);
    if (next == 'G' || next == 'R')
    {
        return false;
    }
    return true;
}
