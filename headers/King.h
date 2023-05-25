/**
 * @file King.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the King subclass
 * @version 0.1
 * @date 2023-05-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef KING_H
#define KING_H

#include <iostream>
#include <utility>

#include "Piece.h" // Parent class

class King : public Piece
{
private:
    // Attributes
    std::string symbol = "K"; // K for king
public:
    // Constructor
    King();
    King(int color, std::pair<int, int> position);

    // Methods
    bool isValidMove(std::pair<int, int> positionToMove);
};

// Constructor

/**
 * @brief Construct a new King:: King object
 * 
 */

King::King()
{
    color = 0;
    position = std::make_pair(0, 0);
    isCaptured = false;
}

/**
 * @brief Construct a new King:: King object
 * 
 * @param color 
 * @param position 
 */

King::King(int color, std::pair<int, int> position)
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

bool King::isValidMove(std::pair<int, int> positionToMove) {
    int currentRow = position.first;
    int currentCol = position.second;
    int targetRow = positionToMove.first;
    int targetCol = positionToMove.second;

    int rowDiff = abs(targetRow - currentRow);
    int colDiff = abs(targetCol - currentCol);

    // The King can move in any direction, but only one square at a time.
    if ((rowDiff == 1 && colDiff == 0) || (rowDiff == 0 && colDiff == 1) || (rowDiff == 1 && colDiff == 1)) {
        return true;
    }

    return false;
}

#endif