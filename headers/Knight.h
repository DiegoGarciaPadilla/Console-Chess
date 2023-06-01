/**
 * @file Knight.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Knight subclass
 * @version 0.1
 * @date 2023-05-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include <utility>

#include "Piece.h" // Parent class

class Knight : public Piece
{
private:
    // Attributes
    std::string name = "Knight"; // Name of the piece
    std::string symbol = "N"; // N for knight
public:
    // Constructor
    Knight();
    Knight(int color, std::pair<int, int> position);

    // Methods
    bool isValidMove(std::pair<int, int> positionToMove);
};

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

// Methods

/**
 * @brief Checks if the move is valid
 * 
 * @param positionToMove 
 * @return true 
 * @return false 
 */

bool Knight::isValidMove(std::pair<int, int> positionToMove)
{
    int currentRow = position.first;
    int currentCol = position.second;
    int targetRow = positionToMove.first;
    int targetCol = positionToMove.second;

    int rowDiff = abs(targetRow - currentRow);
    int colDiff = abs(targetCol - currentCol);

    // A Knight moves in an "L" shape: two squares in one direction and one in the other.
    if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2)) {
        return true;
    }

    return false;
}

#endif