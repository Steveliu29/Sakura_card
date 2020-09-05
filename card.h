#ifndef _CARD_H_
#define _CARD_H_
#include <string>
#include <vector>
#include "card_info.h"

enum Combo {Invalid,Big_Attack,Big_Delay,Big_Scroll,Big_Twin,Double_Element,Element_Arrow,Element_Sword,Freezing_Rain,Invisible,Light_Dark,Maze_Illusion,Maze_Lord,Nightmare,Powerful_Light,Quadra_Element,Thunder_Shot,Time_Return,Triple_Element,Twin_Attack,Twin_Delay,Twin_Scroll,Water_Shield};

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
	enum Combo combo_check(int card_amount_in_combo,std::vector <Card> card_in_combo);//return the type of the combo
};

int combo_check_unordered(std::vector<Card> card_in_combo,int card_1,int card_2);

enum Combo combo_check_bigtwin(int card_to_check,int big_or_twin);

enum Combo combo_check_2cards(std::vector<Card> card_in_combo);
/*
class Windy:public Card{
public:
	Windy ();
};
*/
#endif
