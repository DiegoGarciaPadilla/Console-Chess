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

#include "../drivers/Piece.cpp" // Parent class

class Queen : public Piece
{
private:
    // Attributes
    std::string name = "Queen"; // Name of the piece
    std::string symbol = "Q";   // Q for queen
public:
    // Constructor
    Queen();
    Queen(int color, std::pair<int, int> position);

    // Getters
    std::string getName();
    int getColor();
    std::string getSymbol();
    std::pair<int, int> getPosition();
    bool getIsCaptured();

    // Setters
    void setPosition(std::pair<int, int> position);
    void setIsCaptured(bool isCaptured);

    // Methods
    bool isValidMove(std::pair<int, int> positionToMove, Board &board);
};

#endif