

#include "Game.hpp"

Game::Game() : player(Player(100,100)) {
	this->InitWindow();
}

Game::~Game() {

}

void Game::UpdateDt() {
	this -> dt = this -> dtClock.restart().asSeconds();
}

void Game::UpdateSFMLEvent() {
	if (this->window.pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::Update() {
	this->UpdateSFMLEvent();
	player.Update(this->dt);
}

void Game::Render() {
	this->window.clear();

	player.Render(window);

	this->window.display();
}

void Game::run() {
	while (this->window.isOpen()) {
		this->UpdateDt();
		this->Update();
		this->Render();
	}
}

void Game::InitWindow() {
	this->window.create(sf::VideoMode(1920,1080), "SFML Platformer", sf::Style::Default);
}

