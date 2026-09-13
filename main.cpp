#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Game Behaviour
bool gameOver;

// Window/Game size
const int height = 20;
const int width = 20;

// Player
int playerX, playerY, score;
enum eDIRECTION { STOP = 0, UP, DOWN, LEFT, RIGHT};
eDIRECTION dir;

// Fruit
int fruitX, fruitY;

void Setup() {

    gameOver = false;
    dir = STOP;
    playerX = width / 2;
    playerY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;

}

void Draw() {

    system("cls"); // system clear in the console window
    for (int i = 0; i < width; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#";
            }

            if (i == playerY && j == playerX) {
                cout << "0";
            } else if (i == fruitY && j == fruitX) {
                cout << "F";
            } else {
                cout << " ";
            }

            if (j == width - 1) {
                cout << "#";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < height; i++) {
        cout << "#";
    }
    cout << endl;

}

void Input() {

    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }

}

void Logic() {

    switch (dir) {
        case LEFT:
            playerX--;
            break;
        case RIGHT:
            playerX++;
            break;
        case UP:
            playerY--;
            break;
        case DOWN:
            playerY++;
            break;
        default:
            break;
    }
    if (playerX > width || playerY > height || playerX < 0 || playerY < 0) {
        gameOver = true;
    }
    if (playerX == fruitX && playerY == fruitY) {
        score += 10;
    }
}


int main() {
    Setup();
    while (gameOver == false) {
        Draw();
        Input();
        Logic();
        Sleep(50);
        // cout << playerX << endl;
        // cout << playerY << endl;
        cout << "Score: " << score << endl;
    }

}