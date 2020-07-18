/**
  Project Sakura Card
  game.cpp
Purpose: class member function definition for game class
Define all functions in the game class

Author Steveliu29
Version 1.00  - 13/07/2020
*/

#include "game.h"

// Empty constructor for the Game class
//
Game::Game(){
	const Card card_no_0{0};
	const Card card_no_1{1};
	const Card card_no_2{2};
	const Card card_no_3{3};
	const Card card_no_4{4};
	const Card card_no_5{5};
	const Card card_no_6{6};
	const Card card_no_7{7};
	const Card card_no_8{8};
	const Card card_no_9{9};
	const Card card_no_10{10};
	const Card card_no_11{11};
	const Card card_no_12{12};
	const Card card_no_13{13};
	const Card card_no_14{14};
	const Card card_no_15{15};
	const Card card_no_16{16};
	const Card card_no_17{17};
	const Card card_no_18{18};
	const Card card_no_19{19};
	const Card card_no_20{20};
	const Card card_no_21{21};
	const Card card_no_22{22};
	const Card card_no_23{23};
	const Card card_no_24{24};
	const Card card_no_25{25};
	const Card card_no_26{26};
	const Card card_no_27{27};
	const Card card_no_28{28};
	const Card card_no_29{29};
	const Card card_no_30{30};
	const Card card_no_31{31};
	const Card card_no_32{32};
	const Card card_no_33{33};
	const Card card_no_34{34};
	const Card card_no_35{35};
	const Card card_no_36{36};
	const Card card_no_37{37};
	const Card card_no_38{38};
	const Card card_no_39{39};
	const Card card_no_40{40};
	const Card card_no_41{41};
	const Card card_no_42{42};
	const Card card_no_43{43};
	const Card card_no_44{44};
	const Card card_no_45{45};
	const Card card_no_46{46};
	const Card card_no_47{47};
	const Card card_no_48{48};
	const Card card_no_49{49};
	const Card card_no_50{50};
	const Card card_no_51{51};

	draw_deck.add_card(card_no_0);
	draw_deck.add_card(card_no_1);
	draw_deck.add_card(card_no_2);
	draw_deck.add_card(card_no_3);
	draw_deck.add_card(card_no_4);
	draw_deck.add_card(card_no_5);
	draw_deck.add_card(card_no_6);
	draw_deck.add_card(card_no_7);
	draw_deck.add_card(card_no_8);
	draw_deck.add_card(card_no_9);
	draw_deck.add_card(card_no_10);
	draw_deck.add_card(card_no_11);
	draw_deck.add_card(card_no_12);
	draw_deck.add_card(card_no_13);
	draw_deck.add_card(card_no_14);
	draw_deck.add_card(card_no_15);
	draw_deck.add_card(card_no_16);
	draw_deck.add_card(card_no_17);
	draw_deck.add_card(card_no_18);
	draw_deck.add_card(card_no_19);
	draw_deck.add_card(card_no_20);
	draw_deck.add_card(card_no_21);
	draw_deck.add_card(card_no_22);
	draw_deck.add_card(card_no_23);
	draw_deck.add_card(card_no_24);
	draw_deck.add_card(card_no_25);
	draw_deck.add_card(card_no_26);
	draw_deck.add_card(card_no_27);
	draw_deck.add_card(card_no_28);
	draw_deck.add_card(card_no_29);
	draw_deck.add_card(card_no_30);
	draw_deck.add_card(card_no_31);
	draw_deck.add_card(card_no_32);
	draw_deck.add_card(card_no_33);
	draw_deck.add_card(card_no_34);
	draw_deck.add_card(card_no_35);
	draw_deck.add_card(card_no_36);
	draw_deck.add_card(card_no_37);
	draw_deck.add_card(card_no_38);
	draw_deck.add_card(card_no_39);
	draw_deck.add_card(card_no_40);
	draw_deck.add_card(card_no_41);
	draw_deck.add_card(card_no_42);
	draw_deck.add_card(card_no_43);
	draw_deck.add_card(card_no_44);
	draw_deck.add_card(card_no_45);
	draw_deck.add_card(card_no_46);
	draw_deck.add_card(card_no_47);
	draw_deck.add_card(card_no_48);
	draw_deck.add_card(card_no_49);
	draw_deck.add_card(card_no_50);
	draw_deck.add_card(card_no_51);
}

