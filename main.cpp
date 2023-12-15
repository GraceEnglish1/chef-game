#include<SFML/Graphics.hpp>
#include<string>
#include "ChefGame.h"
#include<iostream>

using namespace sf;


// main file intialises and runs game
int main(){
	
	ChefGame game(600, "Chef Game");
	game.run();

	return 0;
}