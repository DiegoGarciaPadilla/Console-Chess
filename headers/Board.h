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
    std::vector<std::vector<Piece>> board;
    int turn;   // 0 = white, 1 = black
public:
    // Constructor
    Board();
    Board(std::vector<std::vector<Piece>> board, int turn);

    // Getters
    std::vector<std::vector<Piece>> getBoard();
    int getTurn();

    // Setters
    void setBoard(std::vector<std::vector<Piece>> board);
    void setTurn(int turn);

    // Methods
    void initializeBoard();
    void printBoard();
    bool movePiece(std::string command);
};

// Constructor

/**
 * @brief Construct a new Board:: Board object
 * 
 */

Board::Board()
{
    board = std::vector<std::vector<Piece>>(8, std::vector<Piece>(8));
    turn = 0;
}

/**
 * @brief Construct a new Board:: Board object
 * 
 * @param board 
 * @param turn 
 */

Board::Board(std::vector<std::vector<Piece>> board, int turn)
{
    this->board = board;
    this->turn = turn;
}

// Getters

/**
 * @brief Get the Board object
 * 
 * @return std::vector<std::vector<Piece>> 
 */

std::vector<std::vector<Piece>> Board::getBoard()
{
    return board;
}

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
 * @brief Set the Board object
 * 
 * @param board 
 */

void Board::setBoard(std::vector<std::vector<Piece>> board)
{
    this->board = board;
}

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
 * @brief Initializes the board with the pieces in their initial positions
 * 
 */

void Board::initializeBoard()
{
    // Initialize the board with empty spaces
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = Piece();
        }
    }


    // White pieces
    
    // Pawns
    for (int i = 0; i < 8; i++)
    {
        board[1][i] = Pawn(0, std::make_pair(1, i));
    }

    // Rooks
    board[0][0] = Rook(0, std::make_pair(0, 0));
    board[0][7] = Rook(0, std::make_pair(0, 7));

    // Knights
    board[0][1] = Knight(0, std::make_pair(0, 1));
    board[0][6] = Knight(0, std::make_pair(0, 6));

    // Bishops
    board[0][2] = Bishop(0, std::make_pair(0, 2));
    board[0][5] = Bishop(0, std::make_pair(0, 5));

    // Queen
    board[0][3] = Queen(0, std::make_pair(0, 3));

    // King
    board[0][4] = King(0, std::make_pair(0, 4));

    // Black pieces

    // Pawns
    for (int i = 0; i < 8; i++)
    {
        board[6][i] = Pawn(1, std::make_pair(6, i));
    }

    // Rooks
    board[7][0] = Rook(1, std::make_pair(7, 0));
    board[7][7] = Rook(1, std::make_pair(7, 7));

    // Knights
    board[7][1] = Knight(1, std::make_pair(7, 1));
    board[7][6] = Knight(1, std::make_pair(7, 6));

    // Bishops
    board[7][2] = Bishop(1, std::make_pair(7, 2));
    board[7][5] = Bishop(1, std::make_pair(7, 5));

    // Queen
    board[7][3] = Queen(1, std::make_pair(7, 3));

    // King
    board[7][4] = King(1, std::make_pair(7, 4));
}

/**
 * @brief Prints the board
 * 
 */

void Board::printBoard()
{
    std::cout << "  ";
    for (int i = 0; i < 8; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << i << " ";
        for (int j = 0; j < 8; j++)
        {
            std::cout << board[i][j].getSymbol() << " ";
        }
        std::cout << std::endl;
    }
}

#endif