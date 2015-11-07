#include <SFML/Graphics.hpp>

class Game
{
	public:
		Game();

		void mainLoop();

	private:
		void loadFont();
		void initBoard();
		void initLines();
		void initAreas();
		void initMessages();
		void initButton();
		void newGame();
		bool checkTie();
		void events();
		void update();
		void draw();

		sf::RenderWindow window;
		sf::Event event;
		sf::Font font;
		int board[3][3];
		std::vector<sf::RectangleShape> figures;
		sf::RectangleShape lines[4];
		sf::RectangleShape button;
		sf::FloatRect areas[3][3];
		sf::Text messages;
		std::string messages_text;
		sf::Text button_text;
		Player* player;
		int turn;
		bool left_button;
};