#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(const std::string& name, char symbol)
        : name_(name), symbol_(symbol) {}

    const std::string& name() const {
        return name_;
    }

    char symbol() const {
        return symbol_;
    }

private:
    std::string name_;
    char symbol_;
};

#endif
