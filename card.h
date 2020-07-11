#ifndef _CARD_H_
#define _CARD_H_
#include <string>
#include <vector>
#include "card_info.h"

enum Combo {Invalid,Double_Element,Element_Arrow,Element_Sword,Freezing_Rain,Invisible,Light_Dark,Maze_Illusion,Maze_Lord,Nightmare,Powerful_Light,Quadra_Element,The_Big,The_Twin,Thunder_Shot,Time_Return,Triple_Element,Water_Shield};

typedef struct DAMAGE{
	int damage;
	int star;
	int type;//used for some special attacking-defending rules
}Damage;

class Card{
protected:
	//information to display to the player
	int number;
	std::string name;
	std::string instruction;
public:
	Card ();
	Card (int num);
	void display();//show the information of the single card
	void operator = (Card card_to_assign);
	bool operator == (Card card_to_compare); 
	Damage deal_damage();
	int identify();
};

class Windy:public Card{
public:
	Windy ();
	enum Combo combo(int card_amount_in_combo, std::vector <Card> card_in_combo);//return the type of the combo
};

#endif
