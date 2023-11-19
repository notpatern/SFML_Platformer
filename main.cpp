#include <iostream>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "sfml platformer", sf::Style::Default, settings);


		window.clear(sf::Color::Black);

		window.draw(player);

		window.display();
	}
    return 0;
}