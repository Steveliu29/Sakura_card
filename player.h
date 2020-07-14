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
    bool enable_card_deal; // player can only deal card with the player is enabled
    std::vector<enum Status> status;

public:
    Player();
    int                       get_health                        ();
    Deck                      get_card_in_hand                  ();
    Deck                      get_card_for_judgement            ();
    bool                      get_is_alive                      ();
    bool                      get_enable_card_deal              ();
    void                      set_is_alive                      (bool alive_arg);
    void                      set_enable_card_deal              (bool enable_arg);
    std::vector<enum Status>  get_status                        ();
    void                      kill_player                       ();
    void                      add_status                        (enum Status status_to_add);
    void                      remove_status                     (enum Status status_to_remove);
    bool                      check_status                      (enum Status status_to_check);
    bool                      check_status                      (enum Status status_to_check, unsigned int& index_to_return);
    void                      add_health                        (unsigned int health_to_add);
    void                      reduce_health                     (unsigned int health_to_reduce);
    void                      add_card_to_hand                  (Deck& deck_to_acquire_from);
    void                      add_card_to_hand                  (Deck& deck_to_acquire_from, unsigned int index_to_get);
    void                      add_card_for_judgement            (Card card_to_add);
    void                      deal_card                         (Deck& deck_to_receive, unsigned int index_to_deal);
    Card                      find_extreme_ID_in_hand           (bool max_min_switch);
};

#endif
