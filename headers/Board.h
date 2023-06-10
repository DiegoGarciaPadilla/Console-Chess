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
    Piece *board[8][8]; // Board
public:
    // Constructor
    Board();

    // Destructor
    ~Board();

    // Methods
    void initializeBoard();
    void printBoard(int);

    bool isOccupied(std::pair<int, int>);
    bool standardMove(std::pair<int, int>, std::pair<int, int>);

    std::pair<int, int> getKingPosition(int);

    bool isAttacked(int, std::pair<int, int>);
    bool isCheck(int);
    
    Piece *getPiece(std::pair<int, int>);
};

#endif