/**
    Project Sakura Card
    game.h
    Purpose: class member function declaration for player class
    Declare all functions in the player class

    Author Steveliu29
    Version 1.00  - 13/07/2020
*/

#ifndef _GAME_H_
#define _GAME_H_

#include <string>

enum Combo {Invalid,Double_Element,Element_Arrow,Element_Sword,Freezing_Rain,Invisible,Light_Dark,Maze_Illusion,Maze_Lord,Nightmare,Powerful_Light,Quadra_Element,The_Big,The_Twin,Thunder_Shot,Time_Return,Triple_Element,Water_Shield};

struct User_decision{
    std::vector<unsigned int> card_indice_to_deal;
    bool end_round = false;
};

class Game{
private:
    Deck draw_deck{};
    Deck discard_deck{};
    Deck temp_deck_to_deal{};
    std::vector<Player> group_of_players;
    void merge_discard_to_draw();
    User_decision ask_for_decision();
    void player_deal_card(unsigned int player_index, std::vector<unsigned int> card_indice);
    void check_effect();
    enum Combo combo_check(int card_amount_in_combo,std::vector <Card> card_in_combo);//return the type of the combo

public:
    Game();
    void game_start(unsigned int number_of_players);
    void single_player_draw_card(unsigned int player_index, unsigned int number_of_cards)
    void all_player_draw_card(); // draw to 5 cards at the end of all players' rounds
    void player_round_start(unsigned int player_index);

};



#endif
