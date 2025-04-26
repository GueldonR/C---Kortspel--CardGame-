# Gueldon's Card Game

Gueldon's Card Game is a simple two-player card game implemented in C++. Players take turns drawing cards, and the winner is determined based on the card's value and suit. The game keeps track of wins and losses for each player.

## Features

- Two-player gameplay.
- Randomized card drawing.
- Scoring based on card value and suit.
- Win-loss tracking across multiple games.
- User-friendly prompts and instructions.

## How to Play

1. Run the program.
2. Enter the names of the two players.
3. Follow the on-screen instructions:
   - Player 1 presses `1` to draw a card.
   - Player 2 presses `2` to draw a card.
   - Press `4` to reveal the results of the round.
4. The game continues until one player reaches the winning score (default: 2 points).
5. After the game ends, you can choose to play again or exit.
6. A win-loss table is displayed at the end of the session.

## Requirements

- A C++ compiler (e.g., GCC, Clang, or MSVC).
- C++11 or later.

## How to Compile and Run

1. Open a terminal or command prompt.
2. Navigate to the directory containing `Kortspel.cpp`.
3. Compile the program using a C++ compiler. For example:
   ```sh
   g++ -o kortspel Kortspel.cpp
