//
// Created by rodie on 11/19/2023.
//

#ifndef UNTITLED_GAME_HPP
#define UNTITLED_GAME_HPP

#include <iostream>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"


class Game {
private:
	sf::RenderWindow window;
	sf::Event event{};
	sf::Clock dtClock;
	float dt;

	void InitWindow();

public:
	Player player;

	Game();
	virtual ~Game();

	void UpdateDt();
	void UpdateSFMLEvent();
	void Update();
	void Render();
	void run();
};


#endif //UNTITLED_GAME_HPP
