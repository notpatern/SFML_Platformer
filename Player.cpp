//
// Created by rodie on 11/19/2023.
//

#include "Player.hpp"

Player::Player(float playerHeight, float playerWidth, float maxMoveSpeed, float accel, float friction)
	: playerHeight(playerHeight), playerWidth(playerWidth), maxMoveSpeed(maxMoveSpeed), accel(accel), friction(friction)
	{
	this->InitPlayer();
}

Player::~Player() = default;

void Player::InitPlayer() {
	this->body.height = this->playerHeight;
	this->body.width = this->playerWidth;
	this->body.top = 490;

	this->playerShape.setSize(sf::Vector2f(this->playerWidth, this->playerHeight));
}

void Player::Update(float dt) {
	std::cout << this->xVel << std::endl;
	this->UpdatePhysics(dt);
	this->Movement(dt);
}

void Player::Render(sf::RenderTarget &target) {
	this->SyncBodyShape();
	target.draw(this->playerShape);
}

void Player::Movement(float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->xVel = std::min(this->xVel + this->accel * dt, this->maxMoveSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->xVel = std::max(this->xVel - this->accel * dt, -this->maxMoveSpeed);
	}
	else {
		this->Friction(dt);
	}

	this->body.left += this->xVel * dt;
}

void Player::UpdatePhysics(float dt) {
	if (!this->grounded)
		this->Gravity(dt);
}

void Player::Gravity(float dt) {

}

void Player::Friction(float dt) {
	if (this->xVel > 0)
		this->xVel = std::max(this->xVel - this->friction * dt, 0.0f);
	if (this->xVel < 0)
		this->xVel = std::min(this->xVel + this->friction * dt, 0.0f);
}

void Player::Jump() {

}

void Player::SyncBodyShape() {
	this->playerShape.setPosition(sf::Vector2f (this->body.left, this->body.top));
}

bool Player::CheckGrounded() {

}
