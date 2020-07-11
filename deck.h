/**
    Project Sakura Card
    deck.h
    Purpose: class member function declaration for deck class
    Declare all functions in the deck class

    Author Steveliu29
    Version 1.01  - 10/07/2020
*/

#ifndef _DECK_H_
#define _DECK_H_

class Deck{
private:
    std::vector<Card>     deck_of_cards;
    unsigned int          deck_size;
    void                  perfect_shuffle();
    void                  clear();

public:
    Deck ();
    Deck (unsigned int size);
    void                  operator=               (Deck deck_to_assign);
    Deck                  operator+               (Deck deck_to_add);
    unsigned int          get_deck_size           ();
    Card                  get_card                (unsigned int index);
    bool                  search_card             (Card card_to_search); // simply tell you if the card is in the deck or not
    bool                  search_card             (Card card_to_search, unsigned int& index_to_return); // this also return the index of the card by reference
    void                  add_card                (Card card_to_add, unsigned int index);
    void                  add_card                (Card card_to_add);
    void                  remove_card             (unsigned int index);
    void                  remove_card             ();
    void                  set_size                (unsigned int size);
    void                  set_card                (unsigned int index, Card card_to_set);
    void                  merge_deck              (Deck& deck_to_merge);
    Deck                  split_deck              (unsigned int index);
    void                  random_shuffle          ();
    void                  single_shuffle          (unsigned int n);
};
#endif
