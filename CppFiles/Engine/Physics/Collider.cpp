//
// Created by rodie on 11/20/2023.
//

#include "Collider.hpp"

Collider::Collider(sf::FloatRect &body) : body(body) {

}

Collider::~Collider() {

}

bool Collider::CheckCollision(Collider &other, float push) {
	return false;
}
