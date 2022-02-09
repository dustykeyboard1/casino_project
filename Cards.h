#include <iostream>
#include <vector>

using namespace std;

#ifndef CARDS_H
#define CARDS_H

struct Card {
    char _name;
    size_t _value;
};

class Cards {
private:
    void create_deck();
    vector<Card> deck_of_cards;
public:
    Cards();
    Card return_card(size_t index);
    Card create_new_card(char name, size_t value);
    void print_cards();
};

#endif
