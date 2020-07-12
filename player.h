/**
    Project Sakura Card
    player.h
    Purpose: class member function declaration for player class
    Declare all functions in the player class

    Author Steveliu29
    Version 1.00  - 11/07/2020
*/

#ifndef _PLAYER_H_
#define _PLAYER_H_

enum Status{
    invisible,
    nightmare,
    judger,
    maze_through
};

class Player{
private:
    int health;
    Deck card_in_hand{};
    Deck card_for_judgement{};
    bool is_alive;
    bool enable_card_deal;
    std::vector<enum Status> status;

public:
    Player();
    void kill_player();
    bool check_alive();
    void receive_damage(unsigned int damage);
    void get_card(Deck& deck_to_acquire_from, unsigned int number_of_cards);
    // The deck to receive the card to be specified, we need info about the card
    // void deal_card(unsigned int index_to_deal);
};

#endif
