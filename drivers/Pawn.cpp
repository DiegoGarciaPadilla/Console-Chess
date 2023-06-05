/**
 * @file Pawn.cpp
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Implementation of the Pawn class
 * @version 0.1
 * @date 2023-06-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PAWN_CPP
#define PAWN_CPP

#include <iostream>
#include <utility>
#include <string>

#include "../headers/Pawn.h" // Header file
#include "Board.cpp"         // Board class

// Constructor

/**
 * @brief Construct a new Pawn:: Pawn object
 *
 */

Pawn::Pawn() : Piece() {}

/**
 * @brief Construct a new Pawn:: Pawn object
 *
 * @param color
 * @param position
 */

Pawn::Pawn(int color, std::pair<int, int> position) : Piece(color, position) {}

// Getters

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string Pawn::getName() { return name; }

/**
 * @brief Get the Color object
 *
 * @return int
 */

int Pawn::getColor() { return color; }

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string Pawn::getSymbol() { return symbol; }

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> Pawn::getPosition() { return position; }

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void Pawn::setPosition(std::pair<int, int> position) { this->position = position; }

// Methods

/**
 * @brief Checks if the move is valid
 *
 * @param positionToMove
 * @return true
 * @return false
 */

bool Pawn::isValidMove(std::pair<int, int> positionToMove, Board &board)
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

    // Check if the pawn is moving horizontally
    if (abs(xDifference) > 1)
    {
        return false;
    }

    // Check if the pawn is moving backwards
    if (color == 0 && yDifference < 0)
    {
        return false;
    }
    else if (color == 1 && yDifference > 0)
    {
        return false;
    }

    // Check if the pawn is moving more than 2 spaces
    if (abs(yDifference) > 2)
    {
        return false;
    }

    // Check if the pawn is moving more than 1 space after the first move
    if (!isFirstMove && abs(yDifference) > 1)
    {
        return false;
    }

    // Check if the pawn is moving diagonally more than 1 space
    if (abs(yDifference) == abs(xDifference) && abs(yDifference) > 1)
    {
        return false;
    }
    // Check if the pawn is moving diagonally without capturing
    else if (abs(yDifference) == abs(xDifference) && abs(yDifference) == 1 && board.getPiece(std::make_pair(xFinal, yFinal)) == nullptr)
    {
        return false;
    }

    // Capture piece if there is one
    if (board.getPiece(positionToMove) != nullptr && board.getPiece(positionToMove)->getColor() != color && board.getPiece(positionToMove)->getName() != "King")
    {
        board.capturePiece(positionToMove);
    }

    // Set first move to false
    isFirstMove = false;

    // Return true if the move is valid
    return true;
}

#endif