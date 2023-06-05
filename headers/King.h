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

#include "../drivers/Piece.cpp" // Parent class

class King : public Piece
{
private:
    // Attributes
    std::string name = "King"; // Name of the piece
    std::string symbol = "K";  // K for king
public:
    // Constructor
    King();
    King(int color, std::pair<int, int> position);

    // Getters
    std::string getName();
    int getColor();
    std::string getSymbol();
    std::pair<int, int> getPosition();
    bool getHasMoved();

    // Setters
    void setPosition(std::pair<int, int> position);

    // Methods
    bool isValidMove(std::pair<int, int> positionToMove, Board &board);
};

#endif