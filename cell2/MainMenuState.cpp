#include "MainMenuState.h"

#include "GameState.h"


void MainMenuState::initVariables()
{
}

void MainMenuState::initBackground()
{
	this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));
	if (!this->bgTexture.loadFromFile("Resources/Images/Backgrounds/bg1.png"))
	{
		throw "EROOR::MAINMENUSTATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";

	}
	this->background.setTexture(&this->bgTexture);
} 

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/FARRAY.otf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initKeybinds()
{


	std::ifstream ifs("Config/mainmenustate_keybinds.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";


		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);

		}
	}
	ifs.close();


}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"]= new Button(590, 330, 200, 50,
		&this->font, "New Game", sf::Color(208, 150, 131, 200),
		sf::Color(203, 0, 0, 255), sf::Color(31, 31, 122, 200));

	this->buttons["SETTINGS"] = new Button(590, 410, 200, 50,
		&this->font, "Settings", sf::Color(208, 150, 131, 200),
		sf::Color(203, 0, 0, 255), sf::Color(31, 31, 122, 200));

	this->buttons["EXIT_STATE"] = new Button(590, 490, 200, 50,
		&this->font, "Quit", sf::Color(208, 150, 131, 200),
		sf::Color(203, 0, 0, 255), sf::Color(31, 31, 122, 200));

}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();

	this->initFonts();
	this->initKeybinds();
	this->initButtons();


}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for(it=this->buttons.begin();it!=this->buttons.end();++it)
	{
		delete it->second;

	}


}



void MainMenuState::endState()
{
	std::cout << "Ending Mainmenustate";
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();


	
}

void MainMenuState::updateButtons()
{
	for(auto it:this->buttons)
	{
		it.second->update(this->mousePosView);
	}
	//newgame
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->window,this->supportedKeys,this->states));
	}
	//eiuitgame
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->quit = true;
	}
	
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
	
	
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{for (auto it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
	target->draw(this->background);
	
	this->renderButtons(target);

	sf::Text mtext;
	mtext.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mtext.setFont(this->font);
	mtext.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mtext.setString(ss.str());
	target->draw(mtext);
}
