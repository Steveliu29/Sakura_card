#ifndef _CARD_H_
#define _CARD_H_
#include <string>
#include "card_info.h"

struct DAMAGE{
	int damage;
	int card_to_defend;
	enum Damage_Type type;
}Damage;

class Card{
private:
	//information to display to the player
	unsigned int number;
	std::string name;
	std::string instruction;
public:
	Card ();
	void display();//show the information of the single card
	void operator = (Card card_to_assign);
	bool operator == (Card card_to_compare); 
	Damage deal_damage();
};

class Windy:public Card(){
public:
	Windy ();
	int combo(int card_num_in_combo, Card card_in_combo);//return the damage
};

#endif
