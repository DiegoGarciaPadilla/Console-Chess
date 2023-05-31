/**
 * @file Pawn.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Pawn subclass
 * @version 0.1
 * @date 2023-05-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include <utility>

#include "Piece.h" // Parent class

class Pawn : public Piece
{
private:
    // Attributes
    std::string symbol = ""; // The pawn has no symbol
public:
    // Constructor
    Pawn();
    Pawn(int color, std::pair<int, int> position);

    // Methods
    bool isValidMove(std::pair<int, int> positionToMove);
};

// Constructor

/**
 * @brief Construct a new Pawn:: Pawn object
 * 
 */

Pawn::Pawn()
{
    color = 0;
    position = std::make_pair(0, 0);
    isCaptured = false;
}

/**
 * @brief Construct a new Pawn:: Pawn object
 * 
 * @param color 
 * @param position 
 */

Pawn::Pawn(int color, std::pair<int, int> position)
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

bool Pawn::isValidMove(std::pair<int, int> positionToMove)
{
    // Check if the Pawn is moving horizontally
    if (position.first != positionToMove.first) 
    {
        return false;
    }
    
    if (color == 0) // White
    {
        if (position.second == positionToMove.second + 1)
        {
            return true;
        }
        else if (position.second == positionToMove.second + 2 && position.second == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else // Black
    {
        if (position.second == positionToMove.second - 1)
        {
            return true;
        }
        else if (position.second == positionToMove.second - 2 && position.second == 6)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


#endif