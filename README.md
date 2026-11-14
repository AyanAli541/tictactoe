# tictactoe
used SFML

Programming Fundamentals Project 

Group Members
Syed Ayan Ali Jaffery (26L-0814)
M Fahad (26L-0764)

## About
This is a GUI Tic-Tac-Toe game where the player (X) plays against the computer (O). Built in C++ with SFML 2.6.x in Visual Studio.

## Setup
1. Download SFML 2.6.x. 
2. Create an Empty C++ Project
3. Additional Include Directories: `C:\SFML\SFML-2.6.1\include`
5. Additional Library Directories: `C:\SFML\SFML-2.6.1\lib`
6. linked the code with sfml, for GUI.
7. Additional Dependencies: `sfml-graphics-d.lib; sfml-window-d.lib; sfml-system-d.lib`
8. Copy the three `-d-2.dll` files from `SFML\bin` into `x64\Debug`.
9. Run the code

## Done So Far 
A 540 x 760 game window is created
Board stored in `char board[3][3]` 
'X' = player and 'O' = computer while ' ' = empty
`resetBoard()` clears the board
`drawGrid()` draws the 3x3 grid
`drawX()` draws an X
 Left click places an X on an empty square

## Still To Do
Draw the computer's O
Computer moves (win, block, center, first empty square)
Win, loss, and draw checking with an on screen message
Restart button
