#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

enum Direction
{
	Up,Down,Right,Left
};

class Helper
{
	typedef std::map<Direction, std::pair<sf::Vector2f, sf::Vector2f>> VectorToMoveMap;
	public:
		static Helper& getInstance();
		const VectorToMoveMap& getVectorToMoveMap();
		sf::Vector2f getVectorToMove(int directions, float currRotation,float speed);
		void set_spped();
	private:
		VectorToMoveMap m_vectorToMove;
		Helper();
		~Helper();
		int m_speed;
};

