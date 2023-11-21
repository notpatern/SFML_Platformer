#include "Player.hpp"

Player::Player(float playerHeight, float playerWidth, float maxMoveSpeed, float jumpForce, float accel, float friction)
	: playerHeight(playerHeight), playerWidth(playerWidth), maxMoveSpeed(maxMoveSpeed), jumpForce(jumpForce), accel(accel), friction(friction)
	{
	InitPlayer();
}

Player::~Player() = default;

void Player::InitPlayer() {
	body.height = playerHeight;
	body.width = playerWidth;
	body.top = 490;
	grounded = false;
	gravity = 9000;

	playerShape.setSize(sf::Vector2f(playerWidth, playerHeight));
}

void Player::Update(float dt, sf::RenderTarget &target) {
	Player::CheckGrounded(target);
	UpdatePhysics(dt);
	Movement(dt);
}

void Player::Render(sf::RenderTarget &target) {
	SyncBodyShape();
	target.draw(playerShape);
}

void Player::Movement(float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		xVel = std::min(xVel + accel * dt, maxMoveSpeed);
		moving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		xVel = std::max(xVel - accel * dt, -maxMoveSpeed);
		moving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && grounded) {
		Jump();
	}

	moving = false;

	body.left += xVel * dt;
	body.top += yVel * dt;
}

void Player::UpdatePhysics(float dt) {
	if (!grounded)
		Gravity(dt);
	if (!moving)
		Friction(dt);
}

void Player::Gravity(float dt) {
	yVel += gravity * dt;
}

void Player::Friction(float dt) {
	if (xVel > 0)
		xVel = std::max(xVel - friction * dt, 0.0f);
	if (xVel < 0)
		xVel = std::min(xVel + friction * dt, 0.0f);
}

void Player::Jump() {
	yVel = -jumpForce;
}

void Player::SyncBodyShape() {
	playerShape.setPosition(sf::Vector2f (body.left, body.top));
}

void Player::CheckGrounded(sf::RenderTarget &target) {
	if (body.top + body.height < target.getSize().y) {
		grounded = false;
	} else {
		body.top = target.getSize().y - body.height;
		grounded = true;
	}
}
