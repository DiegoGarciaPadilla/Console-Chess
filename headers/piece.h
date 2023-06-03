/**
 * @file Piece.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Piece class
 * @version 0.1
 * @date 2023-05-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <utility>
#include <string>

class Board; // Forward declaration (to avoid circular dependencies)

class Piece
{
protected:
    // Attributes
    int color; // 0 = white, 1 = black

    std::string name = " ";   // Name of the piece
    std::string symbol = " "; // Symbol to print on the board

    std::pair<int, int> position; // (x, y)
    bool isCaptured = false;      // true = captured, false = not captured

public:
    // Constructor
    Piece();
    Piece(int color, std::pair<int, int> position);

    // Getters (the getters are virtual because they are overriden in the subclasses)
    virtual std::string getName();
    virtual int getColor();
    virtual std::string getSymbol();
    virtual std::pair<int, int> getPosition();
    virtual bool getIsCaptured();

    // Setters (the setters are virtual because they are overriden in the subclasses)
    virtual void setPosition(std::pair<int, int> position);
    virtual void setIsCaptured(bool isCaptured);

    // Methods (the methods are virtual because they are overriden in the subclasses)
    virtual bool isValidMove(std::pair<int, int> positionToMove, Board &board);
};

#endif