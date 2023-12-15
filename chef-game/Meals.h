#ifndef __Meals_h__
#define __Meals_h__

#include<SFML/Graphics.hpp>
#include<string>
#include "Ingredients.h"
#include "FoodEntity.h"

class Meals : public FoodEntity
{
protected:
	// defining meal variables
	Ingredients * meal_ingredients;
	bool completeness_check;
	sf::Text meals_UI;
	sf::Font font;
	int _number_of_ingredients;
public:
	// constructor
	Meals();
	// other constructor
	Meals(std::string name, int number_of_ingredients);
	// sets number of ingredients in meal
	void set_num_ingredients(int num);
	// checks for meal completeness
	bool is_meal_complete(int player_inventory, int index);
	// returns meal name
	std::string get_name();
	// returs recipe UI
	virtual std::string show_recipe();
	// sets score for completed meal
	void set_score();
	// deconstructor
	~Meals();
};

#endif //__Meals.h__