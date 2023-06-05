/**
 * @file King.cpp
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Implementation of the King class
 * @version 0.1
 * @date 2023-06-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef KING_CPP
#define KING_CPP

#include <iostream>
#include <utility>
#include <string>

#include "../headers/King.h" // Header file
#include "Board.cpp"         // Board class

// Constructor

/**
 * @brief Construct a new King:: King object
 *
 */

King::King() : Piece() {}

/**
 * @brief Construct a new King:: King object
 *
 * @param color
 * @param position
 */

King::King(int color, std::pair<int, int> position) : Piece(color, position) {}

// Getters

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string King::getName() { return name; };

/**
 * @brief Get the Color object
 *
 * @return int
 */

int King::getColor() { return color; };

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string King::getSymbol() { return symbol; };

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> King::getPosition() { return position; };

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void King::setPosition(std::pair<int, int> position) { this->position = position; };

// Methods

/**
 * @brief Checks if the move is valid
 *
 * @param positionToMove
 * @return true
 * @return false
 */

bool King::isValidMove(std::pair<int, int> positionToMove, Board &board)
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

    // Check if the move is valid
    if (abs(xDifference) > 1 || abs(yDifference) > 1)
    {
        return false;
    }

    // Capture piece if there is one
    if (board.getPiece(positionToMove) != nullptr && board.getPiece(positionToMove)->getColor() != color && board.getPiece(positionToMove)->getName() != "King")
    {
        board.capturePiece(positionToMove);
    }

    // Move is valid
    return true;
}

#endif