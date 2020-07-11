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
}

// Function that force to kill a player
//
void Player::kill_player(){
    this -> is_alive = false;
}

// Function that checks whether the player is alive or not
// If the player suppose to be dead, then the function weill set is_alive to false
//
bool Player::check_alive(){
    if (is_alive == false){
        return false;
    }

    else if (this -> health <= 0){
        this -> is_alive = false;
        return false;
    }

    else{
        return true;
    }
}

// Function that reduce player's health
void Player::receive_damage(unsigned int damage){
    this -> health = this -> health - damage;
}
