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
#include <string>

#include "Piece.h" // Parent class

class Bishop : public Piece
{
private:
    // Attributes
    std::string name = "Bishop"; // Name of the piece
    std::string symbol = "B"; // B for bishop
public:
    // Constructor
    Bishop();
    Bishop(int color, std::pair<int, int> position);

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
 * @brief Construct a new Bishop:: Bishop object
 * 
 */

Bishop::Bishop(): Piece() {}

/**
 * @brief Construct a new Bishop:: Bishop object
 * 
 * @param color 
 * @param position 
 */

Bishop::Bishop(int color, std::pair<int, int> position): Piece(color, position) {}

// Methods

/**
 * @brief Shows the piece's information
 * 
 */

void Bishop::showPieceInfo()
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

bool Bishop::isValidMove(std::pair<int, int> positionToMove) 
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

    // Check if the move is not diagonal
    if (abs(xDifference) != abs(yDifference))
    {
        return false;
    }

    // If the move is diagonal, is valid
    return true;
}

#endif