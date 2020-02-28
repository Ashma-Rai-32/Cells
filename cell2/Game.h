
#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "MainMenuState.h"
class Game
{
	sf::RenderWindow *window;
	sf::Event sfEvent;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings windowSettings;
	bool fullscreen;
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;
	
	std::map<std::string, int>supportedKeys;

	//initialize
	void initVariables();
	void initWindow();
		void initKeys();
		void initStates();



public:
	Game();
	virtual ~Game();


	//fucn
	//regular
	void endApplication();
	//update
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	//run
	void run();



};

#endif