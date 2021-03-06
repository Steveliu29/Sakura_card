/**
    Project Sakura Card
    player.cpp
    Purpose: class member function definition for player class
    Define all functions in the player class

    Author Steveliu29
    Version 1.00  - 11/07/2020
*/

#include "player.h"

// Empty constructor for the Player class
//
Player::Player(){
    this -> health   = 1;
    this -> is_alive = true;
    this -> enable_card_deal = false;
}

// Getter for the health
//
int Player::get_health(){
    return health;
}

// Getter for the card in hand
//
Deck Player::get_card_in_hand(){
    return card_in_hand;
}

// Getter for the card for judgement
//
Deck Player::get_card_for_judgement(){
    return card_for_judgement;
}

// Getter for the is_alive variable
//
bool Player::get_is_alive(){
    return is_alive;
}

// Getter for the enable_player variable
//
bool Player::get_enable_card_deal(){
    return enable_card_deal;
}

// Setter for the is_alive variable
//
void Player::set_is_alive(bool alive_arg){
    this -> is_alive = alive_arg;
}

// Setter for the enable_card_deal argument
//
void Player::set_enable_card_deal(bool enable_arg){
    this -> enable_card_deal = enable_arg;
}

// Getter for the rounds left for a certain status
//
unsigned int Player::get_status (enum Status status_to_get){
    unsigned int rounds_to_return{};
    unsigned int temp_index{};

    if (check_status(status_to_get,temp_index)){
        rounds_to_return = player_status[temp_index].rounds_left;
    }

    return rounds_to_return;
}

// Getter for the player status
//
std::vector<Player_status> Player::get_player_status(){
    return player_status;
}

// Function that force to kill a player
//
void Player::kill_player(){
    this -> is_alive = false;
    this -> enable_card_deal = false;
}

// Function that add a status to the player
//
void Player::add_status(enum Status status_to_add, int rounds_to_add){
    Player_status temp{};
    unsigned int index_to_modify{};

    if (check_status(status_to_add, index_to_modify)){
        player_status[index_to_modify].rounds_left = rounds_to_add;

    }else{
        temp.status = status_to_add;
        temp.rounds_left = rounds_to_add;
        player_status.emplace_back(temp);
    }
}

// Function that remove a status from the plater
//
void Player::remove_status(enum Status status_to_remove){
    unsigned int index_to_remove{};
    if (check_status(status_to_remove,index_to_remove))
            player_status.erase(player_status.begin() + index_to_remove);
}

// Function taht remove the status with zero round left
//
void Player::remove_expired_status(){
    for (int it = static_cast<int> (player_status.size()) - 1; it >= 0; it--){
        if (player_status[it].rounds_left <= 0 && player_status[it].status != judger)
            player_status.erase(player_status.begin() + it);
    }
}

// Function that decrement all rounds by 1
//
void Player::decrement_status_round(){
    for (auto it = 0; it < player_status.size(); it++)
        player_status[it].rounds_left--;
}

// Overloaded function that decrement all rounds by a specific amount
//
void Player::decrement_status_round(int rounds_to_decrease){
    for (auto it = 0; it < player_status.size(); it++)
        player_status[it].rounds_left -= rounds_to_decrease;
}

// Overloaded funtion that decrement the round of one status by 1
//
void Player::decrement_status_round(enum Status status_to_decrement){
    unsigned int index_to_decrement{};

    if (check_status(status_to_decrement, index_to_decrement))
        player_status[index_to_decrement].rounds_left = player_status[index_to_decrement].rounds_left - 1;
}

// Overloaded function that decrement the round of one status by a specific amount
//
void Player::decrement_status_round(enum Status status_to_decrement, int rounds_to_decrease){
    unsigned int index_to_decrement{};

    if (check_status(status_to_decrement, index_to_decrement))
        player_status[index_to_decrement].rounds_left = player_status[index_to_decrement].rounds_left - rounds_to_decrease;
}

// Function that checks if player has the status provided
//
bool Player::check_status(enum Status status_to_check){
    for (auto it = 0; it < player_status.size(); it ++){
        if (player_status[it].status == status_to_check)
            return true;
    }

    return false;
}

// Overloaded function that checks if player has the status provided
// If the status is there, the index in the vector will also be returned
//
bool Player::check_status(enum Status status_to_check, unsigned int& index_to_return){
    for (auto it = 0; it < player_status.size(); it ++){
        if (player_status[it].status == status_to_check){
            index_to_return = it;
            return true;
        }
    }

  return false;
}

// Function that add player's health
//
void Player::add_health(unsigned int health_to_add){
    this -> health = this -> health + health_to_add;
}

// Function that reduce player's health
//
void Player::reduce_health(unsigned int health_to_reduce){
    this -> health = this -> health - health_to_reduce;
}

// Function that get the player a card to hand from other deck
//
void Player::add_card_to_hand(Deck& deck_to_acquire_from){
    deck_to_acquire_from.deal_card_to(card_in_hand);
}

// Overloaded function that get player a card to hand from other deck with dealing index being specified
//
void Player::add_card_to_hand(Deck& deck_to_acquire_from, unsigned int index_to_get){
    deck_to_acquire_from.deal_card_to(card_in_hand, index_to_get);
}

// Function that add a card to judgement zone
// When adding the card to the judgement zone, DO NOT forget remove the original judgement card from other deck
//
void Player::add_card_for_judgement(Card card_to_add){
    card_for_judgement.add_card(card_to_add);
}

// Function that allow player to deal a card
//
void Player::deal_card(Deck& deck_to_receive, unsigned int index_to_deal){
    if (enable_card_deal == true)
        card_in_hand.deal_card_to(deck_to_receive, index_to_deal);
}

// Function that return the card with extreme ID in hand
// max_min_switch = true for largest, false for smallest
//
Card Player::find_extreme_ID_in_hand(bool max_min_switch){
    Card extreme = card_in_hand.get_card(0);

    if (max_min_switch){
        for (auto it = 1; it < card_in_hand.get_deck_size(); it ++){
            if (card_in_hand.get_card(it).identify() > extreme.identify())
                extreme = card_in_hand.get_card(it);
        }
    }

    else{
        for (auto it = 1; it < card_in_hand.get_deck_size(); it ++){
            if (card_in_hand.get_card(it).identify() < extreme.identify())
                extreme = card_in_hand.get_card(it);
        }
    }

    return extreme;
}
