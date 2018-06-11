#ifdef _DEBUG
#pragma comment(lib, "sfml-main-d.lib")
#elif defined(NDEBUG)
#pragma comment(lib, "sfml-main.lib")
#else
#error "Unrecognized configuration!"
#endif

#include <SFML/Graphics.hpp>
#include <cassert>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <random>
#include <time.h>
#include <sstream>
#include <SFML/Audio.hpp>
#include "Helper.h"

using namespace std;
using std::ofstream;
using std::max;


/*int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Pacman game");
	sf::RectangleShape shape(sf::Vector2f(200, 200));
	shape.setPosition(100, 100);
	shape.setFillColor(sf::Color::Red);
	sf::Image image;

	if (image.loadFromFile("1.JPG"))
		return -1;

	bool col = true;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				if(event.key.code == sf::Keyboard::Escape)
					window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					sf::Vector2i v = sf::Mouse::getPosition(window);

					if (v.x > 100 && v.x < 300 && v.y > 100 && v.y < 300)
					{
						if (col)
						{
							shape.setFillColor(sf::Color::Green);
							col = false;
						}
						else
						{
							shape.setFillColor(sf::Color::Red);
							col = true;
						}
					}
				}
			}
		}
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}*/
/*int main()
{
	string str_menu[10] = { "wall.png","cookie.png", "ghost.png", "pacman.png", "red.png", "green.png", "blue.png", "Delete.png", "Clear.png", "Save.png" };
	string str_board[13] = { "blueC.png","blueG.png","blueP.png","greenC.png","greenG.png","greenP.png","redC.png","redG.png","redP.png","wallB.png","wallG.png","wallR.png","empty.png" };

	srand(time(NULL));

	bool ok = true;
	bool move = true;
	int c = 0;

	sf::RenderWindow window(sf::VideoMode(600, 600), "Pong");

	while (window.isOpen())
	{

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::KeyPressed)
					if (event.key.code == sf::Keyboard::Escape)
						window.close();

				if (event.type == sf::Event::MouseMoved)
				{
					sf::Vector2i v = sf::Mouse::getPosition(window);
					if (v.x > 90 && v.x < 240 && v.y > 30 && v.y < 180)
						move = false;
					else
						move = true;
				}


				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						sf::Vector2i v = sf::Mouse::getPosition(window);

						if (v.x > 30 && v.x < 60 && v.y > 30 && v.y < 330)
							ok = false;
						else
							ok = true;
					}
				}
			}
			for (int i = 0; i < 10; i++)
			{
				sf::Texture tex;
				sf::Sprite cartoon;

				assert(tex.loadFromFile(str_menu[i]));

				cartoon.setTexture(tex);
				cartoon.setPosition(30 , (30 + (i * 30)));

				if(!ok)
					cartoon.setColor(sf::Color::Yellow);

				window.draw(cartoon);
			}
			for (int row = 0; row < 5; row++)
			{
				for (int col = 0; col < 5; col++)
				{
					int num_of_image = (rand () % 12);

					sf::Texture tex;
					sf::Sprite cartoon;

					assert(tex.loadFromFile(str_board[num_of_image]));

					cartoon.setTexture(tex);
					cartoon.setPosition(90 + (30 * col), (30 + (row * 30)));

					if (!move)
						cartoon.setColor(sf::Color::Blue);
					else
						cartoon.setColor(sf::Color::Green);

					window.draw(cartoon);
				}
			}
			sf::Texture tex;
			sf::Sprite cartoon;

			if(move)
			c++;
			c = c % 4;

			assert(tex.loadFromFile("greenP.png"));

			cartoon.setTexture(tex);
			cartoon.setPosition(300, 300);

			if (c == 1)
				cartoon.setColor(sf::Color::Blue);
			if(c == 2)
				cartoon.setColor(sf::Color::Green);
			if (c == 3)
				cartoon.setColor(sf::Color::Red);

			window.draw(cartoon);

		window.display();
	}

	return 0;
}
*/
int main()
{
//	sf::RenderWindow window(sf::VideoMode(1500, 900), "Pong");
	sf::RenderWindow window(sf::VideoMode(3000, 900), "Pong");
	window.setFramerateLimit(100);
	float y = 2985;
	float x = 330;

	float speed = 5;

	char direction = 'S';

	sf::Clock clock1;
	int lastMili1 = 0;
	int currentMili1 = 0;

	float Rotation = 0;
	float Rotation1 = 0;
	float speed_rotate = speed / 4;

	sf::Texture tex1;
	sf::Sprite cartoon1;

	sf::Texture tex;
	sf::Sprite cartoon;

	sf::Texture board;
	sf::Sprite cartoon2;

	string car1 = "Cruz63.png";
	string sboard = "Board4557.png";

	assert(tex1.loadFromFile(car1));
	assert(tex.loadFromFile(car1));
	assert(board.loadFromFile(sboard));


	cartoon1.setTexture(tex1);
	cartoon.setTexture(tex);
	cartoon2.setTexture(board);

	cartoon2.setPosition(0, 0);

	//sf::View viewLeft(sf::FloatRect(x + tex1.getSize().x / 2-500, y + tex1.getSize().y / 2-500, window.getSize().x / 2, window.getSize().y));
	sf::View viewLeft(sf::FloatRect(x + tex1.getSize().x / 2-1000, y + tex1.getSize().y / 2-400, window.getSize().x / 2-100, window.getSize().y-100));
	viewLeft.setViewport(sf::FloatRect(0, 0, 0.5, 1));
	sf::View viewRight(sf::FloatRect(x + tex1.getSize().x / 2 - 360 , y + tex1.getSize().y / 2 - 400, window.getSize().x / 2-100, window.getSize().y-100));
	viewRight.setViewport(sf::FloatRect(0.5, 0, 0.5, 1));

///*	sf::View view(sf::Vector2f(200, 200), sf::Vector2f(1200, 700));
//	view.setCenter(x + tex1.getSize().x / 2, y + tex1.getSize().y / 2);
//	window.setView(view);
//
//	sf::View minimap(sf::Vector2f(200, 200), sf::Vector2f(300, 180));
///*	minimap.setCenter(4000, 4000);
//	window.setView(minimap);*/
//
//	view.setViewport(sf::FloatRect(0.5f, 0, 0.5f, 1));
//	minimap.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));

	cartoon1.setOrigin(tex1.getSize().x / 2, tex1.getSize().y / 2);
	cartoon1.setPosition(x + tex1.getSize().x / 2, y + tex1.getSize().y / 2);

	cartoon.setOrigin(tex.getSize().x / 2, tex.getSize().y / 2);
	cartoon.setPosition(x + tex.getSize().x / 2 - 40, y + tex.getSize().y / 2);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)//Closed
				window.close();

			if (event.type == sf::Event::KeyPressed)//KeyPressed
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			Rotation += speed_rotate;
			cartoon1.move(Helper::getInstance().getVectorToMove(Down, Rotation,speed));
		//	viewLeft.move(Helper::getInstance().getVectorToMove(Down, Rotation, speed));
			viewRight.move(Helper::getInstance().getVectorToMove(Down, Rotation, speed));
		//	view.rotate(1.0f);///////////////////////////////////////////////////////////////////////
			cartoon1.rotate(speed_rotate);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			Rotation -= speed_rotate;
			cartoon1.move(Helper::getInstance().getVectorToMove(Down, Rotation, speed));
		//	viewLeft.move(Helper::getInstance().getVectorToMove(Down, Rotation, speed));
			viewRight.move(Helper::getInstance().getVectorToMove(Down, Rotation, speed));
		//	view.rotate(-1.0f);//////////////////////////////////////////////////////////////////////////
			cartoon1.rotate(-speed_rotate);
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))////////////////////
		{
			Rotation1 += speed_rotate;
			cartoon.move(Helper::getInstance().getVectorToMove(Down, Rotation, speed));
			viewLeft.move(Helper::getInstance().getVectorToMove(Down, Rotation, speed));
		//	viewRight.move(Helper::getInstance().getVectorToMove(Down, Rotation, speed));
			//	view.rotate(1.0f);///////////////////////////////////////////////////////////////////////
			cartoon.rotate(speed_rotate);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Rotation1 -= speed_rotate;
			cartoon.move(Helper::getInstance().getVectorToMove(Down, Rotation, speed));
			viewLeft.move(Helper::getInstance().getVectorToMove(Down, Rotation, speed));
		//	viewRight.move(Helper::getInstance().getVectorToMove(Down, Rotation, speed));
			//	view.rotate(-1.0f);//////////////////////////////////////////////////////////////////////////
			cartoon.rotate(-speed_rotate);////////////////////////////////
		}




		currentMili1 = clock1.getElapsedTime().asMilliseconds();
		if (currentMili1 - lastMili1 > 1)
		{
			cartoon1.move(Helper::getInstance().getVectorToMove(Up, Rotation, speed));
			cartoon.move(Helper::getInstance().getVectorToMove(Up, Rotation, speed));
			viewLeft.move(Helper::getInstance().getVectorToMove(Up, Rotation, speed));
			viewRight.move(Helper::getInstance().getVectorToMove(Up, Rotation, speed));

			lastMili1 = currentMili1;
			
			/*window.setView(viewRight);
			window.setView(viewLeft);*/
//			window.setView(minimap);
		}

		/*if (currentMili1 >= 10000)
			speed = 9;*/

		window.clear();

		window.setView(viewRight);
		window.draw(cartoon2);
		window.draw(cartoon1);
		window.draw(cartoon);
		window.setView(viewLeft);
		window.draw(cartoon2);
		window.draw(cartoon1);
		window.draw(cartoon);

		window.display();
	}
	return 0;
}
//int main()
//{
//	sf::Clock clock;
//	int current;
//	int left_sec = 0;
//	int right_sec = 0;
//	int min = 0;
//
//	sf::Text text;
//	sf::Text text1;
//	sf::Text text2;
//	sf::Text text3;
//	sf::Font font;
//	font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
//	sf::RenderWindow window(sf::VideoMode(600, 600), "Pong");
//
//	while (window.isOpen())
//	{
//		current = clock.getElapsedTime().asSeconds();
//
//		if (current == 10)
//		{
//			clock.restart();
//			left_sec = 0;
//			right_sec++;
//
//			if (right_sec == 6)
//			{
//				min++;
//				right_sec = 0;
//
//				if (min == 3)
//					break;
//			}
//		}
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//
//			if (event.type == sf::Event::KeyPressed)
//				if (event.key.code == sf::Keyboard::Escape)
//					window.close();
//		}
//
//		string s_left = std::to_string(current);
//		string s_right = std::to_string(right_sec);
//		string s_min = std::to_string(min);
//
//		text.setString("3:00/  :");
//		text1.setString(s_left);
//		text2.setString(s_right);
//		text3.setString(s_min);
//
//		text.setFont(font);
//		text.setCharacterSize(50);
//		text.setFillColor(sf::Color::Red);
//		text.setPosition(0, 120);
//		text.setStyle(sf::Text::Bold);
//
//		text1.setFont(font);
//		text1.setCharacterSize(50);
//		text1.setFillColor(sf::Color::Red);
//		text1.setPosition(190, 120);
//		text1.setStyle(sf::Text::Bold);
//
//		text2.setFont(font);
//		text2.setCharacterSize(50);
//		text2.setFillColor(sf::Color::Red);
//		text2.setPosition(160, 120);
//		text2.setStyle(sf::Text::Bold);
//
//		text3.setFont(font);
//		text3.setCharacterSize(50);
//		text3.setFillColor(sf::Color::Red);
//		text3.setPosition(120, 120);
//		text3.setStyle(sf::Text::Bold);
//
//		window.clear();
//		window.draw(text);
//		window.draw(text1);
//		window.draw(text2);
//		window.draw(text3);
//
//
//		window.display();
//	}
//	return 0;
//}









