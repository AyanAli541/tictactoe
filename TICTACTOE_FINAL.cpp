
#include <SFML/Graphics.hpp>
const int CELL_SIZE = 180; // size of one square
const int BOARD_TOP = 80; // space above the board
char board[3][3]; // 'X', 'O' or ' ' (empty)
int gameState = 0; // 0 = playing, 1 = player wins, 2 = computer wins, 3 = draw
int moveRow = 0; 
int moveCol = 0;
sf::RenderWindow window(sf::VideoMode(540, 760), "Tic-Tac-Toe", sf::Style::Close);
sf::Font font;

void resetBoard()
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			board[r][c] = ' ';
		}
	}
	gameState = 0;
}

char checkWinner()
{
	
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}
	
	if (board[1][1] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[1][1];
	if (board[1][1] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[1][1];
	
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (board[r][c] == ' ')
				return ' ';
		}
	}
	return 'D'; 
}
int findWinningMove(char who)
{

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (board[r][c] == ' ')
			{
				board[r][c] = who; // try the move
				char result = checkWinner();
				board[r][c] = ' '; // undo the move
				if (result == who)
				{
					moveRow = r;
					moveCol = c;
					return 1;
				}
			}
		}
	}
	return 0;
}

void computerMove()
{
	if (findWinningMove('O') == 1)
	{
		board[moveRow][moveCol] = 'O';
	}
	else if (findWinningMove('X') == 1)
	{
		board[moveRow][moveCol] = 'O';
	}
	else if (board[1][1] == ' ')
	{
		board[1][1] = 'O';
	}
	else
	{
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				if (board[r][c] == ' ')
				{
					board[r][c] = 'O';
					return;
				}
			}
		}
	}
}
void checkResult()
{
	char result = checkWinner();
	if (result == 'X')
		gameState = 1;
	else if (result == 'O')
		gameState = 2;
	else if (result == 'D')
		gameState = 3;
}



void drawGrid()
{
	for (int i = 1; i < 3; i++)
	{
		sf::RectangleShape vLine(sf::Vector2f(6, 540));
		vLine.setPosition(i * CELL_SIZE - 3, BOARD_TOP);
		vLine.setFillColor(sf::Color(90, 90, 110));
		window.draw(vLine);
		sf::RectangleShape hLine(sf::Vector2f(540, 6));
		hLine.setPosition(0, BOARD_TOP + i * CELL_SIZE - 3);
		hLine.setFillColor(sf::Color(90, 90, 110));
		window.draw(hLine);
	}
}

void drawX(float cx, float cy)
{
	sf::Text text("X", font, 120);
	text.setFillColor(sf::Color(52, 152, 219));
	text.setPosition(cx - 40, cy - 85);
	window.draw(text);
}

void drawO(float cx, float cy)
{
	sf::Text text("O", font, 120);
	text.setFillColor(sf::Color(231, 76, 60));
	text.setPosition(cx - 47, cy - 85);
	window.draw(text);
}

void drawMarks()
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			float cx = c * CELL_SIZE + 90;
			float cy = BOARD_TOP + r * CELL_SIZE + 90;
			if (board[r][c] == 'X')
				drawX(cx, cy);
			else if (board[r][c] == 'O')
				drawO(cx, cy);
		}
	}
}

void drawTexts()
{
	sf::Text title("Tic-Tac-Toe", font, 38);
	title.setPosition(150, 18);
	window.draw(title);
	sf::Text message;
	message.setFont(font);
	message.setCharacterSize(34);
	message.setPosition(140, 632);
	if (gameState == 0)
		message.setString("Your turn (X)");

	else if (gameState == 1)
		message.setString("You Win!");
	else if (gameState == 2)
		message.setString("Computer Wins!");
	else
		message.setString("It's a Draw!");
	window.draw(message);
}

void drawButton()
{
	sf::RectangleShape button(sf::Vector2f(200, 50));
	button.setPosition(170, 690);
	button.setFillColor(sf::Color(46, 204, 113));
	window.draw(button);
	sf::Text buttonText("Restart", font, 26);
	buttonText.setPosition(235, 697);
	window.draw(buttonText);
}

int main()
{
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	resetBoard();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				int mx = event.mouseButton.x;
				int my = event.mouseButton.y;
				// click on the restart button
				if (mx >= 170 && mx <= 370 && my >= 690 && my <= 740)
				{
					resetBoard();
				}
				// click on the board (only while the game is running)
				else if (gameState == 0 && my >= BOARD_TOP && my < BOARD_TOP + 540)
				{
					int col = mx / CELL_SIZE;
					int row = (my - BOARD_TOP) / CELL_SIZE;
					if (board[row][col] == ' ')
					{
						board[row][col] = 'X'; // player move
						checkResult();
						if (gameState == 0)
						{
							computerMove();
							checkResult();
						}
					}
				}

			}
		}
		window.clear(sf::Color(30, 30, 40));
		drawGrid();
		drawMarks();
		drawTexts();
		drawButton();
		window.display();
	}
	return 0;
}