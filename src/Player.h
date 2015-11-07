#include <SFML/Graphics.hpp>

class Player
{
    public:
		Player();

		sf::RectangleShape getFigure(const int& i, const int& j);

		virtual bool checkWin(int board[3][3]) = 0;

    protected:
    	sf::RectangleShape figure;
};

class PlayerGreen : public Player
{
    public:
    	PlayerGreen();

    	virtual bool checkWin(int board[3][3]);
};

class PlayerBlue : public Player
{
    public:
		PlayerBlue();

		virtual bool checkWin(int board[3][3]);
};