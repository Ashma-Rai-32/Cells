#ifndef ENTITY_H
#define ENTITY_H

#include<vector>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<sstream>

#include<stack>
#include<map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
class Entity
{private:

protected:
	sf::Texture frameTexture;
	sf::RectangleShape background;
	sf::RectangleShape shape;
	float movementSpeed;

public:
	Entity();
	virtual ~Entity();
//funv
	virtual void move(const float& dt, const float x, const float y);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
	
};
#endif

