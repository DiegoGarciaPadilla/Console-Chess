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
    std::string name = "King"; // Name of the piece
    std::string symbol = "K"; // K for king
public:
    // Constructor
    King();
    King(int color, std::pair<int, int> position);

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
 * @brief Construct a new King:: King object
 * 
 */

King::King() : Piece() {}

/**
 * @brief Construct a new King:: King object
 * 
 * @param color 
 * @param position 
 */

King::King(int color, std::pair<int, int> position) : Piece(color, position) {}

// Methods

/**
 * @brief Checks if the move is valid
 * 
 * @param positionToMove 
 * @return true 
 * @return false 
 */

/**
 * @brief Shows the piece's information
 * 
 */

void King::showPieceInfo()
{
    std::cout << "Piece: " <<  name << std::endl;
    std::cout << "Symbol: " << symbol << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Position: (" << position.first << ", " << position.second << ")" << std::endl;
    std::cout << "Is captured: " << isCaptured << std::endl;
}

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