/**
 * @file Queen.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Queen subclass
 * @version 0.1
 * @date 2023-05-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include <utility>

#include "Piece.h" // Parent class

class Queen : public Piece
{
private:
    // Attributes
    std::string symbol = "Q"; // Q for queen
public:
    // Constructor
    Queen();
    Queen(int color, std::pair<int, int> position);

    // Methods
    bool isValidMove(std::pair<int, int> positionToMove);
};

// Constructor

/**
 * @brief Construct a new Queen:: Queen object
 * 
 */

Queen::Queen()
{
    color = 0;
    position = std::make_pair(0, 0);
    isCaptured = false;
}

/**
 * @brief Construct a new Queen:: Queen object
 * 
 * @param color 
 * @param position 
 */

Queen::Queen(int color, std::pair<int, int> position)
{
    this->color = color;
    this->position = position;
    this->isCaptured = false;
}

// Methods

/**
 * @brief Checks if the move is valid
 * 
 * @param positionToMove 
 * @return true 
 * @return false 
 */

bool Queen::isValidMove(std::pair<int, int> positionToMove)
{
    // Check if the move is diagonal
    if (abs(positionToMove.first - position.first) == abs(positionToMove.second - position.second))
    {
        return true;
    }
    // Check if the move is horizontal
    else if (positionToMove.first == position.first)
    {
        return true;
    }
    // Check if the move is vertical
    else if (positionToMove.second == position.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif