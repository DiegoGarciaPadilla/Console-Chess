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
    bool isFirstMove = true; // True if it's the first move of the piece
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

Pawn::Pawn() : Piece() {}

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
    std::cout << "Is first move: " << isFirstMove << std::endl;
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
    // Get row and column of the position
    int xInitial = position.first;
    int yInitial = position.second;

    // Get row and column of the position to move
    int xFinal = positionToMove.first;
    int yFinal = positionToMove.second;

    // Get difference between initial and final position
    int xDifference = xFinal - xInitial;
    int yDifference = yFinal - yInitial;

    // Check if the pawn is moving horizontally
    if (xDifference != 0)
    {
        std::cout << "The pawn can't move horizontally" << std::endl;
        return false;
    }

    // Check if the pawn is moving backwards
    if (color == 0 && yDifference < 0)
    {
        std::cout << "The pawn can't move backwards" << std::endl;
        return false;
    }
    else if (color == 1 && yDifference > 0)
    {
        return false;
    }

    // Check if the pawn is moving more than 2 spaces
    if (abs(yDifference) > 2)
    {
        std::cout << "The pawn can't move more than 2 spaces" << std::endl;
        return false;
    }

    // Check if the pawn is moving more than 1 space after the first move
    if (!isFirstMove && abs(yDifference) > 1)
    {
        std::cout << "The pawn can't move more than 1 space after the first move" << std::endl;
        return false;
    }

    // Move is valid

    // Set first move to false
    isFirstMove = false;

    return true;

}


#endif