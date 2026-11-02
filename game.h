#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

#include <iostream>
#include <sstream>
#include <string>

class Game {
public:
    Game()
        : players_{Player("Player 1", 'X'), Player("Player 2", 'O')} {}

    int run() {
        std::cout << "Tic-Tac-Toe\n";
        std::cout << "Choose a square by entering its number (1-9).\n\n";

        do {
            if (!playRound()) {
                return 0;
            }
        } while (playAgain());

        std::cout << "Thanks for playing!\n";
        return 0;
    }

private:
    bool playRound() {
        board_.reset();
        int currentPlayer = 0;

        while (true) {
            board_.display();
            const Player& player = players_[currentPlayer];
            std::cout << player.name() << " (" << player.symbol()
                      << "), choose a square: ";

            int square = 0;
            if (!readSquare(square)) {
                return false;
            }
            if (!board_.place(square, player.symbol())) {
                std::cout << "That square is already taken. Try again.\n\n";
                continue;
            }

            if (board_.hasWinner(player.symbol())) {
                board_.display();
                std::cout << player.name() << " (" << player.symbol()
                          << ") wins!\n\n";
                return true;
            }
            if (board_.isFull()) {
                board_.display();
                std::cout << "It's a draw!\n\n";
                return true;
            }

            currentPlayer = 1 - currentPlayer;
        }
    }

    bool readSquare(int& square) const {
        while (true) {
            std::string line;
            if (!std::getline(std::cin, line)) {
                return false;
            }

            std::istringstream input(line);
            char extra = '\0';
            if (input >> square && !(input >> extra) &&
                square >= 1 && square <= 9) {
                return true;
            }
            std::cout << "Please enter one number from 1 to 9.\n\n";
        }
    }

    bool playAgain() const {
        while (true) {
            std::cout << "Play again? (y/n): ";
            std::string line;
            if (!std::getline(std::cin, line)) {
                return false;
            }

            if (line == "y" || line == "Y") {
                std::cout << '\n';
                return true;
            }
            if (line == "n" || line == "N") {
                return false;
            }
            std::cout << "Please enter y or n.\n";
        }
    }

    Board board_;
    Player players_[2];
};

#endif
