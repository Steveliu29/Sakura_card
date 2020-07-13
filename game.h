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

class Game{
private:
    Deck draw_deck{};
    Deck discard_deck{};
    std::vector<Player> group_of_players;
    void merge_discard_to_draw();

public:
    Game();
    void game_start(unsigned int number_of_players);
    void single_player_draw_card(unsigned int player_index, unsigned int number_of_cards)
    void all_player_draw_card(); // draw to 5 cards at the end of all player's round
    void player_round_start(unsigned int player_index);
    void player_round_end(unsigned int player_index);
    Combo combo_check(Deck deck_to_check);
};



#endif
