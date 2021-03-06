/**
    Project Sakura Card
    deck.cpp
    Purpose: class member function definition for deck class
    Implement all functions in the deck class

    Author Steveliu29
    Version 1.01  - 10/07/2020
*/

#include "deck.h"

// Operator '=' is overloaded to assign the value of one deck to the other
//
void Deck::operator= (Deck deck_to_assign){
    deck_of_cards.clear();
    for (auto it = 0; it < deck_to_assign.get_deck_size(); it ++)
        this -> add_card(deck_to_assign.get_card(it));
    this -> deck_size = deck_to_assign.get_deck_size();
}

// Operator '+' is overloaded to add all the deck from one deck to the end of this deck
Deck Deck::operator+ (Deck deck_to_add){
    Deck deck_to_return{};

    for (auto it = 0; it < deck_size; it ++)
         deck_to_return.add_card(deck_of_cards[it]);

    for (auto it = 0; it < deck_to_add.get_deck_size(); it ++)
         deck_to_return.add_card(deck_to_add.get_card(it));

    return deck_to_return;
}

// Empty constructor
//
Deck::Deck(){
    this -> deck_size = 0;
}

// Constructor with specific size being set
// Empty cards are added to the Deck by default
// You can later change the cards to something else with set_card() function
//
Deck::Deck(unsigned int size){
    Card empty_card{};
    for (auto it = 0; it < size; it ++)
        deck_of_cards.emplace_back(empty_card);
    this -> deck_size = size;
}

// Funtion that clears all the element in a deck
//
void Deck::clear(){
    deck_of_cards.clear();
    this -> deck_size = 0;
}

// Getter for the deck size
//
unsigned int Deck::get_deck_size(){
    return this -> deck_size;
}

// Getter for the Card vector in Deck
//
std::vector<Card> Deck::get_all_cards_in_deck(){
    return deck_of_cards;
}

// Getter for a card in the deck
// return the card at specific index
//
Card Deck::get_card(unsigned int index){
    return this -> deck_of_cards[index];
}

// Function check if the current deck is empty
//
bool Deck::isEmpty(){
    if (deck_size == 0)
        return true;
    else
        return false;
}

// Function that linearly searches for a card in the deck
// return TRUE if the card is in the deck, FALSE if not in the deck
//
bool Deck::search_card(Card card_to_search){
    for (auto it = 0; it < deck_size; it++){
        if (card_to_search == deck_of_cards[it])
            return true;
    }
    return false;
}

// Overloaded Function for the previous linear search function
// the index of the card is returned by reference
//
bool Deck::search_card(Card card_to_search, unsigned int& index_to_return){
    for (auto it = 0; it < deck_size; it++){
        if (card_to_search == deck_of_cards[it]){
            index_to_return = it;
            return true;
        }
    }
    return false;
}

// Function that adds a card to a specific index
// The card will be placed on the index provided, the original card on the same index will be pushed to the next index.
// The same applies to the latter cards. All the cards after the provided index will be shifted by 1 index
//
void Deck::add_card(Card card_to_add, unsigned int index){
    if (index < this -> deck_size){
        deck_of_cards.insert(deck_of_cards.begin()+ index, card_to_add);
        this -> deck_size++;
    }
    else{
        // EXCEPTIONS SHOULD BE DEFINED FOR INVALID INSERTION AT UNREASEONABLE INDEX
    }
}

// Overloaded function that adds a card to a specific index, the default position to add is the end of deck
//
void Deck::add_card(Card card_to_add){
    deck_of_cards.emplace_back(card_to_add);
    this -> deck_size++;
}

// Function that removes a card from the deck.
//
void Deck::remove_card(unsigned int index){
    if (index < this -> deck_size){
        deck_of_cards.erase(deck_of_cards.begin() + index);
        this -> deck_size--;
    }
}

// Overloaded Function that removes a card from the deck.The default index for removal is the end of deck
//
void Deck::remove_card(){
    if (this -> deck_size > 0){
        deck_of_cards.erase( deck_of_cards.end() );
        this -> deck_size--;
    }
}

