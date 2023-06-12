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

#include "../drivers/Piece.cpp" // Parent class

class Knight : public Piece
{
private:
    // Attributes
    std::string name = "Knight"; // Name of the piece
    std::string symbol = "N";    // N for knight
public:
    // Constructor
    Knight();
    Knight(int, std::pair<int, int>);

    // Getters
    std::string getName();
    int getColor();
    std::string getSymbol();
    std::pair<int, int> getPosition();
    bool getHasMoved();

    // Setters
    void setPosition(std::pair<int, int>);
    void setHasMoved(bool);

    // Methods
    bool isValidMove(std::pair<int, int>, Board&);
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> getPossibleMoves(Board&);
};

#endif