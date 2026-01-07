# ROCK-PAPER-SCISSORS
OOP LAP PROJECT(ROCK-PAPER_SCISSORS GAME)
# Rock Paper Scissors Game

## Problem Statement
This is a simple console-based game where a player competes with the computer.  
The game keeps track of the player's score and saves the results of each round in a file.  
Players can also view the history of previous games.

## OOP Concepts Used
- **Classes & Objects** – Player and GamePlayer classes  
- **Encapsulation** – Private and protected data members, public functions  
- **Inheritance** – GamePlayer class inherits from Player class  
- **Polymorphism** – Virtual functions and pointers to base class  
- **Function Overloading** – `updateScore()` function has two versions  
- **Function Overriding** – `displayDetails()` in GamePlayer overrides base class function  
- **Operator Overloading** – `+` operator is overloaded to sum scores  
- **File Handling** – Game results are saved in `game_results.txt`  
- **Exception Handling** – Handles file errors while saving or reading history  

## Class Structure
- **Player (Base Class)**  
  - Stores player name and score  
  - Virtual function `displayDetails()`  
- **GamePlayer (Derived Class)**  
  - Stores player choice (rock/paper/scissors)  
  - Functions to input details, make choice, update score, display details  
  - Overloaded `updateScore()` and `+` operator  
  - Function to save game result to file  

## Program Flow
1. Player enters their name  
2. Player chooses **rock, paper, or scissors**  
3. Computer randomly selects a choice  
4. Winner is decided based on game rules  
5. Player’s score is updated  
6. Game result is saved to `game_results.txt`  
7. Player can view all previous game results from the file  

## How to Run
1. Open your terminal or IDE  
2. Compile the program:  
   ```bash
   g++ main.cpp -o game