//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(1500, 900), "Pong");
//	window.setFramerateLimit(100);
//	float y = 2985;
//	float x = 370;
//	float y1 = 2985;
//	float x1 = 290;
//
//	//char direction = 'S';
//
//	sf::Clock clock1;
//	int lastMili1 = 0;
//	int currentMili1 = 0;
//
//	sf::Clock clock;
//	int lastMili = 0;
//	int currentMili = 0;
//
//	float Rotation = 0;
//	float Rotation1 = 0;
//
//	sf::Texture tex1;
//	sf::Sprite cartoon1;
//	sf::Texture tex;
//	sf::Sprite cartoon;
//
//	sf::Texture board;
//	sf::Sprite cartoon2;
//
//	string car1 = "Cruz63.png";
//	string sboard = "Board4557.png";
//
//	assert(tex1.loadFromFile(car1));
//	assert(tex.loadFromFile(car1));
//	assert(board.loadFromFile(sboard));
//
//
//	cartoon1.setTexture(tex1);
//	cartoon.setTexture(tex);
//	cartoon2.setTexture(board);
//
//	cartoon2.setPosition(0, 0);
//
//	sf::View view(sf::Vector2f(200, 200), sf::Vector2f(1200, 700));
//	view.setCenter(x + tex1.getSize().x / -40, y + tex1.getSize().y / 2);
//	window.setView(view);
//
//	cartoon1.setOrigin(tex1.getSize().x / 2, tex1.getSize().y / 2);
//	cartoon1.setPosition(x + tex1.getSize().x / 2, y + tex1.getSize().y / 2);
//
//	cartoon.setOrigin(tex.getSize().x / 2, tex.getSize().y / 2);
//	cartoon.setPosition(x1 + tex.getSize().x / 2, y1 + tex.getSize().y / 2);
//
//	while (window.isOpen())
//	{
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)//Closed
//				window.close();
//
//			if (event.type == sf::Event::KeyPressed)//KeyPressed
//				switch (event.key.code)
//				{
//				case sf::Keyboard::Escape:
//					window.close();
//					break;
//				}
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//		{
//			Rotation += 1;
//			cartoon1.move(Helper::getInstance().getVectorToMove(Down, Rotation));
//			view.move(Helper::getInstance().getVectorToMove(Down, Rotation));
//			//	view.rotate(1.0f);///////////////////////////////////////////////////////////////////////
//			cartoon1.rotate(1.0f);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//		{
//			Rotation += -1;
//			cartoon1.move(Helper::getInstance().getVectorToMove(Down, Rotation));
//			view.move(Helper::getInstance().getVectorToMove(Down, Rotation));
//			//	view.rotate(-1.0f);//////////////////////////////////////////////////////////////////////////
//			cartoon1.rotate(-1.0f);
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//		{
//			Rotation1 += 1;
//			cartoon.move(Helper::getInstance().getVectorToMove(Down, Rotation));
//			//view.move(Helper::getInstance().getVectorToMove(Down, Rotation));
//			//	view.rotate(1.0f);///////////////////////////////////////////////////////////////////////
//			cartoon.rotate(1.0f);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//		{
//			Rotation1 += -1;
//			cartoon.move(Helper::getInstance().getVectorToMove(Down, Rotation));
//			//view.move(Helper::getInstance().getVectorToMove(Down, Rotation));
//			//	view.rotate(-1.0f);//////////////////////////////////////////////////////////////////////////
//			cartoon.rotate(-1.0f);
//		}
//
//		currentMili1 = clock1.getElapsedTime().asMilliseconds();
//		if (currentMili1 - lastMili1 > 1)
//		{
//			cartoon1.move(Helper::getInstance().getVectorToMove(Up, Rotation));
//			view.move(Helper::getInstance().getVectorToMove(Up, Rotation));
//
//			lastMili1 = currentMili1;
//			window.setView(view);
//		}
//
//		currentMili = clock.getElapsedTime().asMilliseconds();
//		if (currentMili - lastMili > 1)
//		{
//			cartoon.move(Helper::getInstance().getVectorToMove(Up, Rotation));
//			//view.move(Helper::getInstance().getVectorToMove(Up, Rotation));
//
//			lastMili = currentMili;
//			//window.setView(view);
//		}
//
//		window.clear();
//
//		window.draw(cartoon2);
//		window.draw(cartoon1);
//		window.draw(cartoon);
//
//		window.display();
//	}
//	return 0;
//}


