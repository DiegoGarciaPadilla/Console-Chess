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

#include "headers\Piece.h" // Parent class
#include "headers\Pawn.h" // Pawn subclass
#include "headers\Rook.h" // Rook subclass
#include "headers\Knight.h" // Knight subclass
#include "headers\Bishop.h" // Bishop subclass
#include "headers\Queen.h" // Queen subclass
#include "headers\King.h" // King subclass
#include "headers\Board.h" // Board class

int main()
{
    // Create board
    Board board;

    // Initialize board
    board.initializeBoard();

    // Initialize variables
    int initialX, initialY, finalX, finalY;

    // Move pieces

    for (int i = 0; i < 10; i++)
    {
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

        std::pair <int, int> initialPosition = std::make_pair(initialX, initialY);
        std::pair <int, int> finalPosition = std::make_pair(finalX, finalY);

        // Move piece
        board.movePiece(initialPosition, finalPosition);
    }

    // Print board
    board.printBoard();

    // Pause
    system("pause");

    // Destroy board
    board.~Board();

    return 0;
}