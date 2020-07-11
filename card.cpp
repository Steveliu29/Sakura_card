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
	//initialization
	result.damage=1;
	result.card_to_defend=1;
	//special cards
	if (name=="Light"||name=="Dark"){
		result.damage=2;
		result.card_to_defend=2;
	}else if (name=="Windy"||name=="Firey"||name=="Watery"||name=="Earthy")
		result.card_to_defend=2;

	return result;
}

Windy::Windy():Card(0){}


