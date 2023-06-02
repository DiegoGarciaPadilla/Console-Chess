/**
 * @file Rook.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Rook subclass
 * @version 0.1
 * @date 2023-05-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include <utility>

#include "Piece.h" // Parent class

class Rook : public Piece
{
private:
    // Attributes
    std::string name = "Rook"; // Name of the piece
    std::string symbol = "R"; // R for rook
public:
    // Constructor
    Rook();
    Rook(int color, std::pair<int, int> position);

    // Methods
    void showPieceInfo();
    bool isValidMove(std::pair<int, int> positionToMove);
};

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

Rook::Rook(int color, std::pair<int, int> position) : Piece(color, position){}

// Methods

/**
 * @brief Shows the piece's information
 * 
 */

void Rook::showPieceInfo()
{
    std::cout << "Piece: " <<  name << std::endl;
    std::cout << "Symbol: " << symbol << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Position: (" << position.first << ", " << position.second << ")" << std::endl;
    std::cout << "Is captured: " << isCaptured << std::endl;
}

/**
 * @brief Check if the move is valid
 * 
 * @param positionToMove 
 * @return true 
 * @return false 
 */

bool Rook::isValidMove(std::pair<int, int> positionToMove)
{
    if (positionToMove.first == position.first || positionToMove.second == position.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif