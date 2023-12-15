#ifndef __LevelTwoMeals_h__
#define __LevelTwoMeals_h__

#include<SFML/Graphics.hpp>
#include<string>
#include "Meals.h"

class LevelTwoMeals : public Meals
{
protected:
	// define level two meal variable
	int level_two_number = 3;
public:
	// constructor
	LevelTwoMeals();
	// constructor creating meal
	LevelTwoMeals(std::string name);
	// recipe UI creation
	std::string show_recipe();
	// sets number of ingredients in meal
	void set_num_ingredients();
	// deconstructor
	~LevelTwoMeals();
};

#endif //__LevelTwoMeals.h__
