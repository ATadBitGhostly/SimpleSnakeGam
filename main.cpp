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
int playerX, playerY, score; // Player head coords and score initialization
int tailX[100], tailY[100];
int nTail; // checks collision?
enum eDIRECTION { STOP = 0, UP, DOWN, LEFT, RIGHT}; // directions
eDIRECTION dir; // keeps tabs on direction

// Fruit
int fruitX, fruitY; // Fruit coords initialization

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
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print) cout << " ";
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

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = playerX;
    tailY[0] = playerY;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
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
    // if (playerX > width || playerY > height || playerX < 0 || playerY < 0) {
    //     gameOver = true;
    // }
    if (playerX >= width) playerX = 0; else if (playerX < 0) playerX = width - 1;
    if (playerY >= height) playerY = 0; else if (playerY < 0) playerY = height - 1;
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == playerX && tailY[i] == playerY) {
            gameOver = true;
        }
    }
    if (playerX == fruitX && playerY == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
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