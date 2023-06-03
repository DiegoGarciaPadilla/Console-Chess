/**
 * @file Board.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Board class
 * @version 0.1
 * @date 2023-05-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>

#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Board
{
private:
    // Attributes
    Piece* board[8][8];
    int turn = 0;   // 0 = white, 1 = black
public:
    // Constructor
    Board();

    // Destructor
    ~Board();

    // Getters
    int getTurn();

    // Setters
    void setTurn(int turn);

    // Methods
    void initializeBoard();
    void printBoard();
    void boardInfo();

    bool movePiece(std::pair<int, int> initialPosition, std::pair<int, int> finalPosition);
};

// Constructor

/**
 * @brief Construct a new Board:: Board object
 * 
 */

Board::Board()
{
    // Initialize the board with empty spaces
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = new Piece();
        }
    }

    // Set the turn to white
    turn = 0;
}

// Destructor

/**
 * @brief Destroy the Board:: Board object
 * 
 */

Board::~Board()
{
    // Delete the pieces
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            delete board[i][j];
        }
    }
}

// Getters

/**
 * @brief Get the Turn object
 * 
 * @return int 
 */

int Board::getTurn()
{
    return turn;
}

// Setters

/**
 * @brief Set the Turn object
 * 
 * @param turn 
 */

void Board::setTurn(int turn)
{
    this->turn = turn;
}

// Methods

/**
 * @brief Initialize the board with the pieces in their initial positions
 * 
 */

void Board::initializeBoard()
{
    // Initialize the board with empty spaces
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = new Piece();
        }
    }

    // Initialize the white pieces

    // Pawns
    for (int i = 0; i < 8; i++)
    {
        board[1][i] = new Pawn(0, std::make_pair(1, i));
    }

    // Rooks
    board[0][0] = new Rook(0, std::make_pair(0, 0));
    board[0][7] = new Rook(0, std::make_pair(0, 7));

    // Knights
    board[0][1] = new Knight(0, std::make_pair(0, 1));
    board[0][6] = new Knight(0, std::make_pair(0, 6));

    // Bishops
    board[0][2] = new Bishop(0, std::make_pair(0, 2));
    board[0][5] = new Bishop(0, std::make_pair(0, 5));

    // Queen
    board[0][3] = new Queen(0, std::make_pair(0, 3));

    // King
    board[0][4] = new King(0, std::make_pair(0, 4));

    // Initialize the black pieces

    // Pawns

    for (int i = 0; i < 8; i++)
    {
        board[6][i] = new Pawn(1, std::make_pair(6, i));
    }

    // Rooks

    board[7][0] = new Rook(1, std::make_pair(7, 0));
    board[7][7] = new Rook(1, std::make_pair(7, 7));

    // Knights

    board[7][1] = new Knight(1, std::make_pair(7, 1));
    board[7][6] = new Knight(1, std::make_pair(7, 6));

    // Bishops
    board[7][2] = new Bishop(1, std::make_pair(7, 2));
    board[7][5] = new Bishop(1, std::make_pair(7, 5));

    // Queen
    board[7][3] = new Queen(1, std::make_pair(7, 3));

    // King
    board[7][4] = new King(1, std::make_pair(7, 4));
}

/**
 * @brief Print the board
 * 
 */

void Board::printBoard()
{

    // Print the column numbers and the board

    for (int i = 0; i < 8; i++)
    {
        std::cout << i << " ";

        for (int j = 0; j < 8; j++)
        {
            std::cout << board[i][j]->getSymbol() << " ";
        }

        std::cout << std::endl;
    }

    std::cout << "  0 1 2 3 4 5 6 7" << std::endl;
}

/**
 * @brief Print the board with the information of the pieces
 * 
 */

void Board::boardInfo()
{
    for (int i = 0; i < 8; i++)
    {
        std::cout << "Row: " << i << std::endl;
        std::cout << std::endl;

        for (int j = 0; j < 8; j++)
        {
            std::cout << "Position: " << "(" << i << ", " << j << ")" << std::endl;
            board[i][j]->showPieceInfo();
            std::cout << std::endl;
        }
        
        std::cout << std::endl;
    }
}

/**
 * @brief Move a piece from an initial position to a final position
 * 
 * @param initialPosition 
 * @param finalPosition 
 * @return true 
 * @return false 
 */

bool Board::movePiece(std::pair<int, int> initialPosition, std::pair<int, int> finalPosition)
{
    // Get row and column of the initial position
    int iRow = initialPosition.first;
    int iColumn = initialPosition.second;

    // Get row and column of the final position

    int fRow = finalPosition.first;
    int fColumn = finalPosition.second;

    // Check if the initial position is valid

    if (iRow < 0 || iRow > 7 || iColumn < 0 || iColumn > 7)
    {
        std::cout << "Invalid initial position" << std::endl;
        return false;
    }

    // Check if the final position is valid

    if (fRow < 0 || fRow > 7 || fColumn < 0 || fColumn > 7)
    {
        std::cout << "Invalid final position" << std::endl;
        return false;
    }

    // Check if the initial position is empty

    if (board[iRow][iColumn]->getSymbol() == " ")
    {
        std::cout << "Initial position is empty" << std::endl;
        return false;
    }

    // Check if the final position is empty

    if (board[fRow][fColumn]->getSymbol() != " ")
    {
        std::cout << "Final position is not empty" << std::endl;
        return false;
    }

    // Check if the movement is valid

    if (!board[iRow][iColumn]->isValidMove(finalPosition))
    {
        std::cout << "Invalid movement" << std::endl;
        return false;
    }

    // Update the position of the piece

    board[iRow][iColumn]->setPosition(finalPosition);

    // Update the board

    board[fRow][fColumn] = board[iRow][iColumn];
    board[iRow][iColumn] = new Piece();

    // Update the turn

    turn = (turn + 1) % 2;

    return true;

}

#endif