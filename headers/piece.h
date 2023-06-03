/**
 * @file Piece.h
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Definition of the Piece class
 * @version 0.1
 * @date 2023-05-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <utility>
#include <string>

class Piece
{
protected:
    // Attributes
    int color; // 0 = white, 1 = black

    std::string name = " ";   // Name of the piece
    std::string symbol = " "; // Symbol to print on the board

    std::pair<int, int> position; // (x, y)
    bool isCaptured = false;      // true = captured, false = not captured

public:
    // Constructor
    Piece();
    Piece(int color, std::pair<int, int> position);

    // Getters (the getters are virtual because they are overriden in the subclasses)
    virtual std::string getName();
    virtual int getColor();
    virtual std::string getSymbol();
    virtual std::pair<int, int> getPosition();
    virtual bool getIsCaptured();

    // Setters (the setters are virtual because they are overriden in the subclasses)
    virtual void setPosition(std::pair<int, int> position);
    virtual void setIsCaptured(bool isCaptured);

    // Methods (the methods are virtual because they are overriden in the subclasses)
    virtual bool isValidMove(std::pair<int, int> positionToMove);
    virtual void showPieceInfo();
};

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

int Piece::getColor()
{
    return this->color;
}

/**
 * @brief Get the Name object
 *
 * @return std::string
 */

std::string Piece::getName()
{
    return this->name;
}

/**
 * @brief Get the Symbol object
 *
 * @return std::string
 */

std::string Piece::getSymbol()
{
    return this->symbol;
}

/**
 * @brief Get the Position object
 *
 * @return std::pair<int, int>
 */

std::pair<int, int> Piece::getPosition()
{
    return this->position;
}

/**
 * @brief Get the Is Captured object
 *
 * @return true
 * @return false
 */

bool Piece::getIsCaptured()
{
    return this->isCaptured;
}

// Setters

/**
 * @brief Set the Position object
 *
 * @param position
 */

void Piece::setPosition(std::pair<int, int> position)
{
    this->position = position;
}

/**
 * @brief Set the Is Captured object
 *
 * @param isCaptured
 */

void Piece::setIsCaptured(bool isCaptured)
{
    this->isCaptured = isCaptured;
}

// Methods

/**
 * @brief Check if the move is valid
 *
 * @param position
 * @return true
 * @return false
 */

bool Piece::isValidMove(std::pair<int, int> position)
{
    // This method will be implemented in the child classes by overriding it
    return true;
}

/**
 * @brief Show the piece information
 *
 * @return void
 */

void Piece::showPieceInfo()
{
    std::cout << "Piece: " << name << std::endl;
    std::cout << "Symbol: " << symbol << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Position: (" << position.first << ", " << position.second << ")" << std::endl;
    std::cout << "Is captured: " << isCaptured << std::endl;
}

#endif