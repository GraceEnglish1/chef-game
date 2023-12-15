#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
#include "ChefGame.h"
using namespace sf;

// game constructor
ChefGame::ChefGame(int size, std::string title){
	// initialising game window, player, ingredients, level, meals, success variable and score
	win = new sf::RenderWindow(sf::VideoMode(size, size),title);
	player = new Player(20,300,200);
	ingredient = new Ingredients("Tomato", 10, 400, 300, 0);
	ingredient2 = new Ingredients("Pasta", 10, 300, 350, 1);
	ingredient3 = new Ingredients("Spinach", 10, 200, 300,2);
	ingredient2->set_colour("Yellow");
	ingredient3->set_colour("Green");
	meal1 = new LevelOneMeals("Tomato Pasta");
	meal2 = new LevelTwoMeals("Healthy Pasta");
	_level = 0;
	is_lose = false;
	_score = 0;

	// validating font location and setting text attributes in game window
	if(!font.loadFromFile("./font.ttf")){
		std::cout << "Font not found \n";
		exit(0);
	}

	// inventory text attributes 
	inventory_display.setFont(font);
	inventory_display.setFillColor(sf::Color::White);
	inventory_display.setCharacterSize(20);
	inventory_display.setPosition(50,20);
	// front page text attributes
	front_page_info.setFont(font);
	front_page_info.setFillColor(sf::Color::White);
	front_page_info.setCharacterSize(20);
	front_page_info.setPosition(50,20);
	// play instructions text attributes
	play_instructions.setFont(font);
	play_instructions.setFillColor(sf::Color::White);
	play_instructions.setCharacterSize(20);
	play_instructions.setPosition(50,500);
	// level 1 recipe text attributes
	recipe_display1.setFont(font);
	recipe_display1.setFillColor(sf::Color::White);
	recipe_display1.setCharacterSize(20);
	recipe_display1.setPosition(300,20);
	// level 2 recipe text attributes
	recipe_display2.setFont(font);
	recipe_display2.setFillColor(sf::Color::White);
	recipe_display2.setCharacterSize(20);
	recipe_display2.setPosition(300,20);
	// end game text attributes
	end_game.setFont(font);
	end_game.setFillColor(sf::Color::White);
	end_game.setCharacterSize(20);
	end_game.setPosition(100,300);
	// losing text atributes
	you_lose.setFont(font);
	you_lose.setFillColor(sf::Color::Red);
	you_lose.setCharacterSize(40);
	you_lose.setPosition(100,300);
	// score attributes
	display_score.setFont(font);
	display_score.setFillColor(sf::Color::White);
	display_score.setCharacterSize(40);
	display_score.setPosition(50,110);
}

// checks if ingredient is picked up, then calls set score function and adds returned score to score variable
void ChefGame::PickUp(){
	if(ingredient->checkPickUp() !=  true && player->isHit(ingredient->get_x(), ingredient->get_y(), ingredient->get_depth(), ingredient->get_name(), ingredient->get_key())){
		ingredient->isPickedUp();
		ingredient->set_score(_level);
		_score += ingredient->return_score();
	}else if (ingredient2->checkPickUp() !=  true && player->isHit(ingredient2->get_x(), ingredient2->get_y(), ingredient2->get_depth(), ingredient2->get_name(), ingredient2->get_key())){
		ingredient2->isPickedUp();
		ingredient2->set_score(_level);
		_score += ingredient2->return_score();
	}else if (ingredient3->checkPickUp() !=  true && player->isHit(ingredient3->get_x(), ingredient3->get_y(), ingredient3->get_depth(), ingredient3->get_name(), ingredient3->get_key())){
		ingredient3->isPickedUp();
		if(_level == 1){
			ingredient3->set_score();
		} else{
			ingredient3->set_score(_level);
		}
		_score += ingredient3->return_score();
	}
}

