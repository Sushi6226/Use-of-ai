# Use-of-ai
using ai
test 




← Conceptual Quiz 14: Review
·
Part of CIS-25 Fall 2026
← Modules
Review
Answers are saved to this course version. Original saved answers and files remain preserved.

Download these answers
cis-25-quiz
1. A thermostat (2 points)
Consider this program.

#include <iostream>

class Thermostat {
private:
    int target;
public:
    Thermostat(int start) : target(start) {}
    void raise() { target = target + 1; }
    int getTarget() const { return target; }
};

void show(const Thermostat& t) {
    t.raise();
    std::cout << t.getTarget() << '\n';
}

int main() {
    Thermostat hall(68);
    show(hall);
    return 0;
}
✗ Try again
What happens when this program is compiled and run?
0 / 2 points

It prints 69: raise changes hall through the reference, and then getTarget reads the new target.

It prints 68: a change made through a const reference is undone when show returns.

It doesn't compile: t is a const reference, and raise isn't a const member function, so it can't be called through t.

It doesn't compile: getTarget is declared const, so it can't be called after raise has changed the target.

It doesn't compile: a const reference parameter can't refer to hall, because hall itself isn't const.
2. Turnstiles (2 points)
Parts (a) and (b) use this class and these two functions.

class Turnstile {
private:
    static int total;
    int entries;
public:
    Turnstile() : entries(0) {}
    void admit(int people) {
        entries = entries + people;
        total = total + people;
    }
    int getEntries() const { return entries; }
    int getTotal() const { return total; }
};

int Turnstile::total = 0;

void openGate(Turnstile& gate, int people) {
    gate.admit(people);
}

void testGate(Turnstile gate, int people) {
    gate.admit(people);
}
✗ Try again
(a) main creates two Turnstile objects, north and south. Then it calls openGate(north, 5), openGate(south, 3), and testGate(north, 4), in that order. What does north.getEntries() return now?
0 / 1 points
13
✗ Try again
(b) After those three calls, what does south.getTotal() return?
0 / 1 points
6
3. Instruments (2 points)
Consider this program.

#include <iostream>
#include <string>

class Instrument {
private:
    std::string name;
public:
    Instrument(std::string instrumentName) : name(instrumentName) {}
    std::string getName() const { return name; }
};

class Guitar : public Instrument {
private:
    int strings;
public:
    Guitar(std::string guitarName, int stringCount) : strings(stringCount) {
        std::cout << "Tuning " << guitarName << '\n';
    }
    int getStrings() const { return strings; }
};

int main() {
    Guitar bass("Bass", 4);
    std::cout << bass.getName() << " has " << bass.getStrings() << " strings\n";
    return 0;
}
✗ Try again
What happens when this program is compiled and run?
0 / 2 points

It compiles and prints Tuning Bass, then Bass has 4 strings: the guitarName parameter fills in the inherited name.

It doesn't compile: the Instrument part must be constructed before the Guitar constructor's body runs, and Instrument has no constructor that takes no arguments.

It compiles, but bass's name is empty, because nothing gave the Instrument part a name.

It doesn't compile: name is private in Instrument, so a Guitar object can't use getName.
4. Choosing a value (3 points)
Consider these two functions. main calls adjust once, with the values given.

#include <iostream>

void pick(int* chosen, int* other) {
    chosen = other;
    *chosen = *chosen + 1;
}

void adjust(int a, int b) {
    int* selected = &a;
    pick(selected, &b);
    *selected = *selected * 2;
    std::cout << a << '\n';
}
✗ Try again
main calls adjust(6, 11). What number does it print?
0 / 3 points
173
5. Lap times (2 points)
Consider this program.

#include <iostream>

int* makeLaps(int count) {
    int* laps = new int[count];
    for (int i = 0; i < count; ++i) {
        laps[i] = 60 - i;
    }
    return laps;
}

int fastest(int* laps, int count) {
    int best = laps[0];
    for (int i = 1; i < count; ++i) {
        if (laps[i] < best) {
            best = laps[i];
        }
    }
    delete[] laps;
    return best;
}

