//
// Created by rodie on 11/19/2023.
//

#ifndef UNTITLED_PLAYER_HPP
#define UNTITLED_PLAYER_HPP

#include <iostream>
#include "SFML/Window/Event.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <math.h>

class Player {
private:
	// player
	float playerHeight;
	float playerWidth;
	sf::FloatRect body;
	sf::RectangleShape playerShape;

	// movement
	bool grounded;
	bool moving;
	float maxMoveSpeed;
	float xVel = 0;
	float yVel = 0;
	float jumpForce;
	float gravity;
	float accel;
	float friction;

	void InitPlayer();
	void UpdatePhysics(float dt);
	void CheckGrounded(sf::RenderTarget &target);
	void Movement(float dt);
	void Gravity(float dt);
	void Friction(float dt);
	void Jump();
	void SyncBodyShape();

public:
	Player(float playerHeight, float playerWidth, float maxMoveSpeed = 800, float jumpForce = 1500, float accel = 8000, float friction = 2000);
	~Player();

	void Update(float dt, sf::RenderTarget &target);
	void Render(sf::RenderTarget &target);
};


#endif //UNTITLED_PLAYER_HPP
