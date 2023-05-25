/**
 * @file Bishop.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Bishop subclass
 * @version 0.1
 * @date 2023-05-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include <utility>

#include "Piece.h" // Parent class

class Bishop : public Piece
{
private:
    // Attributes
public:
    // Constructor
    Bishop();
    Bishop(int color, std::pair<int, int> position);

    // Methods
    bool isValidMove(std::pair<int, int> positionToMove);
};

// Constructor

/**
 * @brief Construct a new Bishop:: Bishop object
 * 
 */

Bishop::Bishop()
{
    color = 0;
    position = std::make_pair(0, 0);
    isCaptured = false;
}

/**
 * @brief Construct a new Bishop:: Bishop object
 * 
 * @param color 
 * @param position 
 */

Bishop::Bishop(int color, std::pair<int, int> position)
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

bool Bishop::isValidMove(std::pair<int, int> positionToMove) {
    int currentRow = position.first;
    int currentCol = position.second;
    int targetRow = positionToMove.first;
    int targetCol = positionToMove.second;

    int rowDiff = abs(targetRow - currentRow);
    int colDiff = abs(targetCol - currentCol);

    // The bishop moves diagonally, so the difference in rows must be equal to the difference in columns.
    if (rowDiff == colDiff) {
        return true;
    }

    return false;
}

#endif