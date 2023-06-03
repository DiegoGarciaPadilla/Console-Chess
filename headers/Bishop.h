/**
 * @file Bishop.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Bishop subclass
 * @version 0.1
 * @date 2023-05-23
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include <utility>

#include "Piece.h" // Parent class

class Bishop : public Piece
{
private:
    // Attributes
    std::string name = "Bishop"; // Name of the piece
    std::string symbol = "B";    // B for bishop
public:
    // Constructor
    Bishop();
    Bishop(int color, std::pair<int, int> position);

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
 * @brief Construct a new Bishop:: Bishop object
 *
 */

Bishop::Bishop() : Piece() {}

/**
 * @brief Construct a new Bishop:: Bishop object
 *
 * @param color
 * @param position
 */

Bishop::Bishop(int color, std::pair<int, int> position) : Piece(color, position) {}

// Getters

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string Bishop::getName() { return name; };

/**
 * @brief Get the Color object
 *
 * @return int
 */

int Bishop::getColor() { return color; };

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string Bishop::getSymbol() { return symbol; };

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> Bishop::getPosition() { return position; };

/**
 * @brief Get the Is Captured object
 *
 * @return bool
 */

bool Bishop::getIsCaptured() { return isCaptured; };

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void Bishop::setPosition(std::pair<int, int> position) { this->position = position; };

/**
 * @brief Set the Is Captured object
 *
 * @param isCaptured
 */

void Bishop::setIsCaptured(bool isCaptured) { this->isCaptured = isCaptured; };

// Methods

/**
 * @brief Shows the piece's information
 *
 */

void Bishop::showPieceInfo()
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

bool Bishop::isValidMove(std::pair<int, int> positionToMove, Board &board)
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

    // Check if the move is not diagonal
    if (abs(xDifference) != abs(yDifference))
    {
        return false;
    }

    // Check if there are pieces in the way

    // Check if the bishop is moving to the right and up
    if (xDifference > 0 && yDifference > 0)
    {
        for (int i = 1; i < xDifference; i++)
        {
            if (board.getPiece(std::make_pair(xInitial + i, yInitial + i)) != nullptr)
            {
                std::cout << "There is a piece in the way" << std::endl;
                return false;
            }
        }
    }

    // Check if the bishop is moving to the right and down
    else if (xDifference > 0 && yDifference < 0)
    {
        for (int i = 1; i < xDifference; i++)
        {
            if (board.getPiece(std::make_pair(xInitial + i, yInitial - i)) != nullptr)
            {
                std::cout << "There is a piece in the way" << std::endl;
                return false;
            }
        }
    }

    // Check if the bishop is moving to the left and up
    else if (xDifference < 0 && yDifference > 0)
    {
        for (int i = 1; i < abs(xDifference); i++)
        {
            if (board.getPiece(std::make_pair(xInitial - i, yInitial + i)) != nullptr)
            {
                std::cout << "There is a piece in the way" << std::endl;
                return false;
            }
        }
    }

    // Check if the bishop is moving to the left and down
    else if (xDifference < 0 && yDifference < 0)
    {
        for (int i = 1; i < abs(xDifference); i++)
        {
            if (board.getPiece(std::make_pair(xInitial - i, yInitial - i)) != nullptr)
            {
                std::cout << "There is a piece in the way" << std::endl;
                return false;
            }
        }
    }

    // If the bishop is moving diagonally and there are no pieces in the way, the move is valid
    return true;
}

#endif