#ifndef _CARD_H_
#define _CARD_H_
#include <string>
class Card{
private:
	//information to display to the player
	unsigned int number;
	string name;
	string instruction;
public:
	void display();//show the information of the single card
	void operator = (Card card_to_assign);
};
#endif
