#include<SFML/Graphics.hpp>
#include<string>
#include "LevelTwoMeals.h"

// constuctor initialising and setting meal name, ingredient number and ingredients
LevelTwoMeals::LevelTwoMeals(std:: string name){
	_name = name;
	_number_of_ingredients = level_two_number;
	Ingredients tomato("Tomato", 5, 400, 400, 0);
	Ingredients pasta("Pasta", 5, 400, 400, 1);
	Ingredients spinach("Spinach", 5, 400, 400, 2);
	meal_ingredients[0] = tomato;
	meal_ingredients[1] = pasta;
	meal_ingredients[2] = spinach;
}

// sets number of ingredients to level 2 number - note more ingredients in level 2 than level 1
void LevelTwoMeals::set_num_ingredients(){
	_number_of_ingredients = level_two_number;
}

//  creates and returns level 2 recipe UI for game window
std::string LevelTwoMeals::show_recipe(){
	std::string recipe_UI;
	int index = 0;
	std::string string_index;
	for(int i=0; i < _number_of_ingredients;i++){
		index++;
		string_index = std::to_string(index);
		recipe_UI = recipe_UI + "Ingredient " + string_index + ": " + meal_ingredients[i].get_name()  + "\n";
	}
	std::string meal_name = "Level 2 Meal: " + _name + "\n";
	meal_name = meal_name + recipe_UI;

	return meal_name;
}

// deconstructor
LevelTwoMeals::~LevelTwoMeals()
{
}