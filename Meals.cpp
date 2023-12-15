#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
#include "Meals.h"

// constructor initialising ingredients and setting meal UI text attributes, setting completeness to false
Meals::Meals(){
	_number_of_ingredients = 5;
	_name = "";
	meal_ingredients = new Ingredients[_number_of_ingredients];
	completeness_check = false;
	meals_UI.setFont(font);
	meals_UI.setFillColor(sf::Color::White);
	meals_UI.setCharacterSize(20);
	meals_UI.setPosition(100,100);

}

// constructor initialising ingredients and setting meal UI text attributes, setting completeness to false
Meals::Meals(std::string name, int number_of_ingredients){
	_number_of_ingredients = number_of_ingredients;
	_name = name;
	meal_ingredients = new Ingredients[_number_of_ingredients];
	//currently using Ingredients default constructor, hopefully this is correct
	completeness_check = false;
	meals_UI.setFont(font);
	meals_UI.setFillColor(sf::Color::Yellow);
	meals_UI.setCharacterSize(100);
	meals_UI.setPosition(400,400);
}

// setting number of ingredients in meal
void Meals::set_num_ingredients(int num){
	_number_of_ingredients = num;
}

// checking for meal completeness byt comparing expected ingredient key to actual ingredient key
bool Meals::is_meal_complete(int player_inventory, int index){
	if(meal_ingredients[index].get_key()!=player_inventory){
		return false;
	}
	return true;
}

// setting score of completed meal
void Meals::set_score(){
	_score = 100;
}

// returns meal name when called
std::string Meals::get_name(){
	return _name;
}

// sets recipe UI
std::string Meals::show_recipe(){
	std::string recipe_UI = "";
	return recipe_UI;
}

// deconstructor
Meals::~Meals(){
}

	

