//
// Created by rodie on 11/20/2023.
//

#ifndef UNTITLED_STATE_HPP
#define UNTITLED_STATE_HPP

#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"

class State {
private:
	std::vector<sf::Texture> textures;

public:
	State();
	virtual ~State();

	virtual void Update() = 0;
	virtual void Render() = 0;
};


#endif //UNTITLED_STATE_HPP
