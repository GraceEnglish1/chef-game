#ifndef __ChefGame_h__
#define __ChefGame_h__

#include<SFML/Graphics.hpp>
#include<string>
#include "Player.h"
#include "Ingredients.h"
#include "Meals.h"
#include "LevelOneMeals.h"
#include "LevelTwoMeals.h"

using namespace sf;

class ChefGame
{
protected:
	// define ChefGame variables
	sf::RenderWindow* win;
	Player * player;
	Ingredients * ingredient;
	Ingredients * ingredient2;
	Ingredients * ingredient3;
	Meals * meal1;
	Meals * meal2;
	sf::Font font;
	sf::Text inventory_display;
	sf::Text front_page_info;
	sf::Text play_instructions;
	sf::Text recipe_display1;
	sf::Text recipe_display2;
	sf::Text end_game;
	sf::Text you_lose;
	sf::Text display_score;
	int _level;
	bool is_lose;
	int _score;

public:
	// constructor
	ChefGame(int size, std::string title);
	// checks for collisions between players and ingreadients
	void PickUp();
	// runs game
	void run();
	//deconstructor
	~ChefGame();
};

#endif //__ChefGame.h__