int main() {
    int* race = makeLaps(5);
    std::cout << fastest(race, 5) << '\n';
    std::cout << race[0] << '\n';
    delete[] race;
    return 0;
}
✗ Try again
What's wrong with this program?
0 / 2 points

Nothing: fastest gets its own copy of the array, so deleting it there doesn't affect main.

It leaks memory: the array that makeLaps creates is never released.

makeLaps returns the address of a local variable, so race is dangling as soon as makeLaps returns.

After fastest returns, main reads from an array that has already been released, and then releases that same array a second time.

It doesn't compile: only the function that created an array with new can delete it.
6. Copying an array (2 points)
Consider this function. main calls trial once, with the values given.

#include <iostream>

void trial(int start, int change) {
    int* prices = new int[3];
    for (int i = 0; i < 3; ++i) {
        prices[i] = start + i;
    }

    int* alias = prices;
    int* backup = new int[3];
    for (int i = 0; i < 3; ++i) {
        backup[i] = prices[i];
    }

    alias[0] = alias[0] + change;
    backup[0] = backup[0] * 2;
    std::cout << prices[0] << '\n';

    delete[] backup;
    delete[] prices;
}
✗ Try again
main calls trial(18, 6). What number does it print?
0 / 2 points
36
7. Growing an array (2 points)
Consider this code. seats points to a dynamic array holding count seat numbers, with no free slots. larger points to a new array with 10 more slots, and the seat numbers have already been copied into it. These two lines are meant to finish moving the seat numbers into the larger array.

seats = larger;
delete[] seats;
✗ Try again
What's wrong with this code?
0 / 2 points

It releases the larger array that was just filled, so seats and larger are both left dangling, and the old array can never be released.

Nothing: the old array is released, and seats now points to the larger array.

It never releases the old array, but seats still points to a usable array holding every seat number.

It doesn't compile: seats can't point to an array of a different size from the one it pointed to before.
8. A string of beads (2 points)
Consider this struct and function.

struct Bead {
    int size;
    Bead* next;
};

Bead* build(int count) {
    Bead* first = nullptr;
    for (int size = 1; size <= count; ++size) {
        Bead* bead = new Bead;
        bead->size = size;
        bead->next = first;
        first = bead;
    }
    return first;
}
Numeric answer
main calls build(11), then prints each bead's size, starting from the bead that build returns and following next until it reaches nullptr. What number is printed in position 4? The first number printed is in position 1.
2 points
Enter a number
9. Reaching a value in a stack (2 points)
A stack starts out empty.

✗ Try again
You push the numbers 1, 2, 3, and so on up to 8 onto the stack, in that order. What is the minimum number of pop operations needed to get 2 out of the stack?
0 / 2 points
4
10. Printing before and after a call (3 points)
Parts (a) and (b) use this function. main calls echo once, with the value given.

#include <iostream>

void echo(int n) {
    if (n <= 0) {
        std::cout << "* ";
        return;
    }
    std::cout << n << " ";
    echo(n - 3);
    std::cout << n << " ";
}
✗ Try again
(a) main calls echo(13). How many numbers does it print? Don't count the *.
0 / 2 points
9
✗ Try again
(b) After the * in the output of echo(13), what number is printed in position 2? The first number after the * is in position 1.
0 / 1 points
12
11. A multiplication table (3 points)
Consider these two functions. makeTable builds a multiplication table with the number of rows and columns it is given.

int** makeTable(int rows, int columns) {
    int** table = new int*[rows];
    for (int row = 0; row < rows; row++) {
        table[row] = new int[columns];
        for (int column = 0; column < columns; column++) {
            table[row][column] = (row + 1) * (column + 1);
        }
    }
    return table;
}

void freeTable(int** table) {
    delete[] table;
}
✗ Try again
main calls makeTable(3, 5), uses the table, and then passes it to freeTable. After freeTable returns, how many of the ints that makeTable created have not been released?
0 / 3 points
8
Instructor feedback
No instructor feedback yet.

✓
Submitted for grading
Last submitted Nov 2, 2026, 9:58 AM PST. Score: 0 / 25 (0%) This quiz allows one conceptual submission per quiz session.
Submission recorded