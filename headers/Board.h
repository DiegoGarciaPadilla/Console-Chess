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

    // Captured pieces
    std::vector<Piece *> whiteCapturedPieces; // Pieces captured by white
    std::vector<Piece *> blackCapturedPieces; // Pieces captured by black
public:
    // Constructor
    Board();

    // Destructor
    ~Board();

    // Getters
    int getTurn();

    // Setters
    void setTurn(int);

    // Methods
    void initializeBoard();
    void printBoard();

    bool movePiece(std::pair<int, int>, std::pair<int, int>);
    bool capturePiece(std::pair<int, int>);

    std::pair<int, int> getKingPosition(int);

    bool isAttacked(std::pair<int, int>);
    bool isCheck();
    
    Piece *getPiece(std::pair<int, int>);
};

#endif