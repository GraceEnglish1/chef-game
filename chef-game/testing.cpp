//script performs unit testing
//compile with g++ -o test testing.cpp Player.cpp LevelOneMeals.cpp LevelTwoMeals.cpp Meals.cpp Ingredients.cpp FoodEntity.cpp -lsfml-graphics -lsfml-window -lsfml-system
#include<SFML/Graphics.hpp>
#include<string>
#include "Player.h"
#include "Ingredients.h"
#include "Meals.h"
#include "LevelOneMeals.h"
#include "LevelTwoMeals.h"
#include<iostream>


using namespace sf;

int main(){

	///Test ingredients

	//Initalisation for ingredients test
	Ingredients ingredient("Tomato", 10, 50, 100, 1);
	Ingredients ingredient_negative("Tomato", 10, -50, -100, 1);

	//Test 1 - ingredient inital position
	if((ingredient.get_x() == 50) && (ingredient.get_y() == 100)){
		std::cout << "Passed: Test 1 - Initial position of ingredient"<< std::endl;
	} else {
		std::cout << "Failed: Test 1 - Initial position of ingredient"<< std::endl;
	}

	//Test 2 - ingredient inital negative position
	if((ingredient_negative.get_x() == -50) && (ingredient_negative.get_y() == -100)){
		std::cout << "Passed: Test 2 - Initial negative position of ingredient"<< std::endl;
	} else {
		std::cout << "Failed: Test 2 - Initial negative position of ingredient"<< std::endl;
	}

	//Test 3 - ingredient being set to different position
	ingredient.set_position(200,300);
	if((ingredient.get_x() == 200) && (ingredient.get_y() == 300)){
		std::cout << "Passed: Test 3 - Set position of ingredient"<< std::endl;
	} else {
		std::cout << "Failed: Test 3 - Set position of ingredient"<< std::endl;
	}

	//Test 4 - ingredient being set to negative position
	ingredient.set_position(-200,-300);
	if((ingredient.get_x() == -200) && (ingredient.get_y() == -300)){
		std::cout << "Passed: Test 4 - Set negative position of ingredient"<< std::endl;
	} else {
		std::cout << "Failed: Test 4 - Set negative position of ingredient"<< std::endl;
	}

	//Test 5 - key of ingredient
	if(ingredient.get_key() == 1){
		std::cout << "Passed: Test 5 - Key of ingredient"<< std::endl;
	} else {
		std::cout << "Failed: Test 5 - Key of ingredient"<< std::endl;
	}

	//Test 6 - Ingredient pick up position after initalisation
	if(ingredient.checkPickUp() == false){
		std::cout << "Passed: Test 6 - Initalisation of ingredient pick up bool"<< std::endl;
	} else {
		std::cout << "Failed: Test 6 - Initalisation of ingredient pick up bool"<< std::endl;
	}

	//Test 7 - Ingredient after being picked up
	ingredient.isPickedUp();

	if(ingredient.checkPickUp() == true){
		std::cout << "Passed: Test 7 - Ingredient is picked up"<< std::endl;
	} else {
		std::cout << "Failed: Test 7 - Ingredient is picked up"<< std::endl;
	}

	//Initalisation for tests on Player
	Player * player;
	player = new Player(10, 55, 100);
	
	Player * player_neg;
	player_neg = new Player(10, -55, -100);

	//Test 8 - position of player
	int test_player_position = 55;
	if(player->get_x() == 55 && player->get_y() == 100){
		std::cout << "Passed: Test 8 - Initial position of player"<< std::endl;
	}else {
		std::cout << "Failed: Test 8 - Initial position of player"<< std::endl;
	}

	//Test 9 - position of player
	if(player_neg->get_x() == -55 && player_neg->get_y() == -100){
		std::cout << "Passed: Test 9 - Initial position of player"<< std::endl;
	}else {
		std::cout << "Failed: Test 9 - Initial position of player"<< std::endl;
	}

	//Test 10 - move player 10 places to the left
	for(int i=0; i<10; i++){
		player->move_left(1);
	}

	if(player->get_x() == 45 && player->get_y() == 100){
		std::cout << "Passed: Test 10 - Move player left"<< std::endl;
	}else {
		std::cout << "Failed: Test 10 - Move player left"<< std::endl;
		std::cout << player->get_x() << std::endl;
	}

	//Test 11 - move player 10 places to the right
	for(int i=0; i<10; i++){
		player->move_right(1);
	}

	if(player->get_x() == 55 && player->get_y() == 100){
		std::cout << "Passed: Test 11 - Move player right"<< std::endl;
	}else {
		std::cout << "Failed: Test 11 - Move player right"<< std::endl;
	}

	//Test 12 - move player 10 places up
	for(int i=0; i<10; i++){
		player->move_up(1);
	}

	if(player->get_x() == 55 && player->get_y() == 90){
		std::cout << "Passed: Test 12 - Move player up"<< std::endl;
	}else {
		std::cout << "Failed: Test 12 - Move player up"<< std::endl;
	}

	//Test 13 - move player 10 places down
	for(int i=0; i<10; i++){
		player->move_down(1);
	}

	if(player->get_x() == 55 && player->get_y() == 100){
		std::cout << "Passed: Test 13 - Move player down"<< std::endl;
	}else {
		std::cout << "Failed: Test 13 - Move player down"<< std::endl;
	}

	//Test 14 - move player off screen will not break the game
	for(int i=0; i<1000; i++){
		player->move_down(1);
	}

	if(player->get_x() == 55 && player->get_y() == 1100){
		std::cout << "Passed: Test 14 - Move player down off screen"<< std::endl;
	}else {
		std::cout << "Failed: Test 14 - Move player down off screen"<< std::endl;
		std::cout << player->get_y()<< std::endl;
	}
	
	//Test 15 - Check player inventory key after colliding with ingredient
	Ingredients ingredient_two("Abcd", 20, 0, 0, 2);
	Player * player_two;
	player_two = new Player(20, 0, 0);
	player_two->isHit(0,0,20,ingredient_two.get_name(), ingredient_two.get_key());
	
	if(player_two->get_key(0)==2){
		std::cout << "Passed: Test 15 - Player inventory key matches ingredient key"<< std::endl;
	}else {
		std::cout << "Failed: Test 15 - Player inventory key matches ingredient key"<< std::endl;
		
	}

	//Test 16 - Test resetting inventory keys
	player_two->reset_keys();

	if(player_two->get_key(0)==0){
		std::cout << "Passed: Test 16 - Player inventory key reset"<< std::endl;
	}else {
		std::cout << "Failed: Test 16 - Player inventory key reset"<< std::endl;
		
	}

	//Initalising for Meal One Tests
	LevelOneMeals levelonemeals("Abc");

	//Test 17 - Testing score
	levelonemeals.set_score();

	if(levelonemeals.return_score()==100){
		std::cout << "Passed: Test 17 - Level 1 Meals score works"<< std::endl;
	}else {
		std::cout << "Failed: Test 17 - Level 1 Meals score works"<< std::endl;
		
	}

	//Initalising for Meal Two Tests
	LevelTwoMeals leveltwomeals("Defg");

	//Test 18 - Testing score for level two meals
	leveltwomeals.set_score();

	if(leveltwomeals.return_score()==100){
		std::cout << "Passed: Test 18 - Level 2 Meals score works"<< std::endl;
	}else {
		std::cout << "Failed: Test 18 - Level 2 Meals score works"<< std::endl;
		
	}

	//Test 19 - Ingredient score check
	ingredient.set_score(1);

	if(ingredient.return_score()==10){
		std::cout << "Passed: Test 19 - Level 1 Ingredients score works"<< std::endl;
	}else {
		std::cout << "Failed: Test 19 - Level 1 Ingredients score works"<< std::endl;
		
	}

	//Test 20 - Ingredient score check level 2
	ingredient.set_score(2);

	if(ingredient.return_score()==20){
		std::cout << "Passed: Test 20 - Level 2 Ingredients score works"<< std::endl;
	}else {
		std::cout << "Failed: Test 20 - Level 2 Ingredients score works"<< std::endl;
		
	}

	return 0;
}