#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;
}

//Private functions
void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
}

//Constructor destructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//Getters
const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

//Update
void Game::update()
{
	this->pollEvents();
}

//Render
void Game::render()
{
	this->window->clear();
	this->window->display();
}
