/**
 * @file main.cpp
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Main file for the chess game
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "headers\Piece.h" // Parent class
#include "headers\Pawn.h" // Pawn subclass
#include "headers\Rook.h" // Rook subclass
#include "headers\Knight.h" // Knight subclass
#include "headers\Bishop.h" // Bishop subclass
#include "headers\Queen.h" // Queen subclass
#include "headers\King.h" // King subclass
#include "headers\Board.h" // Board class

void testPiece(Piece *piece)
{
    std::pair<int, int> position1 = std::make_pair(1, 1);
    std::pair<int, int> position2 = std::make_pair(1, 0);
    std::pair<int, int> position3 = std::make_pair(2, 1);

    std::cout << "Piece color: " << piece->getColor() << std::endl;
    std::cout << "Piece symbol: " << piece->getSymbol() << std::endl;
    std::cout << "Piece position: (" << piece->getPosition().first << ", " << piece->getPosition().second << ")" << std::endl;
    std::cout << "Piece isCaptured: " << piece->getIsCaptured() << std::endl;

    std::cout << "Piece isValidMove(1, 1): " << piece->isValidMove(position1) << std::endl;
    std::cout << "Piece isValidMove(1, 0): " << piece->isValidMove(position2) << std::endl;
    std::cout << "Piece isValidMove(2, 1): " << piece->isValidMove(position3) << std::endl;
}

int main()
{
    // Create pieces
    Piece *pawn = new Pawn(0, std::make_pair(0, 0));
    Piece *rook = new Rook(0, std::make_pair(0, 0));
    Piece *knight = new Knight(0, std::make_pair(0, 0));
    Piece *bishop = new Bishop(0, std::make_pair(0, 0));
    Piece *queen = new Queen(0, std::make_pair(0, 0));
    Piece *king = new King(0, std::make_pair(0, 0));

    // Test pieces

    std::cout << "Pawn" << std::endl;
    testPiece(pawn);

    std::cout << "Rook" << std::endl;
    testPiece(rook);

    std::cout << "Knight" << std::endl;
    testPiece(knight);

    std::cout << "Bishop" << std::endl;
    testPiece(bishop);

    std::cout << "Queen" << std::endl;
    testPiece(queen);

    std::cout << "King" << std::endl;
    testPiece(king);

    // Delete pieces

    delete pawn;
    delete rook;
    delete knight;
    delete bishop;
    delete queen;
    delete king;

}