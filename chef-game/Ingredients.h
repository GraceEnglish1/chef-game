#ifndef __Ingredients_h__
#define __Ingredients_h__

#include<SFML/Graphics.hpp>
#include<string>
#include "FoodEntity.h"

class Ingredients : public FoodEntity{
protected:
	// defines ingredient variables
	sf::CircleShape * body;
	int _depth;
	bool pickedUp;
	int _r;
	int _x;
	int _y;
	int _index;
public:
	// default constructor
	Ingredients();
	// constructor
	Ingredients(std::string name, int r, int x, int y, int index);
	// draws player
	void draw(sf::RenderWindow * win);
	// get positions
	int get_x();
	int get_y();
	int get_depth();
	std::string get_name();
	int get_key();
	//set name
	void set_name(std::string name);
	//set position
	void set_position(int x, int y);
	//set colour
	void set_colour(std::string colour);
	// sets true for ingredient picked up
	void isPickedUp();
	// checks pick up status
	bool checkPickUp();
	// resets pickup status
	void reset_pickup();
	// sets score of ingredient with level parameter
	void set_score(int level);
	// sets score of ingredient without level paramter
	void set_score();
	// deconstructor
	~Ingredients();
};

#endif //__Ingredients.h__