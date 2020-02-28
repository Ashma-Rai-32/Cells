#ifndef BUTTON_H
#define BUTTON_H
#include<vector>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<sstream>


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };
class Button
{
	short unsigned buttonState;
	bool pressed;
	bool hover;

	sf::RectangleShape shape;
	sf::Font* font;

	
	sf::Text text;
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;


public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text,
		sf::Color idleColor,
		sf::Color hoverColor, sf::Color activeColor);
	~Button();
	const bool isPressed() const;

	//func
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget* target);

};

#endif

