#include "Player.h"

Player::Player():
figure(sf::Vector2f(70, 70))
{
}

sf::RectangleShape Player::getFigure(const int& i, const int& j)
{
	figure.setPosition(sf::Vector2f(115 + 105 * i, 35 + 105 * j));
	return figure;
}



PlayerGreen::PlayerGreen()
{
	figure.setFillColor(sf::Color::Green);
}

virtual bool PlayerGreen::checkWin(int board[3][3])
{
	if(((board[0][0] == 1) && (board[0][1] == 1) && (board[0][2] == 1)) ||
	   ((board[1][0] == 1) && (board[1][1] == 1) && (board[1][2] == 1)) ||
	   ((board[2][0] == 1) && (board[2][1] == 1) && (board[2][2] == 1)) ||
	   ((board[0][0] == 1) && (board[1][0] == 1) && (board[2][0] == 1)) ||
	   ((board[0][1] == 1) && (board[1][1] == 1) && (board[2][1] == 1)) ||
	   ((board[0][2] == 1) && (board[1][2] == 1) && (board[2][2] == 1)) ||
	   ((board[0][0] == 1) && (board[1][1] == 1) && (board[2][2] == 1)) ||
	   ((board[2][0] == 1) && (board[1][1] == 1) && (board[0][2] == 1)))
	{
		return true;
	}
	else
		return false;
}



PlayerBlue::PlayerBlue()
{
	figure.setFillColor(sf::Color::Blue);
}

virtual bool PlayerBlue::checkWin(int board[3][3])
{
	if(((board[0][0] == 2) && (board[0][1] == 2) && (board[0][2] == 2)) ||
	   ((board[1][0] == 2) && (board[1][1] == 2) && (board[1][2] == 2)) ||
	   ((board[2][0] == 2) && (board[2][1] == 2) && (board[2][2] == 2)) ||
	   ((board[0][0] == 2) && (board[1][0] == 2) && (board[2][0] == 2)) ||
	   ((board[0][1] == 2) && (board[1][1] == 2) && (board[2][1] == 2)) ||
	   ((board[0][2] == 2) && (board[1][2] == 2) && (board[2][2] == 2)) ||
	   ((board[0][0] == 2) && (board[1][1] == 2) && (board[2][2] == 2)) ||
	   ((board[2][0] == 2) && (board[1][1] == 2) && (board[0][2] == 2)))
	{
		return true;
	}
	else
		return false;
}