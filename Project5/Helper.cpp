#include "Helper.h"

#define PI 3.1415

Helper::Helper()
	:m_speed(1)
{
	//cout << m_speed << endl;

	m_vectorToMove.insert(std::make_pair(
		Up,
		std::make_pair(
			sf::Vector2f(0, 0),
			sf::Vector2f(m_speed, -m_speed)
		)
	));

	m_vectorToMove.insert(std::make_pair(
		Down,
		std::make_pair(
			sf::Vector2f(0, 0),
			sf::Vector2f(-m_speed, m_speed)
		)
	));

	m_vectorToMove.insert(std::make_pair(
		Left,
		std::make_pair(
			sf::Vector2f(90, 90),
			sf::Vector2f(-m_speed, m_speed)
		)
	));

	m_vectorToMove.insert(std::make_pair(
		Right,
		std::make_pair(
			sf::Vector2f(90, 90),
			sf::Vector2f(m_speed, -m_speed)
		)
	));
}


Helper::~Helper() {}

const Helper::VectorToMoveMap& Helper::getVectorToMoveMap() {
	return m_vectorToMove;
}

Helper& Helper::getInstance() {
	static Helper instance;
	return instance;
}

sf::Vector2f Helper::getVectorToMove(int directions, float currRotation, float speed) {
	sf::Vector2f v = { 0, 0 };
	for (auto itr = Helper::getInstance().getVectorToMoveMap().begin(); itr != Helper::getInstance().getVectorToMoveMap().end(); ++itr) {
		int currDirection = (int)itr->first;
		if ((directions & currDirection) == currDirection) {
			auto rotation = (*itr).second.first;
			auto factor = (*itr).second.second;
			v += { factor.x *speed * (float)std::sin((PI / 180) * (currRotation + rotation.x)),
				   factor.y *speed* (float)std::cos((PI / 180) * (currRotation + rotation.y)) };
		}
	}
	return v;
}


void Helper::set_spped()
{
	m_speed += 2;
}