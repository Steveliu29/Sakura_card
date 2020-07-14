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
User_decision Game::ask_for_decision(unsigned int index){
    User_decision decision{};
    std::vector<unsigned int> user_input;

    int input=1;
    bool valid=true;
    std::cout<<"Please input the card you want to deal. Input 0 to end the input.";
    while (input!=0){//0 for the end of the input
	    std::cin>>input;
	    if (input>group_of_players[index].get_deck_size()){//check whether the input is valid
		    std::cout<<"Invalid card input."<<std::endl;
		    input=0;
		    valid=false;
	    }
	    user_input.push_back(input);
    }
    if (!valid) decision=this->ask_for_decision(index);//ask for another input if this is invalid

    //assign value to return
    int i=0;
    while (user_input[i]!=0){
	    decision.card_indice_to_deal.push_back(group_of_players[index].get_card_in_hand.get_card(user_input[i]).identify());
	    i++;
    }

    if (decision[0]==0)
	    decision.end_round = true;
    else decision.end_round=false;

    return decision;
}

// Function that allows users to deal card
//
void Game::player_deal_card(unsigned int player_index, std::vector<unsigned int> card_indice){

    for (auto it = 0; it < card_indice.size(); it++)
        group_of_players[player_index].get_card_in_hand().deal_card_to(temp_deck_to_deal,card_indice[it] - it);

}

//Function to handle the damage
//
bool Game::damage_settlement(Damage damage_to_deal, int player_index){//bool to check for Thunder_Shot
	while
}

// Function that checks the effect of the card in the temp_deck_to_deal
//
void Game::check_effect(){
    if (temp_deck_to_deal.size() > 1){
        enum Combo temp_combo = combo_check(temp_deck_to_deal().get_deck_size(), temp_deck_to_deal.get_all_cards_in_deck());
        if (tempo_combo == Invalid){
            group_of_players[player_index].get_card_in_hand().merge_deck(temp_deck_to_deal);
	    cout<<"Invalid combo. Please check your card selection."<<endl;
	else if (tempo_combo == Double_Element){

	}
        // ADD COMBO EFFECT
    }else if (temp_deck_to_deal.size() == 1){
        Card single_card = temp_deck_to_deal.get_card(0);
        // ADD SINGLE CARD EFFECT
    }else std::cout<<"Please choose a card to deal."<<endl;

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

        User_decision decision = ask_for_decision();
        while (group_of_players[player_index].get_is_alive() && false == decision.end_round){
            player_deal_card(player_index, decision.card_indice_to_deal);
            check_effect();
            decision = ask_for_decision();
        }
        // Unfinished



    }
}


// ***********************************************************************************************


enum Combo Game::combo_check(int card_amount_in_combo, std::vector<Card> card_in_combo){
	Card this_card(this->number);
	card_in_combo.push_back(this_card);//have all the cards to check combo ready
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
