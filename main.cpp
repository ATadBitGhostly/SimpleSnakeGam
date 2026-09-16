#include <iostream>
// #include <conio.h>
// #include <windows.h>
// using namespace std;

#include <raylib.h>

int main() {

    InitWindow(600, 400, "SNAKE GAME");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

// all right ill just write some comments and commit cuz i got no idea

//
// // Game Behaviour
// bool gameOver;
//
// // Window/Game size
// const int height = 20;
// const int width = 20;
//
// // Player
// int playerX, playerY, score; // Player head coords and score initialization
// int tailX[100], tailY[100];
// int nTail; // checks collision?
// enum eDIRECTION { STOP = 0, UP, DOWN, LEFT, RIGHT}; // directions or states
// eDIRECTION dir; // keeps tabs on direction
//
// // Fruit
// int fruitX, fruitY; // Fruit coords initialization
//
// // First thing that happens when program starts
// void Setup() {
//
//     gameOver = false; // Sets that the game is not over, who could have guessed
//     dir = STOP; // For eDirection enum "dir" array to know what state it should be in.
//     playerX = width / 2; // Basically sets the players X coord to be in the middle
//     playerY = height / 2; // Same here but on the Y coord
//     fruitX = rand() % width; // Sets the fruit X coord location by getting a random number dividing it by width and getting the remainder
//     fruitY = rand() % height; // Same here except for the fruits Y coord and height
//
// }
//
// // Function that draws the game like, borders/portals, player, etc.
// void Draw() {
//
//     system("cls"); // system clear in the console window
//     // a for loop for top wall/portal
//     for (int i = 0; i < width; i++) {
//         cout << "-";
//     }
//     cout << endl;
//
//     // a big for loop for side walls, and player and fruit location
//     for (int i = 0; i < height; i++) {
//         for (int j = 0; j < width; j++) {
//             if (j == 0) {
//                 cout << "(";
//             }
//             // Ifs that check if the player coords or fruit coords match the iteration and renders the player or fruit
//             if (i == playerY && j == playerX) {
//                 cout << "0";
//             } else if (i == fruitY && j == fruitX) {
//                 cout << "F";
//             } else { // an else option which renders the tail of the player when it increases
//                 bool print = false;
//                 for (int k = 0; k < nTail; k++) {
//                     if (tailX[k] == j && tailY[k] == i) {
//                         cout << "o";
//                         print = true;
//                     }
//                 }
//                 if (!print) cout << " "; // if the print is false it just doesnt print out the tail
//             }
//
//             if (j == width - 1) {
//                 cout << ")";
//             }
//         }
//         cout << endl;
//     }
//     // for loop for the bottom wall/portal
//     for (int i = 0; i < height; i++) {
//         cout << "-";
//     }
//     cout << endl;
//
// }
//
// // Function that Checks the inputs entered
// void Input() {
//
//     // an if that checks if the keyboard has been... touched
//     if (_kbhit()) {
//         switch (_getch()) { // gets the key
//             case 'a': // if it is the 'a' key then dir becomes Left
//                 dir = LEFT;
//                 break;
//             case 'd': // if it is the 'd' key then dir becomes Right
//                 dir = RIGHT;
//                 break;
//             case 'w': // if it is the 'w' key then dir becomes Up
//                 dir = UP;
//                 break;
//             case 's': // if it is the 's' key then dir becomes Down
//                 dir = DOWN;
//                 break;
//             case 'x': // if the 'x' key is pressed the gameOver state turns true and ends the program.
//                 gameOver = true;
//                 break;
//         }
//     }
//
// }
//
// // Function that does all the logic
// void Logic() {
//
//     // Declares prevX and prevY and saves the tails previous positions, also declares prev2X and prev2Y
//     int prevX = tailX[0];
//     int prevY = tailY[0];
//     int prev2X, prev2Y;
//
//     // sets the tails starting position on players X and Y coords
//     tailX[0] = playerX;
//     tailY[0] = playerY;
//     // A for loop that goes through each tail the player has and moves them to previous segments
//     for (int i = 1; i < nTail; i++) {
//         // Saves the current tail segments position before overwriting it.
//         prev2X = tailX[i];
//         prev2Y = tailY[i];
//         // Saves the current tail segment on the previous x and y coords
//         tailX[i] = prevX;
//         tailY[i] = prevY;
//         // saves the previous x and y to be the 2x previous ones.
//         prevX = prev2X;
//         prevY = prev2Y;
//     }
//     // This is basically the same thing in input, but just changes the values of the player
//     switch (dir) {
//         case LEFT:
//             playerX--;
//             break;
//         case RIGHT:
//             playerX++;
//             break;
//         case UP:
//             playerY--;
//             break;
//         case DOWN:
//             playerY++;
//             break;
//         default:
//             break;
//     }
//     // This if is just to enable wall collision logic
//     // if (playerX > width || playerY > height || playerX < 0 || playerY < 0) {
//     //     gameOver = true;
//     // }
//     // These 2 ifs just make the walls become portals to the other side.
//     if (playerX >= width) playerX = 0; else if (playerX < 0) playerX = width - 1;
//     if (playerY >= height) playerY = 0; else if (playerY < 0) playerY = height - 1;
//     // for loop checks if the player head collides with the body/tails
//     for (int i = 0; i < nTail; i++) {
//         if (tailX[i] == playerX && tailY[i] == playerY) {
//             gameOver = true;
//         }
//     }
//     // logic for tail and score increase when player touches the fruits
//     if (playerX == fruitX && playerY == fruitY) {
//         score += 10;
//         fruitX = rand() % width;
//         fruitY = rand() % height;
//         nTail++;
//     }
// }
//
// // Main function which initializes the other functions
// int main() {
//     // Sets up all the necessary variables before game starts
//     Setup();
//     // A while loop that keeps looping till gameOver becomes true
//     while (gameOver == false) {
//         // calls out Draw(), Input() and Logic() functions
//         Draw();
//         Input();
//         Logic();
//         Sleep(50); // a wait function per se, that allows for more time for players
//         // 2 outputs for player coordinates.
//         // cout << playerX << endl;
//         // cout << playerY << endl;
//         cout << "Score: " << score << endl; // Score display
//     }
//
// }