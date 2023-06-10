/**
 * @file main.cpp
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Main file for the chess game
 * @version 0.1
 * @date 2023-05-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "drivers/Game.cpp" // Game class


int main()
{
    // Create Game
    Game game;

    // Initialize variables
    int initialX, initialY, finalX, finalY;

    // Move pieces

    while (true)
    {
        // Print board
        game.printBoard();

        // Message
        std::cout << "Make a move!" << std::endl;

        // Get initial position
        std::cout << "Initial X position: ";
        std::cin >> initialX;

        std::cout << "Initial Y position: ";
        std::cin >> initialY;

        // Get final position
        std::cout << "Final X position: ";
        std::cin >> finalX;

        std::cout << "Final Y position: ";
        std::cin >> finalY;

        std::pair<int, int> initialPosition = std::make_pair(initialX, initialY);
        std::pair<int, int> finalPosition = std::make_pair(finalX, finalY);

        // Move piece
        if (!game.movePiece(initialPosition, finalPosition))
        {
            system("pause");
        }

        // Clean screen
        system("cls");
    }

    // Pause
    system("pause");

    return 0;
}