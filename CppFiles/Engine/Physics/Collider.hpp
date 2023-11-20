//
// Created by rodie on 11/20/2023.
//

#ifndef UNTITLED_COLLIDER_HPP
#define UNTITLED_COLLIDER_HPP
#include "SFML/Graphics.hpp"

class Collider {
public:
	Collider(sf::FloatRect &body);
	~Collider();

	bool CheckCollision(Collider &other, float push);
	[[nodiscard]] sf::Vector2f GetPosition() const { return {body.left, body.top}; }
	[[nodiscard]] sf::Vector2f GetHalfSize() const { return {body.width / 2.0f, body.height / 2.0f}; }

private:
	sf::FloatRect &body;
};


#endif //UNTITLED_COLLIDER_HPP
