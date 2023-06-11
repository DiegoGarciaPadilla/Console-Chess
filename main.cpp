/**
 * @file main.cpp
 * @author Diego Antonio García Padilla (A01710777)
 * @brief Main file for the chess game
 * @version 0.1
 * @date 2023-05-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <utility>

#include "drivers/Game.cpp" // Game class


int main()
{
    // Create Game
    Game game;

    // Play game
    game.playGame();

    return 0;
}