#ifndef _DECK_H_
#define _DECK_H_
//This is the deck class
//
class Deck{
private:
    std::vector<Card> deck_of_cards;
    unsigned int deck_size;
    void perfect_shuffle();
    void clear();

public:
    Deck ();
    Deck (unsigned int size);
    void operator= (Deck deck_to_assign);
    Deck operator+ (Deck deck_to_add);
    unsigned int get_deck_size ();
    Card get_card(unsigned int index);
    void add_card(Card card_to_add, unsigned int index);
    void add_card(Card card_to_add);
    void remove_card(unsigned int index);
    void remove_card();
    void set_size(unsigned int size);
    void set_card(unsigned int index, Card card_to_set);
    void merge_deck(Deck& deck_to_merge);
    Deck split_deck(unsigned int index);
    void random_shuffle();
    void single_shuffle(unsigned int n);
};
#endif