//int main()
//{
//	sf::Clock clock;
//	int current = 0;
//	int left_sec = 0;
//	int right_sec = 0;
//	int min = 0;
//
//	sf::Text text;
//	sf::Text text1;
//	sf::Text text2;
//	sf::Text text3;
//	sf::Font font;
//	font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf");
//
//
//
//	sf::RenderWindow window(sf::VideoMode(1500, 900), "Pong");
//	window.setFramerateLimit(100);
//	float y = 2985;
//	float x = 330;
//
//	char direction = 'S';
//
//	sf::Clock clock1;
//	int lastMili1 = 0;
//	int currentMili1 = 0;
//
//	float Rotation = 0;
//
//	sf::Texture tex1;
//	sf::Sprite cartoon1;
//
//	sf::Texture board;
//	sf::Sprite cartoon2;
//
//	string car1 = "Cruz63.png";
//	string sboard = "Board4557.png";
//
//	assert(tex1.loadFromFile(car1));
//	assert(board.loadFromFile(sboard));
//
//
//	cartoon1.setTexture(tex1);
//	cartoon2.setTexture(board);
//
//	cartoon2.setPosition(0, 0);
//
//	sf::View view(sf::Vector2f(200, 200), sf::Vector2f(1200, 700));
//	view.setCenter(x + tex1.getSize().x / 2, y + tex1.getSize().y / 2);
//	window.setView(view);
//
//	cartoon1.setOrigin(tex1.getSize().x / 2, tex1.getSize().y / 2);
//	cartoon1.setPosition(x + tex1.getSize().x / 2, y + tex1.getSize().y / 2);
//
//	while (window.isOpen())
//	{
//		current = clock.getElapsedTime().asSeconds();
//
//		if (current == 10)
//		{
//			clock.restart();
//			current = 0;
//			right_sec++;
//
//			if (right_sec == 6)
//			{
//				min++;
//				right_sec = 0;
//
//				if (min == 3)
//					break;
//			}
//		}
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)//Closed
//				window.close();
//
//			if (event.type == sf::Event::KeyPressed)//KeyPressed
//				switch (event.key.code)
//				{
//				case sf::Keyboard::Escape:
//					window.close();
//					break;
//				}
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//		{
//			Rotation += 1;
//			cartoon1.move(Helper::getInstance().getVectorToMove(Down, Rotation));
//			view.move(Helper::getInstance().getVectorToMove(Down, Rotation));
//			//	view.rotate(1.0f);///////////////////////////////////////////////////////////////////////
//			cartoon1.rotate(1.0f);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//		{
//			Rotation += -1;
//			cartoon1.move(Helper::getInstance().getVectorToMove(Down, Rotation));
//			view.move(Helper::getInstance().getVectorToMove(Down, Rotation));
//			//	view.rotate(-1.0f);//////////////////////////////////////////////////////////////////////////
//			cartoon1.rotate(-1.0f);
//		}
//
//		currentMili1 = clock1.getElapsedTime().asMilliseconds();
//		if (currentMili1 - lastMili1 > 1)
//		{
//			cartoon1.move(Helper::getInstance().getVectorToMove(Up, Rotation));
//			view.move(Helper::getInstance().getVectorToMove(Up, Rotation));
//
//			lastMili1 = currentMili1;
//			window.setView(view);
//		}
//
//		string s_left = std::to_string(current);
//		string s_right = std::to_string(right_sec);
//		string s_min = std::to_string(min);
//
//		text.setString("3:00/  :");
//		text1.setString(s_left);
//		text2.setString(s_right);
//		text3.setString(s_min);
//
//		text.setFont(font);
//		text.setCharacterSize(50);
//		text.setFillColor(sf::Color::Red);
//		//text.setPosition(0, 120);
//		text.setPosition(view.getCenter().x - 590, view.getCenter().y - 340);
//		text.setStyle(sf::Text::Bold);
//
//		text1.setFont(font);
//		text1.setCharacterSize(50);
//		text1.setFillColor(sf::Color::Red);
//		//text1.setPosition(190, 120);
//		text1.setPosition(view.getCenter().x - 400, view.getCenter().y - 340);
//		text1.setStyle(sf::Text::Bold);
//
//		text2.setFont(font);
//		text2.setCharacterSize(50);
//		text2.setFillColor(sf::Color::Red);
//		//text2.setPosition(160, 120);
//		text2.setPosition(view.getCenter().x - 430, view.getCenter().y - 340);
//		text2.setStyle(sf::Text::Bold);
//
//		text3.setFont(font);
//		text3.setCharacterSize(50);
//		text3.setFillColor(sf::Color::Red);
//		//text3.setPosition(120, 120);
//		text3.setPosition(view.getCenter().x - 470, view.getCenter().y - 340);
//		text3.setStyle(sf::Text::Bold);
//
//		window.clear();
//
//		window.draw(cartoon2);
//		window.draw(cartoon1);
//
//		window.draw(text);
//		window.draw(text1);
//		window.draw(text2);
//		window.draw(text3);
//
//		window.display();
//	}
//	return 0;
//}