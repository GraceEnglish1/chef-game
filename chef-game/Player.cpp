#include<SFML/Graphics.hpp>
#include<string>
#include<cmath>
#include "Player.h"
#include<iostream>

// source: OOP Game Part4: Collision Detection 2022, video recording, The University of Adelaide, Adelaide.
// source: OOP Game Part2: Player Class 2022, video recording, The University of Adelaide, Adelaide.
// used source in constructor, draw, isHit function, move functions and get functions

// constructor initialising player and setting player body attributes, initialises player inventory and slots
Player::Player(int r, int x, int y){
	body = new sf::CircleShape();
	body->setRadius(r);
	body->setPosition(x,y);
	body->setFillColor(sf::Color::Magenta);
	body->setOrigin(r/2,r/2);
	_depth = r;
	
	// initialising and setting player inventory and inventory slots
	inventory = new std::string[5];
	int inventory_index=0;
	key_slot_1 = 0;
	key_slot_2 = 0;
	key_slot_3 = 0;
	key_slot_4 = 0;
	key_slot_5 = 0;
}

//draws player
void Player::draw(sf::RenderWindow * win){
	win->draw(*body);
}

//moves player left/right/up/down
void Player::move_right(float speed){
	body->move(speed, 0);
}
void Player::move_left(float speed){
	body->move(-speed, 0);
}
void Player::move_up(float speed){
	body->move(0, -speed);
}
void Player::move_down(float speed){
	body->move(0, speed);
}

// returns players x/y/depth postion 
int Player::get_x(){
	return body->getPosition().x;
}
int Player::get_y(){
	return body->getPosition().y;
}
int Player::get_depth(){
	return _depth;
}

// detects collision between player and ingredient
bool Player::isHit(int t_x, int t_y, int t_depth, std::string name, int key){
	bool hit = false;
	int x = get_x();
	int y = get_y();
	float d = sqrt((x-t_x)*(x-t_x)+(y-t_y)*(y-t_y));
	// checking for collision
	if (d < (_depth + t_depth)){
		hit = true;
		inventory[inventory_index] = name;
		// sets inventory keyslot to appropriate ingredient index
		switch(inventory_index){
			case 0:
				key_slot_1 = key;
				break;
			case 1:
				key_slot_2 = key;
				break;
			case 2:
				key_slot_3 = key;
				break;
		}
		inventory_index++;
	}
	return hit;
}

// resets player inventory to empty
void Player::reset_inventory(){
	for(int i=0;i<5;i++){
		inventory[i] = "";
	}
	inventory_index = 0;
}

// returns value at certain index in player inventory
std::string Player::getInventory(int index){
	return *(inventory+index);
}

// returns key
int Player::get_key(int index){
	switch(index){
		case 0:
			return key_slot_1;
			break;
		case 1:
			return key_slot_2;
			break;
		case 2:
			return key_slot_3;
			break;
			}
	return 0;
}

//resets key values
void Player::reset_keys(){
	key_slot_1=0;
	key_slot_2=0;
	key_slot_3=0;
}

//deconstructor
Player::~Player(){
};
