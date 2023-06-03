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

#include "../drivers/Piece.cpp" // Parent class

class Pawn : public Piece
{
private:
    // Attributes
    std::string name = "Pawn"; // Name of the piece
    std::string symbol = "P";  // P for pawn
    bool isFirstMove = true;   // True if it's the first move of the piece
public:
    // Constructor
    Pawn();
    Pawn(int color, std::pair<int, int> position);

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