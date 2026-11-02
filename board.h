#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <iostream>

class Board {
public:
    Board() {
        reset();
    }

    void reset() {
        cells_.fill(' ');
    }

    void display(std::ostream& output = std::cout) const {
        for (int row = 0; row < 3; ++row) {
            for (int column = 0; column < 3; ++column) {
                const int index = row * 3 + column;
                const char square = cells_[index] == ' '
                    ? static_cast<char>('1' + index)
                    : cells_[index];

                output << ' ' << square << ' ';
                if (column < 2) {
                    output << '|';
                }
            }
            output << '\n';
            if (row < 2) {
                output << "---+---+---\n";
            }
        }
    }

    bool place(int square, char symbol) {
        if (square < 1 || square > 9 || cells_[square - 1] != ' ') {
            return false;
        }

        cells_[square - 1] = symbol;
        return true;
    }

    bool hasWinner(char symbol) const {
        static const int winningLines[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
            {0, 4, 8}, {2, 4, 6}
        };

        for (int line = 0; line < 8; ++line) {
            if (cells_[winningLines[line][0]] == symbol &&
                cells_[winningLines[line][1]] == symbol &&
                cells_[winningLines[line][2]] == symbol) {
                return true;
            }
        }
        return false;
    }

    bool isFull() const {
        for (std::size_t index = 0; index < cells_.size(); ++index) {
            if (cells_[index] == ' ') {
                return false;
            }
        }
        return true;
    }

private:
    std::array<char, 9> cells_;
};

#endif
