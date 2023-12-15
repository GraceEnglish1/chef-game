#ifndef __Player_h__
#define __Player_h__

#include<SFML/Graphics.hpp>
#include<string>

class Player{
protected:
	// defining player variables
	sf::CircleShape * body;
	std::string * inventory;
	int inventory_index;
	int key_slot_1;
	int key_slot_2;
	int key_slot_3;
	int key_slot_4;
	int key_slot_5;
	int inventory_ing_key[5];
public:
	//constructor
	Player(int r, int x, int y);
	//draws player
	void draw(sf::RenderWindow * win);
	//moves player left/right/up/down
	void move_right(float speed);
	void move_left(float speed);
	void move_up(float speed);
	void move_down(float speed);
	// checks if player has collided with ingredient
	bool isHit(int t_x, int t_y, int t_depth, std::string name, int key);
	// resets player inventory
	void reset_inventory();
	// resets keys
	void reset_keys();
	// defines depth
	int _depth;
	// returns players x/y/depth position
	int get_x();
	int get_y();
	int get_depth();
	// returns key value
	int get_key(int index);
	//int getKey(int index);
	std::string getInventory(int index);
	//deconstructor
	~Player();
};

#endif //__Player.h__