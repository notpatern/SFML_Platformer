

#include "../../HeaderFiles/Game.hpp"

Game::Game() : player(Player(50,50)) {
	InitWindow();
}

Game::~Game() {

}

void Game::UpdateDt() {
	dt = dtClock.restart().asSeconds();
}

void Game::UpdateSFMLEvent() {
	if (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::Update() {
	UpdateSFMLEvent();
	player.Update(dt, window);
}

void Game::Render() {
	window.clear();

	player.Render(window);

	window.display();
}

void Game::run() {
	while (window.isOpen()) {
		UpdateDt();
		Update();
		Render();
	}
}

void Game::InitWindow() {
	window.create(sf::VideoMode(1920,1080), "SFML Platformer", sf::Style::Default);
}

