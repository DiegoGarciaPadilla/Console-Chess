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
 * @brief Shows the piece's information
 * 
 */

void Knight::showPieceInfo()
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

bool Knight::isValidMove(std::pair<int, int> positionToMove)
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

    // Check if the knight doesn't move in L shape
    if (!((abs(xDifference) == 2 && abs(yDifference) == 1) || (abs(xDifference) == 1 && abs(yDifference) == 2)))
    {
        std::cout << "The knight can't move like that" << std::endl;
        return false;
    }

    // If the move is in L shape, return true
    return true;
}

#endif