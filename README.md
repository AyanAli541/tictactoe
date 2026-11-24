# tictactoe

Programming Fundamentals Project 

Group Members
Syed Ayan Ali Jaffery (26L-0814)

M Fahad (26L-0764)

## About
Made a TicTacToe game based on GUI where the player (X) plays against the computer (O). Built in C++ with SFML 2.6.2 in Visual Studio 2026

## Setup
1. Download SFML 2.6.2 
2. Create an Empty C++ Project
3. Additional Include Directories: `C:\SFML\SFML-2.6.2\include`
5. Additional Library Directories: `C:\SFML\SFML-2.6.2\lib`
6. linked the code with sfml, for GUI.
7. Additional Dependencies: `sfml-graphics-d.lib; sfml-window-d.lib; sfml-system-d.lib`
8. Copy the three `-d-2.dll` files from `SFML\bin` into `x64\Debug`.
9. Run the code

## Features 
A 540 x 760 game window is created

Board stored in `char board[3][3]` 

'X' = player and 'O' = computer while ' ' = empty

Computer moves (win, block, center, first empty square)

Win, loss, and draw checking with an on screen message

Restart button

`resetBoard()` clears the board

`drawGrid()` draws the 3x3 grid

`drawX()` draws an X

`checkWinner()` checks for winner in all ways

`findWinningMove()` checks if the player can win with one move

`computerMove()` choose the computer move

`drawTexts()` draw the title and message

`drawButton()` Draw the restart button

 Left click places an X on an empty square

## Prerequisites
Windows (x64) 

Visual Studio 2026 

SFML 2.6.2

## How to Play
Click an empty square to place X. 

The computer plays O automatically. 

Click Restart to play again.

## Screenshots
Draw
<img width="1600" height="1171" alt="image" src="https://github.com/user-attachments/assets/1171cdbe-2ad1-4be4-837d-627d3593fb86" />


Win
<img width="1600" height="979" alt="image" src="https://github.com/user-attachments/assets/55499687-ec2e-4f4a-b9c1-8edf70cac3c3" />


