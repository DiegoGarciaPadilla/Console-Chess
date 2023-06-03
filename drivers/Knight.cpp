/**
 * @file Knight.cpp
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Implementation of the Knight class
 * @version 0.1
 * @date 2023-06-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef KNIGHT_CPP
#define KNIGHT_CPP

#include <iostream>
#include <utility>
#include <string>

#include "../headers/Knight.h" // Header file
#include "Board.cpp"           // Board class

// Constructor

/**
 * @brief Construct a new Knight:: Knight object
 *
 */

Knight::Knight() : Piece() {}
/**
 * @brief Construct a new Knight:: Knight object
 *
 * @param color
 * @param position
 */

Knight::Knight(int color, std::pair<int, int> position) : Piece(color, position) {}

// Getters

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string Knight::getName() { return name; }

/**
 * @brief Get the Color object
 *
 * @return int
 */

int Knight::getColor() { return color; }

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string Knight::getSymbol() { return symbol; }

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> Knight::getPosition() { return position; }

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void Knight::setPosition(std::pair<int, int> position) { this->position = position; }

// Methods

/**
 * @brief Checks if the move is valid
 *
 * @param positionToMove
 * @return true
 * @return false
 */

bool Knight::isValidMove(std::pair<int, int> positionToMove, Board &board)
{
    // Get row and column of the position
    int xInitial = position.first;
    int yInitial = position.second;

    // Get row and column of the position to move
    int xFinal = positionToMove.first;
    int yFinal = positionToMove.second;

    // Get difference between initial and final position
    int xDifference = xFinal - xInitial;
    int yDifference = yFinal - yInitial;

    // Check if the knight doesn't move in L shape
    if (!((abs(xDifference) == 2 && abs(yDifference) == 1) || (abs(xDifference) == 1 && abs(yDifference) == 2)))
    {
        std::cout << "The knight can't move like that" << std::endl;
        return false;
    }

    // Capture piece if there is one
    if (board.getPiece(positionToMove) != nullptr && board.getPiece(positionToMove)->getColor() != color)
    {
        board.capturePiece(positionToMove);
    }

    // If the move is in L shape, return true
    return true;
}

#endif