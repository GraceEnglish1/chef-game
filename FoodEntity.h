#ifndef __FoodEntity_h__
#define __FoodEntity_h__
#include<SFML/Graphics.hpp>
#include<string>

class FoodEntity{
protected:
	// defining FoodEntity variables
	std::string _name;
	int _score;
public:
	//default constructor
	FoodEntity();
	// other constructo
	FoodEntity(std::string name);
	// initialises and stores score
	virtual void set_score()=0;
	// returns score
	int return_score();
	// deconstructor
	virtual ~FoodEntity();
};

#endif //__FoodEntity.h__