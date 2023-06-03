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
    void getPiece(std::pair<int, int> position);
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
    for (int i = 0; i < 8; i++)
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
        board[i][1] = new Pawn(0, std::make_pair(i, 1));
    }

    // Rooks
    board[0][0] = new Rook(0, std::make_pair(0, 0));
    board[7][0] = new Rook(0, std::make_pair(7, 0));

    // Knights
    board[1][0] = new Knight(0, std::make_pair(1, 0));
    board[6][0] = new Knight(0, std::make_pair(6, 0));

    // Bishops
    board[2][0] = new Bishop(0, std::make_pair(2, 0));
    board[5][0] = new Bishop(0, std::make_pair(5, 0));

    // Queen
    board[3][0] = new Queen(0, std::make_pair(3, 0));

    // King
    board[4][0] = new King(0, std::make_pair(4, 0));

    // Initialize the black pieces

    // Pawns

    for (int i = 0; i < 8; i++)
    {
        board[i][6] = new Pawn(1, std::make_pair(i, 6));
    }

    // Rooks

    board[0][7] = new Rook(1, std::make_pair(0, 7));
    board[7][7] = new Rook(1, std::make_pair(7, 7));

    // Knights
    board[1][7] = new Knight(1, std::make_pair(1, 7));
    board[6][7] = new Knight(1, std::make_pair(6, 7));

    // Bishops
    board[2][7] = new Bishop(1, std::make_pair(2, 7));
    board[5][7] = new Bishop(1, std::make_pair(5, 7));

    // Queen
    board[3][7] = new Queen(1, std::make_pair(3, 7));

    // King
    board[4][7] = new King(1, std::make_pair(4, 7));
}

/**
 * @brief Print the board
 * 
 */

void Board::printBoard()
{

    // Print the board for the white player
    if (turn == 0)
    {
        std::cout << "  -----------------------------------------" << std::endl;

        for (int i = 7; i >= 0; i--)
        {
            std::cout << i << " | ";

            for (int j = 0; j < 8; j++)
            {
                if (board[j][i]->getSymbol() == " ")
                {
                    std::cout << "  " << " | ";
                }

                else
                {
                    if (board[j][i]->getColor() == 0)
                    {
                        std::cout << board[j][i]->getSymbol() << "w" << " | ";
                    }

                    else
                    {
                        std::cout << board[j][i]->getSymbol() << "b" << " | ";
                    }
                }
            }

            std::cout << std::endl;
            std::cout << "  -----------------------------------------" << std::endl;
        }

        std::cout << "    0    1    2    3    4    5    6    7" << std::endl;
    }

    // Print the board for the black player
    else
    {
        {
        std::cout << "  -----------------------------------------" << std::endl;

        for (int i = 0; i < 8; i++)
        {
            std::cout << i << " | ";

            for (int j = 7; j >= 0; j--)
            {
                if (board[j][i]->getSymbol() == " ")
                {
                    std::cout << "  " << " | ";
                }

                else
                {
                    if (board[j][i]->getColor() == 0)
                    {
                        std::cout << board[j][i]->getSymbol() << "w" << " | ";
                    }

                    else
                    {
                        std::cout << board[j][i]->getSymbol() << "b" << " | ";
                    }
                }
            }

            std::cout << std::endl;
            std::cout << "  -----------------------------------------" << std::endl;
        }

        std::cout << "    7    6    5    4    3    2    1    0" << std::endl;
    }
    }
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
            board[j][i]->showPieceInfo();
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
    int xInitial = initialPosition.first;
    int yInitial = initialPosition.second;

    // Get row and column of the final position

    int xFinal = finalPosition.first;
    int yFinal = finalPosition.second;

    // Check if the initial position is valid

    if (xInitial < 0 || xInitial > 7 || yInitial < 0 || yInitial > 7)
    {
        std::cout << "Invalid initial position" << std::endl;
        return false;
    }

    // Check if the final position is valid

    if (xFinal < 0 || xFinal > 7 || yFinal < 0 || yFinal > 7)
    {
        std::cout << "Invalid final position" << std::endl;
        return false;
    }

    // Check if the initial position is empty

    if (board[xInitial][yInitial]->getSymbol() == " ")
    {
        std::cout << "Initial position is empty" << std::endl;
        return false;
    }

    // Check if the final position is empty

    if (board[xFinal][yFinal]->getSymbol() != " ")
    {
        std::cout << "Final position is not empty" << std::endl;
        return false;
    }

    // Check if the piece belongs to the player
    if (board[xInitial][yInitial]->getColor() != turn)
    {
        std::cout << "Piece does not belong to the player" << std::endl;
        return false;
    }

    // Check if the piece can move to the final position

    if (!board[xInitial][yInitial]->isValidMove(finalPosition))
    {
        std::cout << "Invalid move" << std::endl;
        return false;
    }

    // Update the position of the piece
    board[xInitial][yInitial]->setPosition(finalPosition);

    // Update the board
    board[xFinal][yFinal] = board[xInitial][yInitial];
    board[xInitial][yInitial] = new Piece();

    // Update the turn
    turn = (turn + 1) % 2;

    return true;

}

/**
 * @brief Get the piece in the given position
 * 
 * @param position 
 */

void Board::getPiece(std::pair<int, int> position)
{
    // Get row and column of the position

    int row = position.first;
    int column = position.second;

    // Check if the position is valid

    if (row < 0 || row > 7 || column < 0 || column > 7)
    {
        std::cout << "Invalid position" << std::endl;
        return;
    }

    // Check if the position is empty

    if (board[row][column]->getSymbol() == " ")
    {
        std::cout << "Position is empty" << std::endl;
        return;
    }

    // Show the information of the piece

    board[row][column]->showPieceInfo();
}


#endif