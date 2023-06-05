/**
 * @file Queen.cpp
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Implementation of the Queen class
 * @version 0.1
 * @date 2023-06-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef QUEEN_CPP
#define QUEEN_CPP

#include <iostream>
#include <utility>
#include <string>

#include "../headers/Queen.h" // Header file
#include "Board.cpp"          // Board class

// Constructor

/**
 * @brief Construct a new Queen:: Queen object
 *
 */

Queen::Queen() : Piece() {}

/**
 * @brief Construct a new Queen:: Queen object
 *
 * @param color
 * @param position
 */

Queen::Queen(int color, std::pair<int, int> position) : Piece(color, position) {}

// Getters

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string Queen::getName() { return name; }

/**
 * @brief Get the Color object
 *
 * @return int
 */

int Queen::getColor() { return color; }

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string Queen::getSymbol() { return symbol; }

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> Queen::getPosition() { return position; }

/**
 * @brief Get the Has Moved object
 *
 * @return true
 * @return false
 */

bool Queen::getHasMoved() { return hasMoved; };

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void Queen::setPosition(std::pair<int, int> position) { this->position = position; }

// Methods

/**
 * @brief Checks if the move is valid
 *
 * @param positionToMove
 * @return true
 * @return false
 */

bool Queen::isValidMove(std::pair<int, int> positionToMove, Board &board)
{
    // Get row and column of the position
    int xInitial = position.first;
    int yInitial = position.second;

    // Get row and column of the position to move
    int xFinal = positionToMove.first;
    int yFinal = positionToMove.second;

    // Get difference between initial and final position
    int xDifference = xFinal - xInitial;
    int yDifference = yFinal - yInitial;

    // Check if the move is not to the same position
    if (xDifference == 0 && yDifference == 0)
    {
        return false;
    }

    // Check if the move is not diagonal, horizontal or vertical
    if (abs(xDifference) != abs(yDifference) && xDifference != 0 && yDifference != 0)
    {
        return false;
    }

    // Check if there are pieces in the way

    // If the move is diagonal
    if (abs(xDifference) == abs(yDifference))
    {
        // If the move is to the top right
        if (xDifference > 0 && yDifference > 0)
        {
            // Check if there are pieces in the way
            for (int i = 1; i < xDifference; i++)
            {
                if (board.getPiece(std::make_pair(xInitial + i, yInitial + i)) != nullptr)
                {
                    return false;
                }
            }
        }

        // If the move is to the top left
        if (xDifference > 0 && yDifference < 0)
        {
            // Check if there are pieces in the way
            for (int i = 1; i < xDifference; i++)
            {
                if (board.getPiece(std::make_pair(xInitial + i, yInitial - i)) != nullptr)
                {
                    return false;
                }
            }
        }

        // If the move is to the bottom right
        if (xDifference < 0 && yDifference > 0)
        {
            // Check if there are pieces in the way
            for (int i = 1; i < abs(xDifference); i++)
            {
                if (board.getPiece(std::make_pair(xInitial - i, yInitial + i)) != nullptr)
                {
                    return false;
                }
            }
        }

        // If the move is to the bottom left
        if (xDifference < 0 && yDifference < 0)
        {
            // Check if there are pieces in the way
            for (int i = 1; i < abs(xDifference); i++)
            {
                if (board.getPiece(std::make_pair(xInitial - i, yInitial - i)) != nullptr)
                {
                    return false;
                }
            }
        }
    }

    // Capture piece if there is one
    if (board.getPiece(positionToMove) != nullptr && board.getPiece(positionToMove)->getColor() != color && board.getPiece(positionToMove)->getName() != "King")
    {
        board.capturePiece(positionToMove);
    }

    // If the move is diagonal, horizontal or vertical, and there are no pieces in the way, the move is valid
    return true;
}

#endif