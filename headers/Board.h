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
    std::pair<std::pair<int, int>, std::pair<int, int>> lastMove; // Last move made
public:
    // Constructor
    Board();

    // Copy constructor
    Board(const Board &);

    // Destructor
    ~Board();

    // Getters
    Piece *getPiece(std::pair<int, int>);
    std::pair<std::pair<int, int>, std::pair<int, int>> getLastMove();

    // Setters
    void setLastMove(std::pair<int, int>, std::pair<int, int>);

    // Methods
    void initializeBoard();
    void printBoard(int);

    bool isOccupied(std::pair<int, int>);
    bool movePiece(std::pair<int, int>, std::pair<int, int>);
    bool removePiece(std::pair<int, int>);

    std::pair<int, int> getKingPosition(int);
    std::vector<Piece*> getPieces(int);
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> getAllPossibleMoves(int);

    bool isAttacked(int, std::pair<int, int>);
    bool isCheck(int);
};

#endif