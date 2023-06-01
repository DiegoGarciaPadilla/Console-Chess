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

    std::string name = ""; // Name of the piece
    std::string symbol = ""; // Symbol to print on the board

    std::pair<int, int> position;   // (x, y)
    bool isCaptured = false;   // true = captured, false = not captured

public:
    // Constructor
    Piece();
    Piece(int color, std::pair<int, int> position);

    // Getters
    int getColor();
    std::string getName();
    std::string getSymbol();
    std::pair<int, int> getPosition();
    bool getIsCaptured();

    // Setters
    void setColor(int color);
    void setName(std::string name);
    void setSymbol(std::string symbol);
    void setPosition(std::pair<int, int> position);
    void setIsCaptured(bool isCaptured);

    // Methods
    virtual bool isValidMove(std::pair<int, int> positionToMove);
    bool move(std::pair<int, int> position);
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
 * @brief Set the Color object
 * 
 * @param color 
 */

void Piece::setColor(int color)
{
    this->color = color;
}

/**
 * @brief Set the Name object
 * 
 * @param name  
 */

void Piece::setName(std::string name)
{
    this->name = name;
}

/**
 * @brief Set the Symbol object
 * 
 * @param symbol 
 */

void Piece::setSymbol(std::string symbol)
{
    this->symbol = symbol;
}

/**
 * @brief Set the Position object
 * 
 * @param position 
 */

void Piece::setPosition(std::pair<int, int> position)
{
    this->position = position;
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
 * @brief Move the piece to the new position
 * 
 * @param position 
 * @return true 
 * @return false 
 */

bool Piece::move(std::pair<int, int> position)
{
    if (isValidMove(position))
    {
        this->position = position;
        return true;
    }
    else
    {
        return false;
    }
}

#endif