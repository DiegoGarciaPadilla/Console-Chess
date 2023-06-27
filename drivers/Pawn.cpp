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

/**
 * @brief Get the Has Moved object
 *
 * @return true
 * @return false
 */

bool Pawn::getHasMoved() { return hasMoved; };

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void Pawn::setPosition(std::pair<int, int> position) { this->position = position; }

/**
 * @brief Set the Has Moved object
 *
 * @param hasMoved
 */

void Pawn::setHasMoved(bool hasMoved) { this->hasMoved = hasMoved; }

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
    if (abs(xDifference) > 1 || (abs(xDifference) == 1 && abs(yDifference) == 0))
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

    // Check for first move
    if (!hasMoved)
    {
        // Check if the pawn is moving more than 2 spaces
        if (abs(yDifference) > 2 || abs(yDifference) == 2 && abs(xDifference) > 0)
        {
            return false;
        }
    }

    // Check if the pawn is moving more than 2 spaces
    if (abs(yDifference) > 2)
    {
        return false;
    }

    // Check if the pawn is moving more than 1 space after the first move
    if (hasMoved && abs(yDifference) > 1)
    {
        return false;
    }

    // Check if the pawn is capturing 2 spaces away
    if (abs(xDifference) >= 1 && abs(yDifference) >= 2)
    {
        return false;
    }

    // Check if the pawn is moving other than vertically or diagonally
    if (abs(xDifference) > 1 && abs(yDifference) > 1)
    {
        return false;
    }

    // Check if the pawn is capturing vertically
    if (abs(xDifference) == 0 && abs(yDifference) >= 1 && board.isOccupied(positionToMove))
    {
        return false;
    }

    // Check if the pawn is moving diagonally
    if (abs(xDifference) == 1 && abs(yDifference) == 1)
    {
        // Check if the pawn is capturing
        if (!board.isOccupied(positionToMove) && !isEnPassant(board, positionToMove))
        {
            return false;
        }
    }

    // Check if there is a piece in the position to move and if it is an enemy piece
    if (board.isOccupied(positionToMove) && board.getPiece(positionToMove)->getColor() == color)
    {
        return false;
    }

    // Return true if the move is valid
    return true;
}

/**
 * @brief Return a vector with all the possible moves
 *
 * @param board
 * @return std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>
 */

std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> Pawn::getPossibleMoves(Board &board)
{
    // Initialize vector
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> possibleMoves;

    // Initialize pairs
    std::pair<int, int> startPosition;
    std::pair<int, int> endPosition;

    // Get row and column of the position
    int xInitial = position.first;
    int yInitial = position.second;

    // Check all the possible moves
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // Check if the move is valid
            if (isValidMove(std::make_pair(i, j), board))
            {
                // Set start and end positions
                startPosition = std::make_pair(xInitial, yInitial);
                endPosition = std::make_pair(i, j);

                // Add the move to the vector
                possibleMoves.push_back(std::make_pair(startPosition, endPosition));
            }
        }
    }

    // Return vector
    return possibleMoves;
}

/**
 * @brief Check if the move is en passant
 *
 * @param board
 * @param positionToMove
 * @return true
 * @return false
 */

bool Pawn::isEnPassant(Board &board, std::pair<int, int> positionToMove)
{
    // Get row and column of the position
    int xInitial = position.first;
    int yInitial = position.second;

    // Get row and column of the position to move
    int xFinal = positionToMove.first;
    int yFinal = positionToMove.second;

    // Get last move
    std::pair<int, int> initialPositionLastMove = board.getLastMove().first;
    std::pair<int, int> finalPositionLastMove = board.getLastMove().second;

    // Get row and column of the last moved piece
    int xLastMove = finalPositionLastMove.first;
    int yLastMove = finalPositionLastMove.second;

    // Get difference between initial and final position
    int xDifference = finalPositionLastMove.first - initialPositionLastMove.first;
    int yDifference = finalPositionLastMove.second - initialPositionLastMove.second;

    // Check if the pawn is in the correct row
    if (color == 0 && yInitial != 4)
    {
        return false;
    }
    else if (color == 1 && yInitial != 3)
    {
        return false;
    }

    // Check if the last move was a pawn and if it moved 2 spaces
    if (board.getPiece(finalPositionLastMove)->getName() != "Pawn" || abs(yDifference) != 2 || abs(xDifference) != 0)
    {
        return false;
    }

    // Check if the current pawn is in the same row as the last moved pawn and if the last move was 1 space away
    if (yInitial == yLastMove && abs(xInitial - xLastMove) == 1)
    {
        // Check if the pawn is moving diagonally
        if (abs(xFinal - xInitial) == 1 && abs(yFinal - yInitial) == 1)
        {
            // Check if the final position is empty
            if (!board.isOccupied(positionToMove))
            {
                // Check if the pawn is moving to the same column as the last moved pawn
                if (xFinal == xLastMove)
                {
                    // Return true if the move is en passant
                    return true;
                }
            }
        }
    }

    // Return false if the move is not en passant
    return false;
}

#endif