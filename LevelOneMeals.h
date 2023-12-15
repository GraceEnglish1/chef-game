#ifndef __LevelOneMeals_h__
#define __LevelOneMeals_h__

#include<SFML/Graphics.hpp>
#include<string>
#include "Meals.h"

class LevelOneMeals : public Meals
{
protected:
	// define level one meal variable
	int level_one_number = 2;
public:
	// constructor
	LevelOneMeals();
	// constructor creating meal
	LevelOneMeals(std::string name);
	// recipe UI creation
	std::string show_recipe();
	// sets number of ingredients in meal
	void set_num_ingredients();
	// deconstructor
	~LevelOneMeals();
};

#endif //__LevelOneMeals.h__
