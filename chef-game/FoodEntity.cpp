#include<SFML/Graphics.hpp>
#include<string>
#include "FoodEntity.h"

//default constructor initialising name
FoodEntity::FoodEntity(){
	_name = "";
}

// other constructor setting name
FoodEntity::FoodEntity(std::string name){
	_name = name;
}

// returns score  variable when called
int FoodEntity::return_score(){
	return _score;
}


// deconstructor 
FoodEntity::~FoodEntity()
{
}