// Function that shuffle the discard_deck and merge it to draw_deck
//
void Game::merge_discard_to_draw(){
	unsigned int rand_num =  get_cut(10,draw_deck.get_deck_size()) % 51;
	for (auto it = 0; it < rand_num ; it ++){
		unsigned int shuffle_index = get_cut(0,draw_deck.get_deck_size()) % 51;
		draw_deck.single_shuffle(shuffle_index);
	}

	draw_deck.merge_deck(discard_deck);
}

// Function that input users decision
// A struct User_decision is returned
//
User_decision Game::ask_for_decision(unsigned int player_index,std::string type){//type to identify active/passive
	User_decision decision{};
	std::vector<unsigned int> user_input;

	int input=1;
	bool valid=true;
	std::cout<<"Please input the card you want to deal. Input 0 to end the input.";
	while (input!=0){//0 for the end of the input
		std::cin>>input;
		if (input>group_of_players[player_index].get_card_in_hand().get_deck_size()){//check whether the input is valid
			std::cout<<"Invalid card input."<<std::endl;
			input=0;
			valid=false;
		}
		user_input.push_back(input);
	}
	if (!valid) decision=this->ask_for_decision(player_index,type);//ask for another input if this is invalid
	else{
		//assign value to return
		int i=0;
		while (user_input[i]!=0){
			decision.card_indice_to_deal.push_back(group_of_players[player_index].get_card_in_hand().get_card(user_input[i]).identify());
//			this->group_of_players[player_index].deal_card(this->temp_deck_to_deal,user_input[i]);
			i++;
		}

		if (user_input[0]==0)//when the user input a 0 as the first input
			decision.end_round = true;
		else decision.end_round = false;

		//deal the cards to the proper deck
		if (type=="attack"){//check whether it is a valid active card dealing
			if (decision.card_indice_to_deal.size()>1){
				std::vector<Card> tmp_card_vector;
				for (size_t i=0;i<decision.card_indice_to_deal.size();i++){
					Card tmp_card(decision.card_indice_to_deal[i]);
					tmp_card_vector.push_back(tmp_card);
				}
				if(combo_check(decision.card_indice_to_deal.size(),tmp_card_vector)==Invalid){//combo re-asking case
					decision=this->ask_for_decision(player_index,type);
					//ensure that only when the choice is valid, the card will be dealt
					//avoid multiple dealing
					valid=false;
				}
			}
			if (decision.card_indice_to_deal.size()==1&&ATTACK[decision.card_indice_to_deal[0]]==0&&!IS_SCROLL[decision.card_indice_to_deal[0]]){//single card re-asking case
			       	decision=this->ask_for_decision(player_index,type);
				valid=false;
			}
			if (valid)
				for (int j=0;user_input[j]!=0;j++)//deal to the tmp deck for the active cards
					this->group_of_players[player_index].deal_card(this->temp_deck_to_deal,user_input[i]);
		}else if (type=="defend")
			if (valid)
				for (int j=0;user_input[j]!=0;j++)//deal to the discard deck for the passive cards
					this->group_of_players[player_index].deal_card(this->discard_deck,user_input[i]);
	}
	return decision;
}

// Function that allows users to deal card
//
void Game::player_deal_card(unsigned int player_index, std::vector<unsigned int> card_indice){

	for (auto it = 0; it < card_indice.size(); it++)
		group_of_players[player_index].get_card_in_hand().deal_card_to(temp_deck_to_deal,card_indice[it] - it);

}

//Player "dying" ask for a health recover from player "save"
void Game::ask_for_health(unsigned int dying,unsigned int save,int card_index){
	Card tmp_card(card_index);
	unsigned int tmp_index;
	if (group_of_players[save].get_card_in_hand().search_card(tmp_card,tmp_index)){
		std::cout<<"Do you want to use "<<NAME[card_index]<<" to save player "<<dying+1<<"?"<<std::endl;
		std::string choice;
		std::cin>>choice;
		if (choice=="yes"||choice=="Yes"||choice=="YES"||choice=="y"||choice=="Y"){
			group_of_players[dying].add_health(1);
			//deal the card to the discard deck
			group_of_players[save].get_card_in_hand().deal_card_to(this->discard_deck,tmp_index);
		}
	}
}

