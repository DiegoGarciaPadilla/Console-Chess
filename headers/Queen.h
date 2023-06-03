/**
 * @file Queen.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Queen subclass
 * @version 0.1
 * @date 2023-05-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include <utility>

#include "Piece.h" // Parent class

class Queen : public Piece
{
private:
    // Attributes
    std::string name = "Queen"; // Name of the piece
    std::string symbol = "Q";   // Q for queen
public:
    // Constructor
    Queen();
    Queen(int color, std::pair<int, int> position);

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
 * @brief Construct a new Queen:: Queen object
 *
 */

Queen::Queen() : Piece() {}

/**
 * @brief Construct a new Queen:: Queen object
 *
 * @param color
 * @param position
 */

Queen::Queen(int color, std::pair<int, int> position) : Piece(color, position) {}

// Getters

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string Queen::getName() { return name; }

/**
 * @brief Get the Color object
 *
 * @return int
 */

int Queen::getColor() { return color; }

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string Queen::getSymbol() { return symbol; }

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> Queen::getPosition() { return position; }

/**
 * @brief Get the Is Captured object
 *
 * @return true
 * @return false
 */

bool Queen::getIsCaptured() { return isCaptured; }

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void Queen::setPosition(std::pair<int, int> position) { this->position = position; }

/**
 * @brief Set the Is Captured object
 *
 * @param isCaptured
 */

void Queen::setIsCaptured(bool isCaptured) { this->isCaptured = isCaptured; }

// Methods

/**
 * @brief Shows the piece's information
 *
 */

void Queen::showPieceInfo()
{
    std::cout << "Piece: " << name << std::endl;
    std::cout << "Symbol: " << symbol << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Position: (" << position.first << ", " << position.second << ")" << std::endl;
    std::cout << "Is captured: " << isCaptured << std::endl;
}

/**
 * @brief Checks if the move is valid
 *
 * @param positionToMove
 * @return true
 * @return false
 */

bool Queen::isValidMove(std::pair<int, int> positionToMove)
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

    // Check if the move is not diagonal, horizontal or vertical
    if (xDifference != yDifference && xDifference != 0 && yDifference != 0)
    {
        std::cout << "The queen only moves diagonally, horizontally or vertically" << std::endl;
        return false;
    }

    // If the move is diagonal, horizontal or vertical, return true
    return true;
}

#endif