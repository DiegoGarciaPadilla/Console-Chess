/**
 * @file Piece.cpp
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Implementation of the Piece class
 * @version 0.1
 * @date 2023-06-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PIECE_CPP
#define PIECE_CPP

#include <iostream>
#include <utility>
#include <string>

#include "../headers/Piece.h" // Header file
#include "Board.cpp"          // Board class

// Constructor

/**
 * @brief Construct a new Piece:: Piece object
 *
 */

Piece::Piece()
{
    this->color = 0;
    this->position = std::make_pair(0, 0);
}

/**
 * @brief Construct a new Piece:: Piece object
 *
 * @param color
 * @param position
 */

Piece::Piece(int color, std::pair<int, int> position)
{
    this->color = color;
    this->position = position;
}

// Getters

/**
 * @brief Get the Color object
 *
 * @return int
 */

int Piece::getColor() { return color; };

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string Piece::getName() { return name; };

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string Piece::getSymbol() { return symbol; };

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> Piece::getPosition() { return position; };

/**
 * @brief Get the Has Moved object
 *
 * @return true
 * @return false
 */

bool Piece::getHasMoved() { return hasMoved; };

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void Piece::setPosition(std::pair<int, int> position) { this->position = position; };

// Methods

/**
 * @brief Check if the move is valid
 *
 * @param position
 * @param board
 * @return true
 * @return false
 */

bool Piece::isValidMove(std::pair<int, int> position, Board &board)
{
    // This method will be implemented in the child classes by overriding it
    return true;
}

/**
 * @brief Get the Possible Moves object
 *
 * @param board
 * @return std::vector<std::pair<int, int>>
 */

std::vector<std::pair<int, int>> Piece::getPossibleMoves(Board &board)
{
    // This method will be implemented in the child classes by overriding it
    return std::vector<std::pair<int, int>>();
}

#endif