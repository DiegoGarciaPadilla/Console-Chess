/**
 * @file King.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the King subclass
 * @version 0.1
 * @date 2023-05-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef KING_H
#define KING_H

#include <iostream>
#include <utility>

#include "Piece.h" // Parent class

class King : public Piece
{
private:
    // Attributes
    std::string name = "King"; // Name of the piece
    std::string symbol = "K";  // K for king
public:
    // Constructor
    King();
    King(int color, std::pair<int, int> position);

    // Getters
    std::string getName();
    int getColor();
    std::string getSymbol();
    std::pair<int, int> getPosition();
    bool getIsCaptured();

    // Setters
    void setPosition(std::pair<int, int> position);
    void setIsCaptured(bool isCaptured);

    // Methods
    void showPieceInfo();
    bool isValidMove(std::pair<int, int> positionToMove);
};

// Constructor

/**
 * @brief Construct a new King:: King object
 *
 */

King::King() : Piece() {}

/**
 * @brief Construct a new King:: King object
 *
 * @param color
 * @param position
 */

King::King(int color, std::pair<int, int> position) : Piece(color, position) {}

// Getters

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string King::getName() { return name; };

/**
 * @brief Get the Color object
 *
 * @return int
 */

int King::getColor() { return color; };

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string King::getSymbol() { return symbol; };

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> King::getPosition() { return position; };

/**
 * @brief Get the Is Captured object
 *
 * @return true
 * @return false
 */

bool King::getIsCaptured() { return isCaptured; };

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void King::setPosition(std::pair<int, int> position) { this->position = position; };

/**
 * @brief Set the Is Captured object
 *
 * @param isCaptured
 */

void King::setIsCaptured(bool isCaptured) { this->isCaptured = isCaptured; };

// Methods

/**
 * @brief Checks if the move is valid
 *
 * @param positionToMove
 * @return true
 * @return false
 */

/**
 * @brief Shows the piece's information
 *
 */

void King::showPieceInfo()
{
    std::cout << "Piece: " << name << std::endl;
    std::cout << "Symbol: " << symbol << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Position: (" << position.first << ", " << position.second << ")" << std::endl;
    std::cout << "Is captured: " << isCaptured << std::endl;
}

bool King::isValidMove(std::pair<int, int> positionToMove)
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

    // Check if the move is valid
    if (abs(xDifference) > 1 && abs(yDifference) > 1)
    {
        std::cout << "The king can only move one space at a time" << std::endl;
        return false;
    }

    // Move is valid
    return true;
}

#endif