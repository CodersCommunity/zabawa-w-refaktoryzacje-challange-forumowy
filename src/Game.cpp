#include "Game.h"

Game::Game():
window(sf::VideoMode(500, 400), "Okno aplikacji"),
messages_text("Komunikaty:"),
player(nullptr),
turn(0),
left_button(false)
{
	window.setFramerateLimit(100);
	loadFont();
	initBoard();
	initLines();
	initAreas();
	initMessages();
	initButton();
}

void Game::mainLoop()
{
	while(window.isOpen())
	{
		events();
		update();
		draw();
	}
}

void Game::loadFont()
{
	if (!font.loadFromFile("DSPLAID.ttf"))
		window.close();
}

void Game::initBoard()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			board[i][j] = 0;
	}
}

void Game::initLines()
{
	for(int i = 0; i < 4; i++)
	{
		lines[i].setSize(sf::Vector2f(310, 5));
		lines[i].setFillColor(sf::Color::White);
	}
	lines[0].setPosition(sf::Vector2f(100, 120));
	lines[1].setPosition(sf::Vector2f(100, 225));
	lines[2].setPosition(sf::Vector2f(205, 20));
	lines[2].rotate(90);
	lines[3].setPosition(sf::Vector2f(310, 20));
	lines[3].rotate(90);
}

void Game::initAreas()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			areas[i][j].left = 100 + 105 * i;
			areas[i][j].top = 20 + 105 * j;
			areas[i][j].width = 100;
			areas[i][j].height = 100;
		}
	}
}

void Game::initMessages()
{
	messages.setFont(font);
	messages.setString(messages_text);
	messages.setCharacterSize(24);
	messages.setPosition(sf::Vector2f(10, 350));
}

void Game::initButton()
{
	button.setSize(sf::Vector2f(90, 30));
	button.setPosition(sf::Vector2f(370, 350));
	button.setFillColor(sf::Color(128, 128, 128));
	button_text.setFont(font);
	button_text.setCharacterSize(24);
	button_text.setString("Od nowa");
	button_text.setPosition(380, 350);
}

void Game::newGame()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			board[i][j] = 0;
	}
	turn = 0;
	messages_text = "Komunikaty:";
	figures.clear();
}

bool Game::checkTie()
{
	int taken = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(board[i][j] != 0)
				taken++;
		}
	}

	if(taken == 9)
		return true;
	else
		return false;
}

void Game::events()
{
	while(window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		left_button = true;
	else
		left_button = false;
}

void Game::update()
{
	if(left_button && button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)))
	{
		newGame();
		messages.setString(messages_text);
	}

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(left_button && areas[i][j].contains(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) && !board[i][j])
			{
				if(turn == 0)
				{
					player = new PlayerGreen;
					board[i][j] = 1;
					figures.push_back(player->getFigure(i, j));
					turn = 1;
					if(player->checkWin(board))
					{
						messages_text += " wygrywa gracz zielony!";
						messages.setString(messages_text);
						for(int i = 0; i < 3; i++)
						{
							for(int j = 0; j < 3; j++)
							{
								if(board[i][j] == 0)
									board[i][j] = 3;
							}
						}
					}
					else if(checkTie())
					{
						messages_text += " remis!";
						messages.setString(messages_text);
					}
				}
				else
				{
					player = new PlayerBlue;
					board[i][j] = 2;
					figures.push_back(player->getFigure(i, j));
					turn = 0;
					if(player->checkWin(board))
					{
						messages_text += " wygrywa gracz niebieski!";
						messages.setString(messages_text);
						for(int i = 0; i < 3; i++)
						{
							for(int j = 0; j < 3; j++)
							{
								if(board[i][j] == 0)
									board[i][j] = 3;
							}
						}
					}
					else if(checkTie())
					{
						messages_text += " remis!";
						messages.setString(messages_text);
					}
				}
			}
		}
	}
}

void Game::draw()
{
	window.clear();
	for(int i = 0; i < 4; i++)
		window.draw(lines[i]);
	for(std::vector<sf::RectangleShape>::iterator it = figures.begin(); it != figures.end(); it++)
		window.draw(*it);
	window.draw(messages);
	window.draw(button);
	window.draw(button_text);
	window.display();
}