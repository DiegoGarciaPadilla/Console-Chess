/**
 * @file Rook.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Rook subclass
 * @version 0.1
 * @date 2023-05-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include <utility>

#include "Piece.h" // Parent class

class Rook : public Piece
{
private:
    // Attributes
    std::string name = "Rook"; // Name of the piece
    std::string symbol = "R";  // R for rook
public:
    // Constructor
    Rook();
    Rook(int color, std::pair<int, int> position);

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
    bool isValidMove(std::pair<int, int> positionToMove, Board &board);
};

// Constructor

/**
 * @brief Construct a new Rook:: Rook object
 *
 */

Rook::Rook() : Piece() {}

/**
 * @brief Construct a new Rook:: Rook object
 *
 * @param color
 * @param position
 */

Rook::Rook(int color, std::pair<int, int> position) : Piece(color, position) {}

// Getters

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string Rook::getName() { return name; }

/**
 * @brief Get the Color object
 *
 * @return int
 */

int Rook::getColor() { return color; }

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string Rook::getSymbol() { return symbol; }

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> Rook::getPosition() { return position; }

/**
 * @brief Get the Is Captured object
 *
 * @return true
 * @return false
 */

bool Rook::getIsCaptured() { return isCaptured; }

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void Rook::setPosition(std::pair<int, int> position) { this->position = position; }

/**
 * @brief Set the Is Captured object
 *
 * @param isCaptured
 */

void Rook::setIsCaptured(bool isCaptured) { this->isCaptured = isCaptured; }

// Methods

/**
 * @brief Shows the piece's information
 *
 */

void Rook::showPieceInfo()
{
    std::cout << "Piece: " << name << std::endl;
    std::cout << "Symbol: " << symbol << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Position: (" << position.first << ", " << position.second << ")" << std::endl;
    std::cout << "Is captured: " << isCaptured << std::endl;
}

/**
 * @brief Check if the move is valid
 *
 * @param positionToMove
 * @return true
 * @return false
 */

bool Rook::isValidMove(std::pair<int, int> positionToMove, Board &board)
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

    // Check if the move is not horizontal or vertical
    if (xDifference != 0 && yDifference != 0)
    {
        std::cout << "The rook only moves horizontally or vertically" << std::endl;
        return false;
    }

    // Check if there are pieces in the way

    // If the move is horizontal
    if (xDifference != 0)
    {
        // If the rook is moving to the right
        if (xDifference > 0)
        {
            // Check if there are pieces in the way
            for (int i = xInitial + 1; i < xFinal; i++)
            {
                if (board.getPiece(std::make_pair(i, yInitial)) != nullptr)
                {
                    std::cout << "There are pieces in the way" << std::endl;
                    return false;
                }
            }
        }
        // If the rook is moving to the left
        else
        {
            // Check if there are pieces in the way
            for (int i = xInitial - 1; i > xFinal; i--)
            {
                if (board.getPiece(std::make_pair(i, yInitial)) != nullptr)
                {
                    std::cout << "There are pieces in the way" << std::endl;
                    return false;
                }
            }
        }
    }
    // If the move is vertical
    else
    {
        // If the rook is moving up
        if (yDifference > 0)
        {
            // Check if there are pieces in the way
            for (int i = yInitial + 1; i < yFinal; i++)
            {
                if (board.getPiece(std::make_pair(xInitial, i)) != nullptr)
                {
                    std::cout << "There are pieces in the way" << std::endl;
                    return false;
                }
            }
        }
        // If the rook is moving down
        else
        {
            // Check if there are pieces in the way
            for (int i = yInitial - 1; i > yFinal; i--)
            {
                if (board.getPiece(std::make_pair(xInitial, i)) != nullptr)
                {
                    std::cout << "There are pieces in the way" << std::endl;
                    return false;
                }
            }
        }
    }

    // If the move is horizontal or vertical, it's valid
    return true;
}

#endif