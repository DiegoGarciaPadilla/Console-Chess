/**
 * @file Rook.cpp
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Implementation of the Rook class
 * @version 0.1
 * @date 2023-06-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ROOK_CPP
#define ROOK_CPP

#include <iostream>
#include <utility>
#include <string>

#include "../headers/Rook.h" // Header file
#include "Board.cpp"         // Board class

// Constructor

/**
 * @brief Construct a new Rook:: Rook object
 *
 */

Rook::Rook() : Piece() {}

/**
 * @brief Construct a new Rook:: Rook object
 *
 * @param color
 * @param position
 */

Rook::Rook(int color, std::pair<int, int> position) : Piece(color, position) {}

// Getters

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string Rook::getName() { return name; }

/**
 * @brief Get the Color object
 *
 * @return int
 */

int Rook::getColor() { return color; }

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string Rook::getSymbol() { return symbol; }

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> Rook::getPosition() { return position; }

/**
 * @brief Get the Has Moved object
 *
 * @return true
 * @return false
 */

bool Rook::getHasMoved() { return hasMoved; };

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void Rook::setPosition(std::pair<int, int> position) { this->position = position; }

// Methods

/**
 * @brief Check if the move is valid
 *
 * @param positionToMove
 * @return true
 * @return false
 */

bool Rook::isValidMove(std::pair<int, int> positionToMove, Board &board)
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

    // Check if the move is not horizontal or vertical
    if (xDifference != 0 && yDifference != 0)
    {
        return false;
    }

    // Check if there are pieces in the way

    // If the move is horizontal
    if (xDifference != 0)
    {
        // If the rook is moving to the right
        if (xDifference > 0)
        {
            // Check if there are pieces in the way
            for (int i = xInitial + 1; i < xFinal; i++)
            {
                if (board.isOccupied(std::make_pair(i, yInitial)))
                {
                    return false;
                }
            }
        }
        // If the rook is moving to the left
        else
        {
            // Check if there are pieces in the way
            for (int i = xInitial - 1; i > xFinal; i--)
            {
                if (board.isOccupied(std::make_pair(i, yInitial)))
                {
                    return false;
                }
            }
        }
    }
    // If the move is vertical
    else
    {
        // If the rook is moving up
        if (yDifference > 0)
        {
            // Check if there are pieces in the way
            for (int i = yInitial + 1; i < yFinal; i++)
            {
                if (board.isOccupied(std::make_pair(i, yInitial)))
                {
                    return false;
                }
            }
        }
        // If the rook is moving down
        else
        {
            // Check if there are pieces in the way
            for (int i = yInitial - 1; i > yFinal; i--)
            {
                if (board.isOccupied(std::make_pair(i, yInitial)))
                {
                    return false;
                }
            }
        }
    }

    // If the move is horizontal or vertical, it's valid
    return true;
}

/**
 * @brief Return a vector with all the possible moves
 * 
 * @param board
 * @return std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>
 */

std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> Rook::getPossibleMoves(Board &board)
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

#endif