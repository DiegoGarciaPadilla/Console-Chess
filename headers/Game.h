/**
 * @file Game.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Game class
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "../drivers/Board.cpp" // Board class
#include "../drivers/Piece.cpp" // Parent class

class Game
{
private:
    // Attributes
    Board board;
    int turn = 0; // 0 = white, 1 = black

    // Captured pieces
    std::vector<Piece *> whiteCapturedPieces; // Pieces captured by white
    std::vector<Piece *> blackCapturedPieces; // Pieces captured by black
public:
    // Constructor
    Game();

    // Destructor
    ~Game();

    // Getters
    int getTurn();

    // Setters
    void setTurn(int);

    // Methods
    void newGame();
    void playGame();
    void printBoard();
    void printCapturedPieces();
    void clearScreen();

    bool movePiece(std::pair<int, int>, std::pair<int, int>);
    bool capturePiece(std::pair<int, int>);

    bool isCheck(int turn);
    bool isCheckAfterMove(std::pair<int, int>, std::pair<int, int>);
    bool isCheckmate(int turn);
    bool isStalemate(int turn);
};

#endif