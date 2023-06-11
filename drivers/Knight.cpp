/**
 * @file Knight.cpp
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Implementation of the Knight class
 * @version 0.1
 * @date 2023-06-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef KNIGHT_CPP
#define KNIGHT_CPP

#include <iostream>
#include <utility>
#include <string>

#include "../headers/Knight.h" // Header file
#include "Board.cpp"           // Board class

// Constructor

/**
 * @brief Construct a new Knight:: Knight object
 *
 */

Knight::Knight() : Piece() {}
/**
 * @brief Construct a new Knight:: Knight object
 *
 * @param color
 * @param position
 */

Knight::Knight(int color, std::pair<int, int> position) : Piece(color, position) {}

// Getters

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string Knight::getName() { return name; }

/**
 * @brief Get the Color object
 *
 * @return int
 */

int Knight::getColor() { return color; }

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string Knight::getSymbol() { return symbol; }

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> Knight::getPosition() { return position; }

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void Knight::setPosition(std::pair<int, int> position) { this->position = position; }

/**
 * @brief Get the Has Moved object
 *
 * @return true
 * @return false
 */

bool Knight::getHasMoved() { return hasMoved; };

// Methods

/**
 * @brief Checks if the move is valid
 *
 * @param positionToMove
 * @return true
 * @return false
 */

bool Knight::isValidMove(std::pair<int, int> positionToMove, Board &board)
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

    // Check if the knight doesn't move in L shape
    if (!((abs(xDifference) == 2 && abs(yDifference) == 1) || (abs(xDifference) == 1 && abs(yDifference) == 2)))
    {
        return false;
    }

    // If the move is in L shape, return true
    return true;
}

/**
 * @brief Return a vector with all the possible moves
 * 
 * @param board
 * @return std::vector<std::pair<int, int>>
 */

/**
 * @brief Return a vector with all the possible moves
 * 
 * @param board
 * @return std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>
 */

std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> Knight::getPossibleMoves(Board &board)
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