#include <SFML/Graphics.hpp>
#include <iostream>

const int boardSize = 3;
auto squareBoard = new int[boardSize][boardSize]();
int tura = 1;
std::string napisy="Komunikaty:";

sf::Text tekst;

bool squareVisibility[9];
bool isActive[9];

void reset()
{
    for (int rows = 0; rows < 3; rows++) 
    {
        squareVisibility[rows] = false;
        isActive[rows]         = true;
    }
    tura = 1;
    napisy = "Komunikaty:";
    tekst.setString(napisy);
}

void check()
{
    if (((squareBoard[0][0] == 1) && (squareBoard[0][1] == 1) && (squareBoard[0][2] == 1)) || 
        ((squareBoard[1][0] == 1) && (squareBoard[1][1] == 1) && (squareBoard[1][2] == 1)) || 
        ((squareBoard[2][0] == 1) && (squareBoard[2][1] == 1) && (squareBoard[2][2] == 1)) || 
        ((squareBoard[0][0] == 1) && (squareBoard[1][0] == 1) && (squareBoard[2][0] == 1)) || 
        ((squareBoard[0][1] == 1) && (squareBoard[1][1] == 1) && (squareBoard[2][1] == 1)) || 
        ((squareBoard[0][2] == 1) && (squareBoard[1][2] == 1) && (squareBoard[2][2] == 1)) || 
        ((squareBoard[0][0] == 1) && (squareBoard[1][1] == 1) && (squareBoard[2][2] == 1)) || 
        ((squareBoard[0][2] == 1) && (squareBoard[1][1] == 1) && (squareBoard[2][0] == 1))
       )
    {
        napisy += " wygrywa gracz zielony!";
        tekst.setString(napisy);
        // TODO: Pętla for dla isActive[] false
    }
    else if (((squareBoard[0][0] == 2) && (squareBoard[0][1] == 2) && (squareBoard[0][2] == 2)) || 
             ((squareBoard[1][0] == 2) && (squareBoard[1][1] == 2) && (squareBoard[1][2] == 2)) || 
             ((squareBoard[2][0] == 2) && (squareBoard[2][1] == 2) && (squareBoard[2][2] == 2)) || 
             ((squareBoard[0][0] == 2) && (squareBoard[1][0] == 2) && (squareBoard[2][0] == 2)) || 
             ((squareBoard[0][1] == 2) && (squareBoard[1][1] == 2) && (squareBoard[2][1] == 2)) || 
             ((squareBoard[0][2] == 2) && (squareBoard[1][2] == 2) && (squareBoard[2][2] == 2)) || 
             ((squareBoard[0][0] == 2) && (squareBoard[1][1] == 2) && (squareBoard[2][2] == 2)) || 
             ((squareBoard[0][2] == 2) && (squareBoard[1][1] == 2) && (squareBoard[2][0] == 2))
            )
    {
        napisy += " wygrywa gracz neibieski!";
        tekst.setString(napisy);
        // TODO: Pętla for dla isActive[] false
    }
    else if ((isActive[1] == false) && (isActive[2] == false) && (isActive[3] == false) && 
             (isActive[4] == false) && (isActive[5] == false) && (isActive[6] == false) && 
             (isActive[7] == false) && (isActive[8] == false) && (isActive[9] == false)
            )
    {
        napisy += " remis";
        tekst.setString(napisy);
    }
}

