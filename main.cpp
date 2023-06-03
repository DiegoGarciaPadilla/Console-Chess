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

#include "drivers/Piece.cpp" // Parent class
#include "drivers/Board.cpp" // Board class


int main()
{
    // Create board
    Board board;

    // Initialize board
    board.initializeBoard();

    // Initialize variables
    int initialX, initialY, finalX, finalY;

    // Move pieces

    while (true)
    {
        // Print turn
        if (board.getTurn() == 0)
        {
            std::cout << "White's turn" << std::endl;
        }
        else
        {
            std::cout << "Black's turn" << std::endl;
        }

        // Print board
        board.printBoard();

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
        if (!board.movePiece(initialPosition, finalPosition))
        {
            system("pause");
        }

        // Clean screen
        system("cls");
    }

    // Print board
    board.printBoard();

    // Pause
    system("pause");

    // Destroy board
    board.~Board();

    return 0;
}