// Function that sets the size for the deck
// You can use this function to resize the deck
// **If the size set is larger than the original size, empty cards will be added to the end of the deck
// ****WARNING: If the size set is smaller than the original size, the cards at the end will be lost
// This function is for developing and testing purpose, always use add_card function to add a card
//
void Deck::set_size(unsigned int size){
    unsigned int diff = labs(size - deck_size);

    for (auto it = 0; it < diff; it ++){
        if (size > deck_size){
            Card empty_card{};
            this -> add_card(empty_card);
        }
        else if (size < deck_size){
            this -> remove_card();
        }
    }
}

// Function that changes a card to another card
//
void Deck::set_card(unsigned int index, Card card_to_set){
    // the operator '=' needs to be overloaded
    //
    deck_of_cards[index] = card_to_set;
}

// Function that merges two deck of cards
// The deck_to_merge will be added to the end
// The deck_to_merge will be destroyed after the merge
//
void Deck::merge_deck(Deck& deck_to_merge){
    for (auto it = 0; it < deck_to_merge.get_deck_size(); it ++)
        this -> add_card(deck_to_merge.get_card(it));
    deck_to_merge.clear();
}

// Function that splits the deck at a particular index
// The function will return the deck being splitted AFTER the index (include the card at the index)
// THe first card in the deck will the card at the provided index
// The original use of the function is for perfect_shuffle
// It might have some interesting usage, so I put it in public class
//
Deck Deck::split_deck(unsigned int index){
    if (index < this -> deck_size){
        Deck deck_splitted{};

        // Since the deck_size will decrease by 1 everytime we remove a card from it
        // We can keep removing at the same index until the deck_size shrink to be less than the index
        //
        while (index < this -> deck_size){
            deck_splitted.add_card(deck_of_cards[index]);
            this -> remove_card(index);
        }
        return deck_splitted;
    }
}

// This function does a perfect shuffle on the current deck of cards
// e.g. 1 2 3 4 5 6 after shuffle -> 4 1 5 2 6 3
// e,g, 1 2 3 4 5 6 7 after shuffle -> 4 1 5 2 6 3 7
//
void Deck::perfect_shuffle(){
    unsigned int half = deck_size / 2;

    Deck half_deck = split_deck(half);

    for (auto it = 0 ; it < half_deck.get_deck_size() ; it ++)
        this -> add_card(half_deck.get_card(it), it*2);

    half_deck.clear();
}

void Deck::single_shuffle(unsigned int n)
{
	unsigned int change;
	//for the cards that has been used
	//reset the encoded suit
	//all the cards used are at the left most position of the deck

	//construct a new deck
	Card deck_tmp[deck_size];

	if (n>deck_size/2)
	{
		//alternative selection
		for(change=0;change<deck_size-n;change++)
		{
			deck_tmp[change*2]=deck_of_cards[n+change];
			deck_tmp[change*2+1]=deck_of_cards[change];
		}
		//load the remaining cards
		for(change=deck_size-n;change<n;change++)
			deck_tmp[deck_size-n+change]=deck_of_cards[change];
	}else{
		for(change=0;change<n;change++)
		{
			deck_tmp[change*2]=deck_of_cards[n+change];
			deck_tmp[change*2+1]=deck_of_cards[change];
		}
		for(change=2*n;change<deck_size;change++)
			deck_tmp[change]=deck_of_cards[change];
	}
	//assign the new deck to the old deck
	for (change=0;change<deck_size;change++)
		deck_of_cards[change]=deck_tmp[change];
}

// Function deal card from the current deck to another deck
// By default, the first card will be dealt
//
void Deck::deal_card_to (Deck& deck_to_receive){
    if (!isEmpty()){
        deck_to_receive.add_card(this -> deck_of_cards[0]);
        this -> remove_card(0);
    }
}

// Overloaded function deal card from the current deck to another deck
// You can choose the index of the card you want to deal from the current deck
//
void Deck::deal_card_to (Deck& deck_to_receive, unsigned int index_to_deal){
    if (index_to_deal < this -> deck_size){
        deck_to_receive.add_card(this -> deck_of_cards[index_to_deal]);
        this -> remove_card(index_to_deal);
    }
}

// Function that displays the entire deck of card
//
void Deck::display(){
    for (auto it = 0; it < deck_size; it++){
        std::cout << it + 1 << ". ";
        std::cout << NAME[deck_of_cards[it].identify()] << std::endl;
    }
}