// runs game
void ChefGame::run(){
	while (win->isOpen()){
		Event e;
		while(win->pollEvent(e)){
			if(e.type == Event::Closed){
				win->close();  // close window if closed
			} 
			// B as key for submission -> checking for whether ingredients collected are in correct order
			if (((e.type == e.KeyPressed) && e.key.code == Keyboard::S)){
				if(_level == 0){
					_level = 1;
				}
			} else if (((e.type == e.KeyPressed) && e.key.code == Keyboard::C)){
				// submission button - checks for meal completeness dependent on level, does so by comparing collected 
				// ingredients and their order to specified ingredients and order in meal
				int check_meal;
				std::string lose_message = "You lose.\nPlease close the window.";
				you_lose.setString(lose_message);
				if(_level == 1){
					check_meal = 0;
					for(int i =0; i < 2; i++){
						if(meal1->is_meal_complete(player->get_key(i),i)==true){
							check_meal++;
						}
					}
				} else if (_level == 2){
					check_meal = 0;
					for(int i =0; i < 3; i++){
						if(meal2->is_meal_complete(player->get_key(i),i)==true){
							check_meal++;
						}
					}
				}
				
				// determining whether level is passed
				// if passed and level 1 resets player inventory/keys and ingredient pickup status and sets score
				if(_level == 1 && check_meal == 2){
					_level = 2;
					meal1->set_score();
					_score += meal1->return_score();
					player->reset_inventory();
					player->reset_keys();
					ingredient->reset_pickup();
					ingredient2->reset_pickup();
					ingredient3->reset_pickup();
				} else if (_level == 2 && check_meal == 3){ // if passed and level , sets score
					meal2->set_score();
					_level = 3;
					_score += meal2->return_score();
				}

				// determines win or loss for loss UI 
				if(_level == 1 && check_meal != 2){
					is_lose = true;
				} else if (_level == 2 && check_meal != 3){
					is_lose = true;
				}			
			}
		}

			// clearing frontpage information then drawing gameplay information
			win->clear();
			player->draw(win);
			
			// player movement around window with arrow keys
			if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && _level != 0){
            player->move_left(0.3);
        	} else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && _level != 0){
            player->move_right(0.3);
        	} else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && _level != 0){
            player->move_up(0.3);
        	} else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && _level != 0){
            player->move_down(0.3);
        	} 

			//check for whether ingredient has been collided with
			PickUp();

			// UI for front page
			std::string front_page;
			front_page = "Welcome to Chef Game!\nPress S to play";
			front_page_info.setString(front_page);

			//UI for levels 1 & 2
			//create player inventory UI
			std::string player_inv;
			player_inv = "Player Inventory \nSlot 1 : " + player->getInventory(0) + " " +
			"\nSlot 2 : " + player->getInventory(1) + " " + "\nSlot 3 : " + player->getInventory(2) + " ";
			//need to update the function to include future slots, currently only returns one item in array
			inventory_display.setString(player_inv);
			//set instructions message for gameplay
			std::string game_info = "Collect ingredients in recipe order! \nFind the right colour and collide with ingredients\nusing the arrow keys. Avoid wrong ingredients\nPress C when you think you have a match!";
			play_instructions.setString(game_info);
			std::string recipe_list1 = meal1->show_recipe();
			recipe_display1.setString(recipe_list1);
			std::string recipe_list2 = "Congrats on beating Level 1!\n" + meal2->show_recipe();
			recipe_display2.setString(recipe_list2);
			//display score
			std::string converted_score = std::to_string(_score);
			std::string show_score = "Score: " + converted_score;
			display_score.setString(show_score);
			//end game UI
			std::string ending_message = "Congratulations you finished the game!!!\nYour score is: " + converted_score;
			end_game.setString(ending_message);
		
			//check which level and pass/fail -> drawing appropriate objects
			if (_level == 0){
				win->draw(front_page_info);
			} else if(_level == 1){
				ingredient->draw(win);
				ingredient2->draw(win);
				ingredient3->draw(win);
				win->draw(inventory_display);
				win->draw(play_instructions);
				win->draw(recipe_display1);
				win->draw(display_score);
				if(is_lose == true){
					win->draw(you_lose);
				}
			} else if(_level == 2){
				ingredient->set_position(350,350);
				ingredient2->set_position(400,400);
				ingredient3->set_position(250,300);
				ingredient->draw(win);
				ingredient2->draw(win);
				ingredient3->draw(win);
				win->draw(inventory_display);
				win->draw(play_instructions);
				win->draw(recipe_display2);
				win->draw(display_score);
			} else if (_level == 3){
				win->draw(end_game);
			}
			else if(_level == 2 && is_lose == true){
				win->draw(you_lose);
			}

			// display window with objects
			win->display();
		
		
	}
}

//deconstructor
ChefGame::~ChefGame(){
	delete this->win;
	delete this->ingredient2;
	delete this->ingredient3;
	delete this->ingredient;
	delete this->meal1;
	delete this->meal2;
	delete this->player;
};
