#pragma once
#include <SFML/Graphics.hpp>

class Game
{
	//Variables
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	//Private functions
	void initVariables();
	void initWindow();

public:
	//Constructor destructor
	Game();
	virtual ~Game();

	//Getters
	const bool running() const;

	//Functions
	void pollEvents();
	void update();
	void render();
};