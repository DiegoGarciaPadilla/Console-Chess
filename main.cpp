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

    // Print board info
    board.boardInfo();

    // Pause
    system("pause");

    // Delete board
    board.~Board();
}