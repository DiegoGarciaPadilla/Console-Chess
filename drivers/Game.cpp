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
#include "Board.cpp"         // Board class

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
 * @brief Plays a game
 *
 */

void Game::playGame()
{
    // Clear screen
    clearScreen();

    // Initialize variables
    int xInitial, yInitial, xFinal, yFinal;

    // Initialize pair of positions
    std::pair<int, int> initialPosition;
    std::pair<int, int> finalPosition;

    // Start game
    while (!isCheckmate(turn) && !isStalemate(turn))
    {
        // Print board
        printBoard();

        // Get initial position
        std::cout << "Initial position: " << std::endl;
        std::cout << "Row: ";
        std::cin >> xInitial;
        std::cout << "Column: ";
        std::cin >> yInitial;
        std::cout << std::endl;

        // Get final position
        std::cout << "Final position: " << std::endl;
        std::cout << "Row: ";
        std::cin >> xFinal;
        std::cout << "Column: ";
        std::cin >> yFinal;
        std::cout << std::endl;

        // Set initial position
        initialPosition = std::make_pair(xInitial, yInitial);

        // Set final position
        finalPosition = std::make_pair(xFinal, yFinal);

        // Move piece
        if (!movePiece(initialPosition, finalPosition))
        {
            std::cout << "Press enter to continue...";
            std::cin.get();
            std::cin.get();
        }

        // Clear screen
        clearScreen();
        
    }

    // Print winner
    if (!isCheckmate(turn))
    {
        std::cout << "Stalemate!" << std::endl;
    }
    else
    {
        if (turn == 0)
        {
            std::cout << "Black wins!" << std::endl;
        }
        else
        {
            std::cout << "White wins!" << std::endl;
        }
    }
    std::cout << std::endl;

    // Print board
    board.printBoard(turn);
    std::cout << std::endl;

    // Print captured pieces
    printCapturedPieces();
    std::cout << std::endl;

    // Pause
    std::cout << "Press enter to continue...";
    std::cin.get();
    std::cin.get();

    // Destroy game
    this->~Game();
}

/**
 * @brief Print the board
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
    printCapturedPieces();
    std::cout << std::endl;

    std::cout << std::endl;
}

/**
 * @brief Print the pieces captured by the players
 *
 */

void Game::printCapturedPieces()
{
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
}

/**
 * @brief Clear screen
 * 
 */

void Game::clearScreen()
{
    // Check OS
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #elif __APPLE__
        system("clear");
    #else
        std::cout << "\033[2J\033[1;1H";
    #error "OS not supported!"
    #endif  
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
        std::cout << "The " << board.getPiece(initialPosition)->getName() << " cannot move to the final position" << std::endl;
        return false;
    }

    // Check if there is a King in the final position
    if (board.isOccupied(finalPosition) && board.getPiece(finalPosition)->getName() == "King")
    {
        std::cout << "King cannot be captured" << std::endl;
        return false;
    }

    // Check if the move puts the player in check
    if (isCheckAfterMove(initialPosition, finalPosition))
    {
        std::cout << "You cannot put yourself in check" << std::endl;
        return false;
    }

    // If the final position is occupied by an enemy piece, capture it
    if (board.isOccupied(finalPosition) && board.getPiece(finalPosition)->getColor() != turn)
    {
        capturePiece(finalPosition);
    }

    // Move piece
    board.movePiece(initialPosition, finalPosition);
    board.getPiece(finalPosition)->setHasMoved(true);
    board.setLastMove(initialPosition, finalPosition);

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
    // Check if the King is in check
    return board.isCheck(turn);
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
    // Initialize variables
    Board dummyBoard(board);
    std::pair<int, int> kingPosition;
    bool isCheck = false;

    // Move piece
    dummyBoard.movePiece(initialPosition, finalPosition);

    // Return true if the King is in check
    isCheck = dummyBoard.isCheck(turn);

    // Delete dummyBoard
    dummyBoard.~Board();

    return isCheck;

}

/**
 * @brief Checks if the player is in checkmate
 *
 * @return true
 * @return false
 */

bool Game::isCheckmate(int turn)
{
    // Initialize variables
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> possibleMoves;
    bool isCheckmate = true;

    // Check if the player is in check
    if (!isCheck(turn))
    {
        return false;
    }

    // Get all the possible moves for the player
    possibleMoves = board.getAllPossibleMoves(turn);

    // Check if any of the possible moves puts the player out of check
    for (int i = 0; i < possibleMoves.size(); i++)
    {
        // Get the initial and final positions of the move
        std::pair<int, int> initialPosition = possibleMoves[i].first;
        std::pair<int, int> finalPosition = possibleMoves[i].second;

        // Check if the move puts the player out of check
        if (!isCheckAfterMove(initialPosition, finalPosition))
        {
            isCheckmate = false;
            break;
        }
    }

    // Else, the player is in checkmate
    return isCheckmate;
}

/**
 * @brief Checks if the player is in stalemate
 *
 * @return true
 * @return false
 */

bool Game::isStalemate(int turn)
{
    // Initialize variables
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> possibleMoves;
    bool isStalemate = true;

    // Check if the player is in check, if so, it is not a stalemate
    if (isCheck(turn))
    {
        return false;
    }

    // Get all the possible moves for the player
    possibleMoves = board.getAllPossibleMoves(turn);

    // Check if there are any possible moves
    if (possibleMoves.size() > 0)
    {
        isStalemate = false;
    }

    // Else, the player is in checkmate
    return isStalemate;
}

#endif