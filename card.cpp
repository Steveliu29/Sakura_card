#include <iostream>
#include "card.h"
#include "card_info.h"

Card::Card(){
		this -> number 				= 0; // 0 as Card ID represents an empty card
		this -> name 					= "EMPTY";
		this -> instruction 	= "";
}

Card::Card(int num){
		this -> number=num;
		this -> name=NAME[num];
		this -> instruction=INS[num];
}

void Card::display(){
		std::cout << "#" << this -> number << " " << this -> name << std::endl;
		std::cout << this -> instruction<<std::endl;
}

void Card::operator= (Card card_to_assign){
		this -> number				=	card_to_assign.number;
		this -> name					=	card_to_assign.name;
		this -> instruction		=	card_to_assign.instruction;
}

bool Card::operator== (Card card_to_compare){
		if (this -> number == card_to_compare.number)
				return true;
		else
				return false;
}

Damage Card::deal_damage(){
	Damage result;
	result.damage=1;
	//special cards for the light and dark
	if (number==LIGHT||number==DARK) result.damage=2;
	result.star=ATTACK[number];
	result.type=number;
	return result;
}

int Card::identify(){return this->number;}

static int combo_check_unordered(std::vector<Card> card_in_combo,int card_1,int card_2){
	if (card_in_combo[0].identify()==card_1&&card_in_combo[1].identify()==card_2) return card_1+card_2;
	else if (card_in_combo[0].identify()==card_2&&card_in_combo[1].identify()==card_1) return card_1+card_2;
	else return 0;
}

static enum Combo combo_check_bigtwin(int card_to_check,int big_or_twin){
	enum Combo result=Invalid;
	if (ATTACK[card_to_check]>0) result=The_Big;
	else switch(card_to_check){
		case 3:
		case 8:
		case 10:
		case 11:
		case 14:
		case 30:
		case 32:
		case 33:
		case 36:
		case 43:
		case 44:
		case 46: result=The_Big;break;
		default: result=Invalid;
	}
	if (result!=Invalid)
		if (big_or_twin==BIG)
			result=The_Big;
		else result=The_Twin;
	return result;
}

static enum Combo combo_check_2cards(std::vector<Card> card_in_combo){
	enum Combo result=Invalid;
	//combo except big and twin
	if (combo_check_unordered(card_in_combo,WINDY,FIREY)==WINDY+FIREY||
	    combo_check_unordered(card_in_combo,WINDY,WATERY)==WINDY+WATERY||
	    combo_check_unordered(card_in_combo,WINDY,EARTHY)==WINDY+EARTHY||
	    combo_check_unordered(card_in_combo,FIREY,WATERY)==FIREY+WATERY||
	    combo_check_unordered(card_in_combo,FIREY,EARTHY)==FIREY+EARTHY||
	    combo_check_unordered(card_in_combo,WATERY,EARTHY)==WATERY+EARTHY)
		result=Double_Element;
	else if (combo_check_unordered(card_in_combo,ARROW,LIGHT)==ARROW+LIGHT||
		 combo_check_unordered(card_in_combo,ARROW,FIREY)==ARROW+FIREY||
		 combo_check_unordered(card_in_combo,ARROW,WATERY)==ARROW+WATERY)
		result=Element_Arrow;
	else if (combo_check_unordered(card_in_combo,SWORD,LIGHT)==SWORD+LIGHT||
		 combo_check_unordered(card_in_combo,SWORD,FIREY)==SWORD+FIREY||
		 combo_check_unordered(card_in_combo,SWORD,WATERY)==SWORD+WATERY)
		result=Element_Sword;
	else if (combo_check_unordered(card_in_combo,FREEZE,RAIN)==FREEZE+RAIN)
		result=Freezing_Rain;
	else if (combo_check_unordered(card_in_combo,DARK,SHADOW)==DARK+SHADOW)
		result=Invisible;
	else if (combo_check_unordered(card_in_combo,LIGHT,DARK)==LIGHT+DARK)
		result=Light_Dark;
	else if (combo_check_unordered(card_in_combo,MAZE,ILLUSION)==MAZE+ILLUSION)
		result=Maze_Illusion;
	else if (combo_check_unordered(card_in_combo,MAZE,THROUGH)==MAZE+THROUGH)
		result=Maze_Lord;
	else if (combo_check_unordered(card_in_combo,SLEEP,DREAM)==SLEEP+DREAM)
		result=Nightmare;
	else if (combo_check_unordered(card_in_combo,LIGHT,GLOW)==LIGHT+GLOW)
		result=Powerful_Light;
	else if (combo_check_unordered(card_in_combo,SHOT,THUNDER)==SHOT+THUNDER)
		result=Thunder_Shot;
	else if (combo_check_unordered(card_in_combo,TIME,RETURN)==TIME+RETURN)
		result=Time_Return;
	else if (combo_check_unordered(card_in_combo,WATERY,SHIELD)==WATERY+SHIELD)
		result=Water_Shield;
	//combo check for big and twin
	else if (card_in_combo[0].identify()==BIG||card_in_combo[0].identify()==TWIN)
		result=combo_check_bigtwin(card_in_combo[1].identify(),card_in_combo[0].identify());
	else if (card_in_combo[1].identify()==BIG||card_in_combo[1].identify()==TWIN)
		result=combo_check_bigtwin(card_in_combo[0].identify(),card_in_combo[1].identify());
	//default
	else result=Invalid;

	return result;
}	


enum Combo Card::combo_check(int card_amount_in_combo, std::vector<Card> card_in_combo){
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