//Function to handle the dying status
//
void Game::death_settlement(unsigned int player_index,unsigned int dying_index){
	for (unsigned int i; i<this->group_of_players.size()&&group_of_players[dying_index].get_health()<1;i++){//ask for FLOWER or SONG or SWEET
		//enable players to use cards
		this->group_of_players[i].set_enable_card_deal(true);
		if (group_of_players[dying_index].get_health()<1)
			this->ask_for_health(dying_index,i,FLOWER);
		else break;
		if (group_of_players[player_index].get_health()<1)
			this->ask_for_health(dying_index,i,SONG);
		else break;
		if (group_of_players[player_index].get_health()<1)
			this->ask_for_health(dying_index,i,SWEET);
		else break;
		this->group_of_players[i].set_enable_card_deal(false);
	}
	this->group_of_players[player_index].set_enable_card_deal(true);
	//kill the player if no FLOWER or SONG or SWEET is dealt
	if (group_of_players[player_index].get_health()<1) group_of_players[player_index].kill_player();
}

//Function to find element in a vector
static bool find_vector(std::vector<unsigned int>vector_to_search,int element){
	for(std::vector<unsigned int>::iterator it = vector_to_search.begin(); it != vector_to_search.end(); ++it)
		if (*it==element) return true;
	return false;
}


