#include <iostream>
#include "card.h"
#include "card_info.h"
#include "deck.h"
#include "game.h"
#include "player.h"
#include "rand.h"

using std::cin;
using std::cout;
using std::endl;

int main(){
	//initialization
	unsigned int player_amount;
	cout<<"Please input the player number:";
	cin>>player_amount;
	Game game;
	game.game_start(player_amount);
	game.all_player_draw_card();
	//game start
	int alive_player=0;
	unsigned alive_id=0;
	unsigned int i=0;
	while (alive_player!=1){//check whether there is only one player left
		for (i=0;i<player_amount;i++){
				game.player_round_start(i);
		}
	}
	cout<<"Player "<<i+1<<" wins"<<endl;
	return 0;
}
	
