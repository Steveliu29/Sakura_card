#include <iostream>
#include "card.h"

void Card::display(){
	std::cout<<"#"<<this->number<<" "<<this->name<<std::endl;
	std::cout<<this->instruction;
}

void Card::operator= (Card card_to_assign){
	this->number=card_to_assign.number;
	this->name=card_to_assign.name;
	this->instruction=card_to_assign.instruction;
}