//Function to handle the damage
//
Damage_return_type Game::damage_settlement(Damage damage_to_deal, unsigned int player_index,unsigned int damage_source_index){//return whether the attacking card is RETURNED
	bool if_returned=false;
	Damage result={0,0,0};
	Damage_return_type return_type;
	User_decision decision=this->ask_for_decision(player_index,"defend");
	//have a new array for the defense
	int defend[52];
	for (int i=0;i<52;i++) defend[i]=DEFEND[i];
	//load the special attacking-defending rules
	switch(damage_to_deal.type){
		case WINDY: defend[ELY]=0;break;
		case LIGHT: 
		case DARK: defend[WINDY]=4;defend[SHADOW]=0;defend[FIREY]=4;defend[WATERY]=4;defend[EARTHY]=4;break;
		case FIREY: defend[WOOD]=0;defend[WAVE]=3;break;
		case WATERY: defend[BUBBLES]=0;defend[WAVE]=0;defend[FREEZE]=3;break;
		case EARTHY: defend[WOOD]=3;break;
	}//switch
	if (damage_to_deal.type==DARK) defend[GLOW]=4;
	else defend[GLOW]=0;
	if (damage_to_deal.type==ARROW||damage_to_deal.type==SWORD)
		if (damage_to_deal.star>3) damage_to_deal.star=6;


	//judge whether the choice of the user can defend the attack
	int valid_defend_card_amount=0;
	int valid_defend=0;
	//collect the defend cards
	//First check for Time_Return, Second check for Return, Third check for Time
	//Fourth check for Little, Fifth check for Move, Sixth check for Mirror, Last check for common defending cards
	if (find_vector(decision.card_indice_to_deal,RETURN)&&find_vector(decision.card_indice_to_deal,TIME)){//first check
		damage_to_deal=result;
		//take all the cards into hand
		this->group_of_players[player_index].get_card_in_hand().merge_deck(this->temp_deck_to_deal);
		std::cout<<"Stupid choice. Time is within my control and so is your attack."<<std::endl;
	}else if (find_vector(decision.card_indice_to_deal,RETURN)){//second check
		damage_to_deal=result;
		if_returned=true;
		std::cout<<"Then time starts to flow...Attack cancelled."<<std::endl;
	}else if (find_vector(decision.card_indice_to_deal,TIME)){//third check
		damage_to_deal=result;
		std::cout<<"Time will always forget you with your attack."<<std::endl;
	}else if (find_vector(decision.card_indice_to_deal,LITTLE)){//fourth check
		damage_to_deal.star-=2;
		valid_defend_card_amount=1;
	}else if (find_vector(decision.card_indice_to_deal,MOVE)&&damage_to_deal.star<=2){//fifth check
		std::cout<<"Please choose which player to move the damage to:"<<std::endl;
		unsigned int new_index=this->group_of_players.size();
		std::cin>>new_index;
		new_index--;
		while (new_index>=this->group_of_players.size()||!(group_of_players[new_index].get_is_alive())){
			std::cout<<"Invalid choice. Please input a different ID."<<std::endl;
			std::cin>>new_index;
		}//while
		std::cout<<"Damage moved successfully to player "<<new_index+1<<"!"<<std::endl;
		return_type=this->damage_settlement(damage_to_deal,new_index,player_index);//move the damage
		if_returned=return_type.is_returned;//ensure is_returned will not be cover-written
	}else if (find_vector(decision.card_indice_to_deal,MIRROR)&&
			(damage_to_deal.type==LIGHT||damage_to_deal.type==FIREY||damage_to_deal.type==WATERY||
			 damage_to_deal.type==THUNDER||damage_to_deal.type==SHOT)){//sixth check
		std::cout<<NAME[damage_to_deal.type]<<" reflected!"<<std::endl;
		return_type=this->damage_settlement(damage_to_deal,damage_source_index,player_index);
		if_returned=return_type.is_returned;
	}else{
		if (find_vector(decision.card_indice_to_deal,MOVE)) std::cout<<"Unable to move "<<NAME[damage_to_deal.type]<<"."<<std::endl;
		if (find_vector(decision.card_indice_to_deal,MIRROR)) std::cout<<"Unable to reflect "<<NAME[damage_to_deal.type]<<"."<<std::endl;
		if (group_of_players[player_index].get_status(invisible)>0){//invisible status and maze_lord status should be added here
			damage_to_deal=result;
			std::cout<<"What you attack is only the void."<<std::endl;
		}else if (group_of_players[player_index].get_status(maze_through)>=damage_to_deal.star){
			damage_to_deal.star=0;
			std::cout<<"You will get lost in the maze."<<std::endl<<"Attack defended!"<<std::endl;
		}else if (find_vector(decision.card_indice_to_deal,WATERY)&&find_vector(decision.card_indice_to_deal,SHIELD)){//check for Watery_Shield 
			damage_to_deal=result;
			std::cout<<"Attack defended!"<<std::endl;
		}else{
			if (group_of_players[player_index].get_status(maze_through)>0){
				valid_defend+=group_of_players[player_index].get_status(maze_through);
				std::cout<<"The maze is broken!"<<std::endl;
			}
			for (unsigned int i=0;i<decision.card_indice_to_deal.size();i++){
				if (defend[decision.card_indice_to_deal[i]]>0){//common defend cards
					valid_defend+=defend[decision.card_indice_to_deal[i]];
					valid_defend_card_amount++;
					if (defend[decision.card_indice_to_deal[i]]>2) valid_defend_card_amount++;
				}
			}//for traverse
		}//else for common defend cards
	}//else for status and common defend cards

	//defend checking
	int VALID_AMOUNT=2;
	if (damage_to_deal.star>4) VALID_AMOUNT=damage_to_deal.star/2;
	//special correction for Thunder_Shot
	if (damage_to_deal.type==THUNDER&&damage_to_deal.star==4)
		if (valid_defend<4){
			valid_defend_card_amount=1;
			damage_to_deal.star=5;//ensure that single one-star defend card cannot reduce any damamge
		}

	damage_to_deal.star-=valid_defend;
	if (valid_defend_card_amount>=VALID_AMOUNT||damage_to_deal.star<=0){//successfully defend
		std::cout<<"Defend successfully!"<<std::endl;
		damage_to_deal.damage=0;
		//check for Thunder_Shot combo
		Card tmp_card_1(THUNDER);
		Card tmp_card_2(SHOT);
		if (group_of_players[player_index].get_card_in_hand().search_card(tmp_card_1)&&group_of_players[player_index].get_card_in_hand().search_card(tmp_card_2)){
			std::cout<<"Do you want to use the THUNDER SHOT combo?"<<std::endl;
			std::string choice;
			std::cin>>choice;
			if (choice=="yes"||choice=="YES"||choice=="Yes"||choice=="Y"||choice=="y"){
				//deal THUNDER and SHOT to the discard deck
				unsigned int tmp_index;
				group_of_players[player_index].get_card_in_hand().search_card(tmp_card_1,tmp_index);
				group_of_players[player_index].get_card_in_hand().deal_card_to(this->discard_deck,tmp_index);
				group_of_players[player_index].get_card_in_hand().search_card(tmp_card_2,tmp_index);
				group_of_players[player_index].get_card_in_hand().deal_card_to(this->discard_deck,tmp_index);
				//assign value to the return result
				return_type.is_thunder_shot=true;
				//result.damage=2;
				//result.type=THUNDER;
				//result.star=4;
			}//if choose to thunder_shot
		}//if able to Thunder_Shot
	}//if success
	else{//if fail
		if (damage_to_deal.star<=3) damage_to_deal.damage=1;
		else if(damage_to_deal.star<=5&&damage_to_deal.type!=DARK) damage_to_deal.damage=2;
		std::cout<<"You are damaged by "<<damage_to_deal.damage<<"."<<std::endl;
		group_of_players[player_index].reduce_health((unsigned int)damage_to_deal.damage);
		if (group_of_players[player_index].get_health()<=0)
			this->death_settlement(damage_source_index,player_index);
		damage_to_deal.damage=0;
	}
	
	return_type.is_returned=if_returned;

	//clear the temporary deck after each judgement
	this->discard_deck.merge_deck(temp_deck_to_deal);

	return return_type;
}//function end

