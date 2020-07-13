#include <iostream>
#include <vector>
#include "card.h"
#include "card.cpp"
#include "deck.h"
#include "deck.cpp"
#include "rand.h"
#include "rand.cpp"

int main();

int main(){
    Deck test{};
    Card card0{0};
    Card card1{1};
    Card card2{2};
    Card card3{3};
    Card card4{4};
    Card card5{5};
    Card card6{6};
    Card card7{7};
    Card card8{8};
    Card card9{9};
    Card card10{10};
    Card card11{11};
    Card card12{12};
    Card card13{13};
    Card card14{14};
    Card card15{15};
    Card card16{16};
    Card card17{17};
    Card card18{18};
    Card card19{19};
    Card card20{20};
    Card card21{21};
    Card card22{22};
    Card card23{23};
    Card card24{24};
    Card card25{25};
    Card card26{26};
    Card card27{27};
    Card card28{28};
    Card card29{29};
    Card card30{30};
    Card card31{31};
    Card card32{32};
    Card card33{33};
    Card card34{34};
    Card card35{35};
    Card card36{36};
    Card card37{37};
    Card card38{38};
    Card card39{39};
    Card card40{40};
    Card card41{41};
    Card card42{42};
    Card card43{43};
    Card card44{44};
    Card card45{45};
    Card card46{46};
    Card card47{47};
    Card card48{48};
    Card card49{49};
    Card card50{50};
    Card card51{51};

    test.add_card(card0);
    test.add_card(card1);
    test.add_card(card2);
    test.add_card(card3);
    test.add_card(card4);
    test.add_card(card5);
    test.add_card(card6);
    test.add_card(card7);
    test.add_card(card8);
    test.add_card(card9);
    test.add_card(card10);
    test.add_card(card11);
    test.add_card(card12);
    test.add_card(card13);
    test.add_card(card14);
    test.add_card(card15);
    test.add_card(card16);
    test.add_card(card17);
    test.add_card(card18);
    test.add_card(card19);
    test.add_card(card20);
    test.add_card(card21);
    test.add_card(card22);
    test.add_card(card23);
    test.add_card(card24);
    test.add_card(card25);
    test.add_card(card26);
    test.add_card(card27);
    test.add_card(card28);
    test.add_card(card29);
    test.add_card(card30);
    test.add_card(card31);
    test.add_card(card32);
    test.add_card(card33);
    test.add_card(card34);
    test.add_card(card35);
    test.add_card(card36);
    test.add_card(card37);
    test.add_card(card38);
    test.add_card(card39);
    test.add_card(card40);
    test.add_card(card41);
    test.add_card(card42);
    test.add_card(card43);
    test.add_card(card44);
    test.add_card(card45);
    test.add_card(card46);
    test.add_card(card47);
    test.add_card(card48);
    test.add_card(card49);
    test.add_card(card50);
    test.add_card(card51);

    test.single_shuffle(((unsigned int)get_cut()));
    test.single_shuffle(((unsigned int)get_cut()));
    test.single_shuffle(((unsigned int)get_cut()));
    test.single_shuffle(((unsigned int)get_cut()));
    test.single_shuffle(((unsigned int)get_cut()));
    test.single_shuffle(((unsigned int)get_cut()));
    test.single_shuffle(((unsigned int)get_cut()));
    test.single_shuffle(((unsigned int)get_cut()));
    test.single_shuffle(((unsigned int)get_cut()));
    test.single_shuffle(((unsigned int)get_cut()));
    test.single_shuffle(((unsigned int)get_cut()));

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    for (auto it = 0; it < test.get_deck_size(); it++)
        test.get_card(it).display();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    Deck test2{};

    test.deal_card_to(test2,-1);

    for (auto it = 0; it < test.get_deck_size(); it++)
        test.get_card(it).display();

    std::cout << std::endl;

    for (auto it = 0; it < test2.get_deck_size(); it++)
        test2.get_card(it).display();

    //for (auto it = 0; it < test.get_deck_size(); it++)
      //  test.get_card(it).display();

    return 0;
}
