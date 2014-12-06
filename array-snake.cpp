#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Snake!");
    window.setFramerateLimit(12);
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(20, 20));
    square.setFillColor(sf::Color::Blue);
    square.setPosition(300,250);
    srand(time(NULL));

   sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;


    sf::Text openingMessage;
    openingMessage.setFont(font);
    openingMessage.setCharacterSize(40);
    openingMessage.setPosition(170.f, 150.f);
    openingMessage.setColor(sf::Color::White);
    openingMessage.setString("Snake game!\nPress space to play");


    enum Direction {RIGHT,LEFT,UP,DOWN};
    Direction direction;

    enum _Direction {right,left,up,down};
    _Direction _direction;

    bool isPlay=false;

    struct a{
    float x=0;
    float y=0;
    };

    struct a p[50];

    p[0].x=25;
    p[0].y=25;
    int j=2;
    int z=0;
    int br=0;

    while (window.isOpen())
    {

        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {

            if ((event.type == sf::Event::Closed)||
                (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            {

                window.close();
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {

                if(!isPlay)
                {
                    isPlay=true;
                    direction=RIGHT;
                }
            }
        }

			if(isPlay)
            {

			if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
			{
				direction = RIGHT;
			}
			else if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
			{
				direction = LEFT;
			}
			else if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
			{
				direction = UP;
			}
			else if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
			{
				direction = DOWN;
			}




	if(direction == UP)
	{
		if(_direction != down)
		{
            for(z=j-1;z>0;z--)
            {
                p[z].x=p[z-1].x;
                p[z].y=p[z-1].y;
            }

			p[0].y=p[0].y-25;
			_direction = up;
		}
		else
		{
			for(z=j-1;z>0;z--)
            {
                p[z].x=p[z-1].x;
                p[z].y=p[z-1].y;
            }
			p[0].y=p[0].y+25;
		}
	}

	else if(direction == RIGHT)
	{
		if(_direction != left)
		{
            for(z=j-1;z>0;z--)
            {
                p[z].x=p[z-1].x;
                p[z].y=p[z-1].y;
            }

			p[0].x=p[0].x+25;
			_direction = right;
		}
		else
		{

            for(z=j-1;z>0;z--)
            {
                p[z].x=p[z-1].x;
                p[z].y=p[z-1].y;
            }
			p[0].x=p[0].x-25;
		}
	}

	else if(direction == DOWN)
	{
		if(_direction != up)
		{
            for(z=j-1;z>0;z--)
            {
                p[z].x=p[z-1].x;
                p[z].y=p[z-1].y;
            }

			p[0].y=p[0].y+25;
			_direction = down;
		}
		else
		{

            for(z=j-1;z>0;z--)
            {
                p[z].x=p[z-1].x;
                p[z].y=p[z-1].y;
            }
			p[0].y=p[0].y-25;
		}

	}

	else if(direction == LEFT)
	{
		if(_direction != right)
		{
            for(z=j-1;z>0;z--)
            {
                p[z].x=p[z-1].x;
                p[z].y=p[z-1].y;
            }

			p[0].x=p[0].x-25;
			_direction = left;
		}
		else
		{

            for(z=j-1;z>0;z--)
            {
                p[z].x=p[z-1].x;
                p[z].y=p[z-1].y;
            }
			p[0].x=p[0].x+25;
		}
	}



        for(int i=0;i<j;i++)
        {
            sf::RectangleShape kocka;
            kocka.setSize(sf::Vector2f(20, 20));
            kocka.setFillColor(sf::Color::Green);

            kocka.move(p[i].x,p[i].y);
            window.draw(kocka);
        }

        if(p[0].x==square.getPosition().x && p[0].y==square.getPosition().y)
        {
            j=j+1;
            int x=(rand()%24)*25;
            int y=(rand()%24)*25;

            square.setPosition(x,y);
        }
        if((p[0].x >=600 || p[0].x < 0) || (p[0].y >=600 || p[0].y < 0))
        {

            window.close();
        }

        for(br=1;br<j-1;br++)
        {
            if(p[0].x == p[br].x && p[0].y==p[br].y)
                window.close();
        }
            }

                if(!isPlay)
        {
            window.draw(openingMessage);
        }
        else
              window.draw(square);
        window.display();
	}


    return 0;
}

