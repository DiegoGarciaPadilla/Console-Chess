/**
 * @file Game.cpp
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Implementation of the Game class
 * @version 0.1
 * @date 2023-06-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GAME_CPP
#define GAME_CPP

#include "../headers/Game.h" // Header file
#include "Board.cpp"          // Board class

// Constructor

/**
 * @brief Construct a new Game:: Game object
 * 
 */

Game::Game()
{
    // Initialize board
    board.initializeBoard();

    // Set turn to white
    turn = 0;

    // Initialize captured pieces
    whiteCapturedPieces = {};
    blackCapturedPieces = {};
}

// Destructor

/**
 * @brief Destroy the Game:: Game object
 * 
 */

Game::~Game()
{
    // Delete board
    board.~Board();

    // Delete captured pieces
    for (int i = 0; i < whiteCapturedPieces.size(); i++)
    {
        delete whiteCapturedPieces[i];
    }

    for (int i = 0; i < blackCapturedPieces.size(); i++)
    {
        delete blackCapturedPieces[i];
    }
}

// Getters

/**
 * @brief Get the Turn object
 * 
 * @return int 
 */

int Game::getTurn() { return turn; }

// Setters

/**
 * @brief Set the Turn object
 * 
 * @param newTurn 
 */

void Game::setTurn(int newTurn) { turn = newTurn; }

// Methods

/**
 * @brief Starts a new game
 * 
 */

void Game::newGame()
{
    // Initialize board
    board.initializeBoard();

    // Set turn to white
    turn = 0;

    // Initialize captured pieces
    whiteCapturedPieces = {};
    blackCapturedPieces = {};
}

/**
 * @brief Prints the board
 * 
 */

void Game::printBoard()
{
    // Print turn
    if (turn == 0)
    {
        std::cout << "White's turn" << std::endl;
    }
    else
    {
        std::cout << "Black's turn" << std::endl;
    }

    // Print a message if the player is in check
    if (isCheck(turn))
    {
        std::cout << "You are in check!" << std::endl;
    }
    std::cout << std::endl;

    // Print board
    board.printBoard(turn);
    std::cout << std::endl;

    // Print captured pieces
    std::cout << "Captured pieces : " << std::endl;

    std::cout << "White: ";
    for (int i = 0; i < whiteCapturedPieces.size(); i++)
    {
        std::cout << whiteCapturedPieces[i]->getSymbol() << " ";
    }
    std::cout << std::endl;

    std::cout << "Black: ";
    for (int i = 0; i < blackCapturedPieces.size(); i++)
    {
        std::cout << blackCapturedPieces[i]->getSymbol() << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Move a piece from an initial position to a final position
 *
 * @param initialPosition
 * @param finalPosition
 * @return true
 * @return false
 */

bool Game::movePiece(std::pair<int, int> initialPosition, std::pair<int, int> finalPosition)
{
    // Get row and column of the initial position
    int xInitial = initialPosition.first;
    int yInitial = initialPosition.second;

    // Get row and column of the final position
    int xFinal = finalPosition.first;
    int yFinal = finalPosition.second;

    // Check if the initial position is valid
    if (xInitial < 0 || xInitial > 7 || yInitial < 0 || yInitial > 7)
    {
        std::cout << "Invalid initial position" << std::endl;
        return false;
    }

    // Check if the final position is valid
    if (xFinal < 0 || xFinal > 7 || yFinal < 0 || yFinal > 7)
    {
        std::cout << "Invalid final position" << std::endl;
        return false;
    }

    // Check if the initial position is empty
    if (!board.isOccupied(initialPosition))
    {
        std::cout << "There is no piece in the initial position" << std::endl;
        return false;
    }

    // Check if the initial position is occupied by a piece of the same color
    if (board.getPiece(initialPosition)->getColor() != turn)
    {
        std::cout << "You cannot move a piece of the other color" << std::endl;
        return false;
    }

    // Check if the final position is empty or occupied by an enemy piece
    if (board.isOccupied(finalPosition) && board.getPiece(finalPosition)->getColor() == turn)
    {
        std::cout << "There is a piece of the same color in the final position" << std::endl;
        return false;
    }

    // Check if the piece moves to a different position
    if (xInitial == xFinal && yInitial == yFinal)
    {
        std::cout << "Piece does not move" << std::endl;
        return false;
    }

    // Check if the piece can move to the final position
    if (!board.getPiece(initialPosition)->isValidMove(finalPosition, board))
    {
        std::cout << "Piece cannot move to the final position" << std::endl;
        return false;
    }

    // Check if there is a King in the final position
    if (board.isOccupied(finalPosition) && board.getPiece(finalPosition)->getName() == "King")
    {
        std::cout << "King cannot be captured" << std::endl;
        return false;
    }

    // If the final position is occupied by an enemy piece, capture it
    if (board.isOccupied(finalPosition) && board.getPiece(finalPosition)->getColor() != turn)
    {
        capturePiece(finalPosition);
    }

    // Check if the move puts the player in check
    if (isCheckAfterMove(initialPosition, finalPosition))
    {
        std::cout << "You cannot put yourself in check" << std::endl;
        return false;
    }

    // Move piece
    board.movePiece(initialPosition, finalPosition);

    // Change turn
    turn = (turn + 1) % 2;

    // Return true
    return true;
}

/**
 * @brief Captures a piece
 * 
 * @param position 
 * @return true
 * @return false
 */

bool Game::capturePiece(std::pair<int, int> position)
{
    // Get row and column of the position
    int x = position.first;
    int y = position.second;

    // We assume that the position is valid and that there is a piece in the position

    // Add the piece to the captured pieces
    if (turn == 0)
    {
        whiteCapturedPieces.push_back(board.getPiece(position));
    }

    else
    {
        blackCapturedPieces.push_back(board.getPiece(position));
    }

    return true;
}

/**
 * @brief Checks if the player is in check
 * 
 * @return true 
 * @return false 
 */

bool Game::isCheck(int turn)
{
    // Get the position of the King
    std::pair<int, int> kingPosition = board.getKingPosition(turn);

    // Check if the King is in check
    return board.isAttacked(turn, kingPosition);
}

/**
 * @brief Checks if the move puts the player in check
 * 
 * @param initialPosition
 * @param finalPosition
 * @return true 
 * @return false 
 */

bool Game::isCheckAfterMove(std::pair<int, int> initialPosition, std::pair<int, int> finalPosition)
{
    // Get the color of the piece
    int color = this->board.getPiece(initialPosition)->getColor();

    // Move the piece
    board.movePiece(initialPosition, finalPosition);

    // Check if the King is in check
    bool check = isCheck(color);

    // Undo the move
    board.undoMove(initialPosition, finalPosition);

    // Return the result
    return check;
}


#endif