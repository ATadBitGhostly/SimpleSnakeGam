#include <iostream>


// Game Behaviour
bool gameOver;

// Window/Game size
const int height = 20;
const int width = 20;

// Player
int playerX, playerY, score;
enum eDIRECTION { UP, DOWN, LEFT, RIGHT, STOP = 0 };
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
        std::cout << "#";
    }
    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                std::cout << "#";
            } else {
                std::cout << " ";
            }
            if (j == width - 1) {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < height; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;

}

void Input() {

}

void Logic() {

}

int main() {

    Draw();
    Input();
    Logic();

}