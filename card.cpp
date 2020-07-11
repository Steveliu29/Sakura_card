#include <iostream>
#include "card.h"
#include "card_info.h"

Card::Card(){
		this -> number 				= 0; // 0 as Card ID represents an empty card
		this -> name 					= "EMPTY";
		this -> instruction 	= "";
}

Card::Card(unsigned int num){
		this -> number=num;
		this -> name=NAME[num];
		this -> instruction=INS[num];
}

void Card::display(){
		std::cout << "#" << this -> number << " " << this -> name << std::endl;
		std::cout << this -> instruction;
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
	if (this->number==LIGHT||this->number==DARK) result.damage=2;
	result.star=ATTACK[this->number];
	result.type=this->number;
	return result;
}

static enum Combo combo_check(int card_num_in_combo;vector <Card> card_in_combo){
	enum Combo result;
	switch (card_num_in_combo){
		case 2: break;//unfinished
		case 3: //finished
		case 4:	//use recursion to check the element combo
			switch (card_in_combo[card_num_in_combo-1].number){
				case WINDY:
				case FIREY:
				case WATERY:
				case EARTHY: result=combo_check(card_num_in_combo-1,card_in_combo);
					     if (result!=invalid) 
						     if(card_num_in_combo==3)
							     result=Triple_Element;
						     else result=Quadra_Element;
					     break;
				default: result=invalid;break;
			}break;
		default: result=invalid;break;
	}
	return result;
}

Windy::Windy():Card(0){}

enum Combo Windy::combo(int card_num_in_combo;vector <Card> card_in_combo){
	//add this card to the vector
	Card this_card(this->number);
	card_in_combo.push_back(this_card);
	return combo_check(card_num_in_combo,card_in_combo);
}
