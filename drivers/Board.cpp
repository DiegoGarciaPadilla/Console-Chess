/**
 * @file Board.c++
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Implementation of the Board class
 * @version 0.1
 * @date 2023-06-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BOARD_CPP
#define BOARD_CPP

#include <iostream>
#include <vector>
#include <utility>
#include <string>

#include "../headers/Board.h" // Header file
#include "Bishop.cpp"         // Bishop class
#include "King.cpp"           // King class
#include "Knight.cpp"         // Knight class
#include "Pawn.cpp"           // Pawn class
#include "Queen.cpp"          // Queen class
#include "Rook.cpp"           // Rook class

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
            board[i][j] = nullptr;
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
            board[i][j] = nullptr;
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
    // Print turn
    if (turn == 0)
    {
        std::cout << "White's turn" << std::endl;
    }
    else
    {
        std::cout << "Black's turn" << std::endl;
    }

    // Print a message if the king is in check
    if (isCheck())
    {
        std::cout << "Your King is in check!" << std::endl;
    }
    std::cout << std::endl;

    // Print the board for the white player
    if (turn == 0)
    {
        std::cout << "  -----------------------------------------" << std::endl;

        for (int i = 7; i >= 0; i--)
        {
            std::cout << i << " | ";

            for (int j = 0; j < 8; j++)
            {
                if (board[j][i] == nullptr)
                {
                    std::cout << "  "
                              << " | ";
                }

                else
                {
                    if (board[j][i]->getColor() == 0)
                    {
                        std::cout << board[j][i]->getSymbol() << "w"
                                  << " | ";
                    }

                    else
                    {
                        std::cout << board[j][i]->getSymbol() << "b"
                                  << " | ";
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
                    if (board[j][i] == nullptr)
                    {
                        std::cout << "  "
                                  << " | ";
                    }

                    else
                    {
                        if (board[j][i]->getColor() == 0)
                        {
                            std::cout << board[j][i]->getSymbol() << "w"
                                      << " | ";
                        }

                        else
                        {
                            std::cout << board[j][i]->getSymbol() << "b"
                                      << " | ";
                        }
                    }
                }

                std::cout << std::endl;
                std::cout << "  -----------------------------------------" << std::endl;
            }

            std::cout << "    7    6    5    4    3    2    1    0" << std::endl;
        }
    }
    std::cout << std::endl;

    // Print captured pieces

    std::cout << "Captured pieces : " << std::endl;

    std::cout << "White: ";
    for (int i = 0; i < whiteCapturedPieces.size(); i++)
    {
        std::cout << whiteCapturedPieces[i]->getSymbol() << " ";
    }
    std::cout << std::endl;

    std::cout << "Black: ";
    for (int i = 0; i < blackCapturedPieces.size(); i++)
    {
        std::cout << blackCapturedPieces[i]->getSymbol() << " ";
    }
    std::cout << std::endl;
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

    if (board[xInitial][yInitial] == nullptr)
    {
        std::cout << "Initial position is empty" << std::endl;
        return false;
    }

    // Check if the final position is empty or has an enemy piece

    if (board[xFinal][yFinal] != nullptr && board[xFinal][yFinal]->getColor() == turn)
    {
        std::cout << "You cannot capture your own piece" << std::endl;
        return false;
    }

    // Check if the piece belongs to the player

    if (board[xInitial][yInitial]->getColor() != turn)
    {
        std::cout << "Piece does not belong to the player" << std::endl;
        return false;
    }

    // Check if the piece moves to a different position

    if (xInitial == xFinal && yInitial == yFinal)
    {
        std::cout << "Piece does not move" << std::endl;
        return false;
    }

    // Check if the piece can move to the final position

    if (!board[xInitial][yInitial]->isValidMove(finalPosition, *this))
    {
        std::cout << "Invalid move" << std::endl;
        return false;
    }

    // Check if there is a king in the final position
    if (board[xFinal][yFinal] != nullptr && board[xFinal][yFinal]->getName() == "K")
    {
        std::cout << "The king cannot be captured" << std::endl;
        return false;
    }

    // Update the position of the piece

    board[xInitial][yInitial]->setPosition(finalPosition);

    // Update the board

    board[xFinal][yFinal] = board[xInitial][yInitial];
    board[xInitial][yInitial] = nullptr;

    // Update the turn

    turn = (turn + 1) % 2;

    return true;
}

/**
 * @brief Capture a piece
 *
 * @param position
 * @return true
 * @return false
 */

bool Board::capturePiece(std::pair<int, int> position)
{
    // Get row and column of the position
    int x = position.first;
    int y = position.second;

    // We assume that the position is valid and that there is a piece in the position

    // Add the piece to the captured pieces
    if (turn == 0)
    {
        whiteCapturedPieces.push_back(board[x][y]);
    }

    else
    {
        blackCapturedPieces.push_back(board[x][y]);
    }

    return true;
}

/**
 * @brief Get the position of the king
 * 
 * @param color
 * @return std::pair<int, int> 
 */

std::pair<int, int> Board::getKingPosition(int color)
{
    // Initialize the position of the king
    std::pair<int, int> kingPosition;

    // Get the position of the king
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != nullptr && board[i][j]->getColor() == color && board[i][j]->getName() == "King")
            {
                kingPosition = board[i][j]->getPosition();
            }
        }
    }

    // Return the position of the king
    return kingPosition;
}

/**
 * @brief Check if the position is in attack by the enemy
 * 
 * @param position
 */

bool Board::isAttacked(std::pair<int, int> position)
{

    // Check if the position is attacked
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != nullptr && board[i][j]->getColor() != turn && board[i][j]->isValidMove(position, *this))
            {
                return true;
            }
        }
    }

    // Else, the position is not attacked
    return false;
}

/**
 * @brief Check if the king of the current player is in check
 *
 * @return true
 * @return false
 */

bool Board::isCheck()
{
    // Initialize the position of the king
    std::pair<int, int> kingPosition;

    // Get the position of the king
    kingPosition = getKingPosition(turn);

    // Check if the king is in check
    return isAttacked(kingPosition);

    // Else, the king is not in check
    return false;
}

/**
 * @brief Get the piece in the given position
 *
 * @param position
 * @return Piece
 */

Piece *Board::getPiece(std::pair<int, int> position)
{
    // Get row and column of the position
    int x = position.first;
    int y = position.second;

    // Check if the position is valid
    if (x < 0 || x > 7 || y < 0 || y > 7)
    {
        std::cout << "Invalid position" << std::endl;
        return nullptr;
    }

    // Return the piece in the position
    return board[x][y];
}

#endif