// Function that checks the effect of the card in the temp_deck_to_deal
//

void Game::check_effect(){
	if (temp_deck_to_deal.size() > 1){
		enum Combo temp_combo = combo_check(temp_deck_to_deal().get_deck_size(), temp_deck_to_deal.get_all_cards_in_deck());
		if (tempo_combo == Invalid){
			group_of_players[player_index].get_card_in_hand().merge_deck(temp_deck_to_deal);
			std::cout<<"Invalid combo. Please check your card selection."<<std::endl;
			else if (tempo_combo == Double_Element){
			}
			// ADD COMBO EFFECT
		}else if (temp_deck_to_deal.size() == 1){
			Card single_card = temp_deck_to_deal.get_card(0);
			// ADD SINGLE CARD EFFECT
		}else std::cout<<"Please choose a card to deal."<<std::endl;
	}
}


// The function to call a game start by setting the number of players in the game
//
void Game::game_start(unsigned int number_of_players){
	Player temp{};

	for (auto it = 0 ; it < number_of_players ; it++)
		group_of_players.emplace_back(temp);

	unsigned int rand_num =  get_cut(10,draw_deck.get_deck_size()) % 51;
	for (auto it = 0; it < rand_num ; it ++){
		unsigned int shuffle_index = get_cut(0,draw_deck.get_deck_size()) % 51;
		draw_deck.single_shuffle(shuffle_index);
	}
}

// Function to let a single player draw card to its hand
//
void Game::single_player_draw_card(unsigned int player_index, unsigned int number_of_cards){
	if (player_index < group_of_players.size()){

		// Player draws cards to hand
		for (auto it = 0; it < number_of_cards; it++){
			if (0 == draw_deck.get_deck_size()){
				this -> merge_discard_to_draw();
			}

			group_of_players[player_index].add_card_to_hand(draw_deck);
		}
	}
}

// Function that let all players draw 5 card at the end of all players' rounds
//
void Game::all_player_draw_card(){
	for (auto it = 0; it < group_of_players.size(); it++){
		int diff = 5 - group_of_players[it].get_card_in_hand().get_deck_size();
		this -> single_player_draw_card(it,diff);
	}
}

// The function that starts the player's round
//
void Game::player_round_start(unsigned int player_index){
	if (player_index < group_of_players.size() && group_of_players[player_index].get_is_alive()){
		group_of_players[player_index].set_enable_card_deal(true);

		User_decision decision = ask_for_decision(player_index,"attack");
		while (group_of_players[player_index].get_is_alive() && false == decision.end_round){
			player_deal_card(player_index, decision.card_indice_to_deal);
			//check_effect();
			decision = ask_for_decision(player_index,"attack");
		}
		// Unfinished
	}
}

// ***********************************************************************************************


enum Combo Game::combo_check(int card_amount_in_combo, std::vector<Card> card_in_combo){
	enum Combo result;
	switch (card_amount_in_combo){
		case 2: result=combo_check_2cards(card_in_combo);break;
		case 3:
		case 4:	//use recursion to check the element combo
			switch (card_in_combo[card_amount_in_combo-1].identify()){
				case WINDY:
				case FIREY:
				case WATERY:
				case EARTHY: result=combo_check(card_amount_in_combo-1,card_in_combo);
					     if (result!=Invalid) //determine the final result for combo
						     if(card_amount_in_combo==3)
							     result=Triple_Element;
						     else result=Quadra_Element;
					     break;
					     //no combo is valid without an element card
				default: result=Invalid;break;
			}break;
		default: result=Invalid;break;//no combo is valid with more than 4 cards
	}
	return result;
}
