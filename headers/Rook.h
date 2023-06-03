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

#include "../drivers/Piece.cpp" // Parent class

class Rook : public Piece
{
private:
    // Attributes
    std::string name = "Rook"; // Name of the piece
    std::string symbol = "R";  // R for rook
public:
    // Constructor
    Rook();
    Rook(int color, std::pair<int, int> position);

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
    void showPieceInfo();
    bool isValidMove(std::pair<int, int> positionToMove, Board &board);
};

#endif