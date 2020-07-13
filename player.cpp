/**
    Project Sakura Card
    player.cpp
    Purpose: class member function definition for player class
    Define all functions in the player class

    Author Steveliu29
    Version 1.00  - 11/07/2020
*/

// Empty constructor for the Player class
//
Player::Player(){
    this -> health   = 1;
    this -> is_alive = true;
    this -> get_enable_card_deal = false;
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

// Getter for the player status
//
std::vector<enum Status> Player::get_status(){
    return status;
}

// Function that force to kill a player
//
void Player::kill_player(){
    this -> is_alive = false;
    this -> get_enable_card_deal = false;
}

// Function that checks if player has the status provided
//
bool Player::check_status(enum Status status_to_check){
    for (auto it = 0; it < status.size(); it ++){
        if (status[it] == status_to_check)
            return true;
    }

    return false;
}

// Overloaded function that checks if player has the status provided
// If the status is there, the index in the vector will also be returned
//
bool Player::check_status(enum Status status_to_check, unsinged int& index_to_return){
    for (auto it = 0; it < status.size(); it ++){
        if (status[it] == status_to_check){
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
void Player::get_card_to_hand(Deck& deck_to_acquire_from){
    deck_to_acquire_from.deal_card_to(card_in_hand);
}

// Overloaded function that get player a card to hand from other deck with dealing index being specified
//
void Player::get_card_to_hand(Deck& deck_to_acquire_from, unsigned int index_to_get){
    deck_to_acquire_from.deal_card_to(card_in_hand, index_to_get);
}

// Function that add a card to judgement zone
// When adding the card to the judgement zone, DO NOT forget remove the original judgement card from other deck
//
void Player::get_card_for_judgement(Card card_to_add){
    card_for_judgement.add_card(card_to_add);
}

// Function that allow player to deal a card
//
void Player::deal_card(Deck& deck_to_receive, unsigned int index_to_deal){
    if (enable_card_deal == true)
        card_in_hand.deal_card_to(deck_to_receive, index_to_deal);
}

// Function that return the largest ID in hand
//
int Player::find_max_ID_in_hand(){
    int max = card_in_hand.get_card(0).identify();

    for (auto it = 1; it < card_in_hand.get_deck_size(); it ++){
        if (card_in_hand.get_card(it).identify() > max)
            max = card_in_hand.get_card(it).identify();
    }

    return max;
}

// Function that return the smalleest ID in hand
//
int Player::find_min_ID_in_hand(){
    int min = card_in_hand.get_card(0).identify();

    for (auto it = 1; it < card_in_hand.get_deck_size(); it ++){
        if (card_in_hand.get_card(it).identify() < min)
            min = card_in_hand.get_card(it).identify();
    }

    return min;
}
