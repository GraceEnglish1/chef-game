#include<SFML/Graphics.hpp>
#include<string>
#include "Ingredients.h"

// source: OOP Game Part4: Player Class 2022, video recording, The University of Adelaide, Adelaide.
// used source in constructor, draw function, and get functions

// default constructor initialising position values, name and index value
Ingredients::Ingredients(){
	_name = "";
	int _r = 0;
	int _x = 0;
	int _y = 0;
	_index = 0;
}

// constructor
Ingredients::Ingredients(std::string name, int r, int x, int y, int index){
	// initialising ingredient body then setting radius, position, colour, origin, name, index and setting ingredient to not picked up
	body = new sf::CircleShape();
	body->setRadius(r);
	body->setPosition(x,y);
	body->setFillColor(sf::Color::Red);
	body->setOrigin(r/2,r/2);
	_depth=r;
	_name = name;
	_index = index;
	pickedUp=false;
}

//draws ingredients
void Ingredients::draw(sf::RenderWindow * win){
	win->draw(*body);
}

// returns x co-ordinate of position
int Ingredients::get_x(){
	return body->getPosition().x;
}

// returns y co-ordinate of position
int Ingredients::get_y(){
	return body->getPosition().y;
}

// returns depth of ingredient
int Ingredients::get_depth(){
	return _depth;
}

// set name of ingredient
void Ingredients::set_name(std::string name){
	_name = name;
}

// set position of ingredient
void Ingredients::set_position(int x, int y){
	body->setPosition(x,y);
}

// set colour, making sure each ingredient is differing
void Ingredients::set_colour(std::string colour){
	if(colour == "Yellow"){
		body->setFillColor(sf::Color::Yellow);
	} else if(colour == "Green"){
		body->setFillColor(sf::Color::Green);
	}
}

// returns ingredient name
std::string Ingredients::get_name(){
	return _name;
}

// returns index value of ingredient
int Ingredients::get_key(){
	return _index;
}

// sets score value for specific ingredient
void Ingredients::set_score(int level){
	_score = 10*level;
}

// sets score value for specific ingredient without level parameter
void Ingredients::set_score(){
	_score = 0;
}

// sets ingredient picked up status to true 
void Ingredients::isPickedUp(){
	pickedUp = true;
}

// returns whether ingredient is picked up or ot
bool Ingredients::checkPickUp(){
	return pickedUp;
}

// resets pickup status of ingredient to false
void Ingredients::reset_pickup(){
	pickedUp = false;
}

//deconstructor
Ingredients::~Ingredients(){
	delete this->body;
};
