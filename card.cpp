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
	if (number==LIGHT||number==DARK) result.damage=2;
	result.star=ATTACK[number];
	result.type=number;
	return result;
}

int Card::identify(){return this->number;}

enum Combo Card::combo_check(int card_amount_in_combo, std::vector<Card> card_in_combo){
	Card this_card(this->number);
	card_in_combo.push_back(this_card);//have all the cards to check combo ready
	enum Combo result;
	switch (card_amount_in_combo){
		case 2: break;//unfinished
		case 3: //finished
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