int main()
{
    sf::RenderWindow oknoAplikacji(sf::VideoMode(500, 400, 32), "Okno aplikacji");

    // Tutaj za dużo niepotrzebnie stworzonych linijek - można to zautomatyzować
    sf::RectangleShape l1;
    sf::RectangleShape l2;
    sf::RectangleShape l3;
    sf::RectangleShape l4;

    // Kod dla każdego "L" się powtarza - trzeba pomyśleć o wydzieleniu funkcji 
    // z parametrem opcjonalnym rotate
    l1.setSize(sf::Vector2f(310, 5));
    l1.setFillColor(sf::Color(255, 255, 255));
    l1.setPosition(sf::Vector2f(100, 120));
    
    l2.setSize(sf::Vector2f(310, 5));
    l2.setFillColor(sf::Color(255, 255, 255));
    l2.setPosition(sf::Vector2f(100, 225));
    
    l3.setSize(sf::Vector2f(310, 5));
    l3.setFillColor(sf::Color(255, 255, 255));
    l3.setPosition(sf::Vector2f(205, 20));
    l3.rotate(90);
    
    l4.setSize(sf::Vector2f(310, 5));
    l4.setFillColor(sf::Color(255, 255, 255));
    l4.setPosition(sf::Vector2f(310, 20));
    l4.rotate(90);



    sf::RectangleShape o1(sf::Vector2f(70, 70));
    o1.setPosition(sf::Vector2f(115, 35));
    
    sf::RectangleShape o2(sf::Vector2f(70, 70));
    o2.setPosition(sf::Vector2f(220, 35));
    
    sf::RectangleShape o3(sf::Vector2f(70, 70));
    o3.setPosition(sf::Vector2f(325, 35));
    
    sf::RectangleShape o4(sf::Vector2f(70, 70));
    o4.setPosition(sf::Vector2f(115, 140));
    
    sf::RectangleShape o5(sf::Vector2f(70, 70));
    o5.setPosition(sf::Vector2f(220, 140));
    
    sf::RectangleShape o6(sf::Vector2f(70, 70));
    o6.setPosition(sf::Vector2f(325, 140));
    
    sf::RectangleShape o7(sf::Vector2f(70, 70));
    o7.setPosition(sf::Vector2f(115, 245));
    
    sf::RectangleShape o8(sf::Vector2f(70, 70));
    o8.setPosition(sf::Vector2f(220, 245));
    
    sf::RectangleShape o9(sf::Vector2f(70, 70));
    o9.setPosition(sf::Vector2f(325, 245));

    sf::RectangleShape button(sf::Vector2f(90, 30));
    button.setPosition(sf::Vector2f(370, 350));
    button.setFillColor(sf::Color(128, 128, 128));

    sf::Font font;
    if (!font.loadFromFile("DSPLAID.ttf"))
    {
            // error...
    }

    // Można to zrobić w odpowiedniej metodzie będzie ładniejsze
    sf::Text button_tekst;
    button_tekst.setFont(font);
    button_tekst.setCharacterSize(24);
    button_tekst.setString("Od nowa");
    button_tekst.setPosition(380, 350);

    tekst.setFont(font);
    tekst.setString(napisy);
    tekst.setCharacterSize(24);
    tekst.setPosition(sf::Vector2f(10, 350));

    while (oknoAplikacji.isOpen())
    {
        sf::Event zdarzenie;

        while (oknoAplikacji.pollEvent(zdarzenie))
        {
            if (zdarzenie.type == sf::Event::Closed)
                oknoAplikacji.close();

            if (zdarzenie.type == sf::Event::MouseButtonPressed && 
                zdarzenie.mouseButton.button == sf::Mouse::Left && 
                zdarzenie.mouseButton.x > 370 && 
                zdarzenie.mouseButton.x < 460 && 
                zdarzenie.mouseButton.y > 350 && 
                zdarzenie.mouseButton.y < 380)
                reset();

            if (zdarzenie.type == sf::Event::MouseButtonPressed && 
                zdarzenie.mouseButton.button == sf::Mouse::Left && 
                zdarzenie.mouseButton.x > 100 && 
                zdarzenie.mouseButton.x < 200 && 
                zdarzenie.mouseButton.y > 20 && 
                zdarzenie.mouseButton.y < 120 && 
                isActive[1] == true)
            {
                if (tura == 1)
                {
                    squareBoard[0][0] = 1;
                    o1.setFillColor(sf::Color(0, 255, 0));
                    squareVisibility[1] = true;
                    tura = 2;
                }
                else
                {
                    squareBoard[0][0] = 2;
                    o1.setFillColor(sf::Color(0, 0, 255));
                    squareVisibility[1] = true;
                    tura = 1;
                }
                isActive[1] = false;
                check();
            }
            if (zdarzenie.type == sf::Event::MouseButtonPressed && 
                zdarzenie.mouseButton.button == sf::Mouse::Left && 
                zdarzenie.mouseButton.x > 205 && 
                zdarzenie.mouseButton.x < 305 && 
                zdarzenie.mouseButton.y > 20 && 
                zdarzenie.mouseButton.y < 120 && 
                isActive[2] == true)
            {
                if (tura == 1)
                {
                    squareBoard[0][1] = 1;
                    o2.setFillColor(sf::Color(0, 255, 0));
                    squareVisibility[2] = true;
                    tura = 2;
                }
                else
                {
                    squareBoard[0][1] = 2;
                    o2.setFillColor(sf::Color(0, 0, 255));
                    squareVisibility[2] = true;
                    tura = 1;
                }
                isActive[2] = false;
                check();
            }
            if (zdarzenie.type == sf::Event::MouseButtonPressed && 
                zdarzenie.mouseButton.button == sf::Mouse::Left && 
                zdarzenie.mouseButton.x > 310 && 
                zdarzenie.mouseButton.x < 410 && 
                zdarzenie.mouseButton.y > 20 && 
                zdarzenie.mouseButton.y < 120 && 
                isActive[3] == true)
            {
                if (tura == 1)
                {
                    squareBoard[0][2] = 1;
                    o3.setFillColor(sf::Color(0, 255, 0));
                    squareVisibility[3] = true;
                    tura = 2;
                }
                else
                {
                    squareBoard[0][2] = 2;
                    o3.setFillColor(sf::Color(0, 0, 255));
                    squareVisibility[3] = true;
                    tura = 1;
                }
                isActive[3] = false;
                check();
            }
            if (zdarzenie.type == sf::Event::MouseButtonPressed && 
                zdarzenie.mouseButton.button == sf::Mouse::Left && 
                zdarzenie.mouseButton.x > 100 && 
                zdarzenie.mouseButton.x < 200 && 
                zdarzenie.mouseButton.y > 125 && 
                zdarzenie.mouseButton.y < 225 && 
                isActive[4] == true)
            {
                if (tura == 1)
                {
                    squareBoard[1][0] = 1;
                    o4.setFillColor(sf::Color(0, 255, 0));
                    squareVisibility[4] = true;
                    tura = 2;
                }
                else
                {
                    squareBoard[1][0] = 2;
                    o4.setFillColor(sf::Color(0, 0, 255));
                    squareVisibility[4] = true;
                    tura = 1;
                }
                isActive[4] = false;
                check();
            }
            if (zdarzenie.type == sf::Event::MouseButtonPressed &&
                zdarzenie.mouseButton.button == sf::Mouse::Left &&
                zdarzenie.mouseButton.x > 205 &&
                zdarzenie.mouseButton.x < 305 &&
                zdarzenie.mouseButton.y > 125 &&
                zdarzenie.mouseButton.y < 225 &&
                isActive[5] == true)
            {
                if (tura == 1)
                {
                    squareBoard[1][1] = 1;
                    o5.setFillColor(sf::Color(0, 255, 0));
                    squareVisibility[5] = true;
                    tura = 2;
                }
                else
                {
                    squareBoard[1][1] = 2;
                    o5.setFillColor(sf::Color(0, 0, 255));
                    squareVisibility[5] = true;
                    tura = 1;
                }
                isActive[5] = false;
                check();
            }
            if (zdarzenie.type == sf::Event::MouseButtonPressed &&
                zdarzenie.mouseButton.button == sf::Mouse::Left &&
                zdarzenie.mouseButton.x > 305 &&
                zdarzenie.mouseButton.x < 405 &&
                zdarzenie.mouseButton.y > 125 &&
                zdarzenie.mouseButton.y < 225 &&
                isActive[6] == true)
            {
                if (tura == 1)
                {
                    squareBoard[1][2] = 1;
                    o6.setFillColor(sf::Color(0, 255, 0));
                    squareVisibility[6] = true;
                    tura = 2;
                }
                else
                {
                    squareBoard[1][2] = 2;
                    o6.setFillColor(sf::Color(0, 0, 255));
                    squareVisibility[6] = true;
                    tura = 1;
                }
                isActive[6] = false;
                check();
            }
            if (zdarzenie.type == sf::Event::MouseButtonPressed &&
                zdarzenie.mouseButton.button == sf::Mouse::Left &&
                zdarzenie.mouseButton.x > 100 &&
                zdarzenie.mouseButton.x < 200 &&
                zdarzenie.mouseButton.y > 230 &&
                zdarzenie.mouseButton.y < 330 &&
                isActive[7] == true)
            {
                if (tura == 1)
                {
                    squareBoard[2][0] = 1;
                    o7.setFillColor(sf::Color(0, 255, 0));
                    squareVisibility[7] = true;
                    tura = 2;
                }
                else
                {
                    squareBoard[2][0] = 2;
                    o7.setFillColor(sf::Color(0, 0, 255));
                    squareVisibility[7] = true;
                    tura = 1;
                }
                isActive[7] = false;
                check();
            }
            if (zdarzenie.type == sf::Event::MouseButtonPressed &&
                zdarzenie.mouseButton.button == sf::Mouse::Left &&
                zdarzenie.mouseButton.x > 205 &&
                zdarzenie.mouseButton.x < 305 &&
                zdarzenie.mouseButton.y > 230 &&
                zdarzenie.mouseButton.y < 330 &&
                isActive[8] == true)
            {
                if (tura == 1)
                {
                    squareBoard[2][1] = 1;
                    o8.setFillColor(sf::Color(0, 255, 0));
                    squareVisibility[8] = true;
                    tura = 2;
                }
                else
                {
                    squareBoard[2][1] = 2;
                    o8.setFillColor(sf::Color(0, 0, 255));
                    squareVisibility[8] = true;
                    tura = 1;
                }
                isActive[8] = false;
                check();
            }
            if (zdarzenie.type == sf::Event::MouseButtonPressed &&
                zdarzenie.mouseButton.button == sf::Mouse::Left &&
                zdarzenie.mouseButton.x > 310 &&
                zdarzenie.mouseButton.x < 410 &&
                zdarzenie.mouseButton.y > 230 &&
                zdarzenie.mouseButton.y < 330 &&
                isActive[9] == true)
            {
                if (tura == 1)
                {
                    squareBoard[2][2] = 1;
                    o9.setFillColor(sf::Color(0, 255, 0));
                    squareVisibility[9] = true;
                    tura = 2;
                }
                else
                {
                    squareBoard[2][2] = 2;
                    o9.setFillColor(sf::Color(0, 0, 255));
                    squareVisibility[9] = true;
                    tura = 1;
                }
                isActive[9] = false;
                check();
            }
        }

        oknoAplikacji.clear();

        oknoAplikacji.draw(l1);
        oknoAplikacji.draw(l2);
        oknoAplikacji.draw(l3);
        oknoAplikacji.draw(l4);

        oknoAplikacji.draw(tekst);
        oknoAplikacji.draw(button);
        oknoAplikacji.draw(button_tekst);

        // Tutaj kod jest mega nadmiarowy - po pierwsze już nie mamy squareBoardlicy squareVisibilityXX, 
        // po drugie jest to ogromny blok kodu, który się powtarza
        if (squareVisibility[1] == true) oknoAplikacji.draw(o1);
        if (squareVisibility[2] == true) oknoAplikacji.draw(o2);
        if (squareVisibility[3] == true) oknoAplikacji.draw(o3);
        if (squareVisibility[4] == true) oknoAplikacji.draw(o4);
        if (squareVisibility[5] == true) oknoAplikacji.draw(o5);
        if (squareVisibility[6] == true) oknoAplikacji.draw(o6);
        if (squareVisibility[7] == true) oknoAplikacji.draw(o7);
        if (squareVisibility[8] == true) oknoAplikacji.draw(o8);
        if (squareVisibility[9] == true) oknoAplikacji.draw(o9);

        oknoAplikacji.display();
    }
    
    return 0;
}
