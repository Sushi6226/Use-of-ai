# Terminal Tic-Tac-Toe

A two-player Tic-Tac-Toe game that runs in your terminal. Player 1 uses **X**
and Player 2 uses **O**.

## Build and run

```sh
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp -o tic-tac-toe
./tic-tac-toe
```

Choose squares by entering the number shown on the board:

```text
 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9
```

The game rejects invalid or occupied squares without changing turns, announces
a win or draw, and offers to start another round.
