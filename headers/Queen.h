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
    std::string name = "Queen"; // Name of the piece
    std::string symbol = "Q"; // Q for queen
public:
    // Constructor
    Queen();
    Queen(int color, std::pair<int, int> position);

    // Methods
    void showPieceInfo();
    bool isValidMove(std::pair<int, int> positionToMove);
};

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

// Methods

/**
 * @brief Shows the piece's information
 * 
 */

void Queen::showPieceInfo()
{
    std::cout << "Piece: " <<  name << std::endl;
    std::cout << "Symbol: " << symbol << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Position: (" << position.first << ", " << position.second << ")" << std::endl;
    std::cout << "Is captured: " << isCaptured << std::endl;
}

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