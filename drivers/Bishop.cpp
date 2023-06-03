/**
 * @file Bishop.cpp
 * @author Diego Antonio García Padilla
 * @brief
 * @version 0.1
 * @date 2023-06-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BISHOP_CPP
#define BISHOP_CPP

#include <iostream>
#include <utility>
#include <string>

#include "../headers/Bishop.h" // Header file
#include "Board.cpp"           // Board class

// Constructor

/**
 * @brief Construct a new Bishop:: Bishop object
 *
 */

Bishop::Bishop() : Piece() {}

/**
 * @brief Construct a new Bishop:: Bishop object
 *
 * @param color
 * @param position
 */

Bishop::Bishop(int color, std::pair<int, int> position) : Piece(color, position) {}

// Getters

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string Bishop::getName() { return name; };

/**
 * @brief Get the Color object
 *
 * @return int
 */

int Bishop::getColor() { return color; };

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string Bishop::getSymbol() { return symbol; };

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> Bishop::getPosition() { return position; };

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void Bishop::setPosition(std::pair<int, int> position) { this->position = position; };

// Methods

/**
 * @brief Checks if the move is valid
 *
 * @param positionToMove
 * @return true
 * @return false
 */

bool Bishop::isValidMove(std::pair<int, int> positionToMove, Board &board)
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

    // Check if the move is not diagonal
    if (abs(xDifference) != abs(yDifference))
    {
        return false;
    }

    // Check if there are pieces in the way

    // Check if the bishop is moving to the right and up
    if (xDifference > 0 && yDifference > 0)
    {
        for (int i = 1; i < xDifference; i++)
        {
            if (board.getPiece(std::make_pair(xInitial + i, yInitial + i)) != nullptr)
            {
                std::cout << "There is a piece in the way" << std::endl;
                return false;
            }
        }
    }

    // Check if the bishop is moving to the right and down
    else if (xDifference > 0 && yDifference < 0)
    {
        for (int i = 1; i < xDifference; i++)
        {
            if (board.getPiece(std::make_pair(xInitial + i, yInitial - i)) != nullptr)
            {
                std::cout << "There is a piece in the way" << std::endl;
                return false;
            }
        }
    }

    // Check if the bishop is moving to the left and up
    else if (xDifference < 0 && yDifference > 0)
    {
        for (int i = 1; i < abs(xDifference); i++)
        {
            if (board.getPiece(std::make_pair(xInitial - i, yInitial + i)) != nullptr)
            {
                std::cout << "There is a piece in the way" << std::endl;
                return false;
            }
        }
    }

    // Check if the bishop is moving to the left and down
    else if (xDifference < 0 && yDifference < 0)
    {
        for (int i = 1; i < abs(xDifference); i++)
        {
            if (board.getPiece(std::make_pair(xInitial - i, yInitial - i)) != nullptr)
            {
                std::cout << "There is a piece in the way" << std::endl;
                return false;
            }
        }
    }

    // Capture piece if there is one
    if (board.getPiece(positionToMove) != nullptr && board.getPiece(positionToMove)->getColor() != color)
    {
        board.capturePiece(positionToMove);
    }

    // If the bishop is moving diagonally and there are no pieces in the way, the move is valid
    return true;
}

#endif