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
    std::string name = "Pawn"; // Name of the piece
    std::string symbol = "P"; // P for pawn
public:
    // Constructor
    Pawn();
    Pawn(int color, std::pair<int, int> position);

    // Getters
    std::string getName() { return name; };
    int getColor() { return color; };
    std::string getSymbol() { return symbol; };
    std::pair<int, int> getPosition() { return position; };
    bool getIsCaptured() { return isCaptured; };

    // Setters
    void setPosition(std::pair<int, int> position) { this->position = position; };
    void setIsCaptured(bool isCaptured) { this->isCaptured = isCaptured; };

    // Methods
    void showPieceInfo();
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

Pawn::Pawn(int color, std::pair<int, int> position) : Piece(color, position){}

// Methods

/**
 * @brief Shows the piece's information
 * 
 */

void Pawn::showPieceInfo()
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