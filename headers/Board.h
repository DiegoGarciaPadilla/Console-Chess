/**
 * @file Board.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Board class
 * @version 0.1
 * @date 2023-05-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <utility>
#include <string>

#include "../drivers/Piece.cpp" // Parent class

class Board
{
private:
    // Attributes
    Piece *board[8][8];
    int turn = 0; // 0 = white, 1 = black
public:
    // Constructor
    Board();

    // Destructor
    ~Board();

    // Getters
    int getTurn();

    // Setters
    void setTurn(int turn);

    // Methods
    void initializeBoard();

    void printBoard();
    void boardInfo();

    bool movePiece(std::pair<int, int> initialPosition, std::pair<int, int> finalPosition);
    Piece *getPiece(std::pair<int, int> position);
};

#endif