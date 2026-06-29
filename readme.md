# RPG Battle System

A simple RPG battle system written in C++ demonstrating core OOP concepts.

## Features
- Character base class with polymorphism
- Warrior class with armor and bonus damage
- Mage class with mana and magic shield
- Turn-based battle system
- Memory management with unique_ptr
- Game loop/update pattern
- Leaderboard integration - winner saved with remaining HP as score

## Concepts Covered
- Inheritance
- Polymorphism
- Encapsulation
- Virtual functions
- Virtual destructor
- Smart pointers (unique_ptr)
- Update pattern
- Composition (Leaderboard has Players)
- STL sort with lambda
- File I/O (save/load leaderboard)

## How to Run
g++ main.cpp Character.cpp Warrior.cpp Mage.cpp Player.cpp Leaderboard.cpp -o main
./main.exe

## Classes
- `Character` — base class
- `Warrior` — melee fighter with armor
- `Mage` — spell caster with mana and magic shield
- `Player` — stores winner name and score
- `Leaderboard` — manages results, sorting and file persistence