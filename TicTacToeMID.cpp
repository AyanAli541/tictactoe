
#include <SFML/Graphics.hpp>
const int CELL_SIZE = 180;   
const int BOARD_TOP = 80;      
char board[3][3];              
sf::RenderWindow window(sf::VideoMode(540, 760), "Tic-Tac-Toe", sf::Style::Close);

void resetBoard()
{
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            board[r][c] = ' ';
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
// Drawing X using 2 crossed bars
void drawX(float cx, float cy)
{
    sf::RectangleShape bar1(sf::Vector2f(120, 14));
    bar1.setOrigin(60, 7);
    bar1.setPosition(cx, cy);
    bar1.setRotation(45);
    bar1.setFillColor(sf::Color(52, 152, 219));
    window.draw(bar1);
    sf::RectangleShape bar2(sf::Vector2f(120, 14));
    bar2.setOrigin(60, 7);
    bar2.setPosition(cx, cy);
    bar2.setRotation(-45);
    bar2.setFillColor(sf::Color(52, 152, 219));
    window.draw(bar2);
}
int main()
{
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
                if (my >= BOARD_TOP && my < BOARD_TOP + 540)
                {
                    int col = mx / CELL_SIZE;
                    int row = (my - BOARD_TOP) / CELL_SIZE;
                    if (board[row][col] == ' ')
                        board[row][col] = 'X';
                }
            }
        }
        window.clear(sf::Color(30, 30, 40));
        drawGrid();
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                if (board[r][c] == 'X')
                    drawX(c * CELL_SIZE + 90, BOARD_TOP + r * CELL_SIZE + 90);
        window.display();
    }
    return 0;
}