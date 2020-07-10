#include <iostream>
#include "card.h"

void display(){
	std::cout<<"#"<<this->number<<" "<<this->name<<std::endl;
	std::cout<<this->instruction;
}

void operator= (Card card_to_assign){
	this->number=card_to_assign.number;
	this->name=card_to_assign.name;
	this->instruction=card_to_assign.instruction;
}
