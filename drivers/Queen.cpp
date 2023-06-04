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

    // Check if the move is not diagonal, horizontal or vertical
    if (abs(xDifference) != abs(yDifference) && xDifference != 0 && yDifference != 0)
    {
        std::cout << "The queen only moves diagonally, horizontally or vertically" << std::endl;
        return false;
    }

    // Check if there are pieces in the way

    // Check if the move is diagonal
    if (xDifference == yDifference)
    {
        // Check if the move is diagonal up
        if (xDifference > 0)
        {
            // Check if there are pieces in the way
            for (int i = 1; i < xDifference; i++)
            {
                if (board.getPiece(std::make_pair(xInitial + i, yInitial + i)) != nullptr)
                {
                    std::cout << "There are pieces in the way" << std::endl;
                    return false;
                }
            }
        }
        // Check if the move is diagonal down
        else
        {
            // Check if there are pieces in the way
            for (int i = 1; i < -xDifference; i++)
            {
                if (board.getPiece(std::make_pair(xInitial - i, yInitial - i)) != nullptr)
                {
                    std::cout << "There are pieces in the way" << std::endl;
                    return false;
                }
            }
        }
    }
    // Check if the move is horizontal or vertical
    else
    {
        // Check if the move is horizontal
        if (xDifference == 0)
        {
            // Check if the move is horizontal right
            if (yDifference > 0)
            {
                // Check if there are pieces in the way
                for (int i = 1; i < yDifference; i++)
                {
                    if (board.getPiece(std::make_pair(xInitial, yInitial + i)) != nullptr)
                    {
                        std::cout << "There are pieces in the way" << std::endl;
                        return false;
                    }
                }
            }
            // Check if the move is horizontal left
            else
            {
                // Check if there are pieces in the way
                for (int i = 1; i < -yDifference; i++)
                {
                    if (board.getPiece(std::make_pair(xInitial, yInitial - i)) != nullptr)
                    {
                        std::cout << "There are pieces in the way" << std::endl;
                        return false;
                    }
                }
            }
        }
        // Check if the move is vertical
        else
        {
            // Check if the move is vertical up
            if (xDifference > 0)
            {
                // Check if there are pieces in the way
                for (int i = 1; i < xDifference; i++)
                {
                    if (board.getPiece(std::make_pair(xInitial + i, yInitial)) != nullptr)
                    {
                        std::cout << "There are pieces in the way" << std::endl;
                        return false;
                    }
                }
            }
            // Check if the move is vertical down
            else
            {
                // Check if there are pieces in the way
                for (int i = 1; i < -xDifference; i++)
                {
                    if (board.getPiece(std::make_pair(xInitial - i, yInitial)) != nullptr)
                    {
                        std::cout << "There are pieces in the way" << std::endl;
                        return false;
                    }
                }
            }
        }
    }

    // Capture piece if there is one
    if (board.getPiece(positionToMove) != nullptr && board.getPiece(positionToMove)->getColor() != color)
    {
        // Check if is the king
        if (board.getPiece(positionToMove)->getName() == "King")
        {
            std::cout << "You can't capture the king" << std::endl;
            return false;
        }
        // If it's not the king, capture the piece
        else
        {
            board.capturePiece(positionToMove);
        }
    }

    // If the move is diagonal, horizontal or vertical, and there are no pieces in the way, the move is valid
    return true;
}

#endif