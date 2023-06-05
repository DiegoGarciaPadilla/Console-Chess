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

#include "../drivers/Piece.cpp" // Parent class

class Bishop : public Piece
{
private:
    // Attributes
    std::string name = "Bishop"; // Name of the piece
    std::string symbol = "B";    // B for bishop
public:
    // Constructor
    Bishop();
    Bishop(int color, std::pair<int, int> position);

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