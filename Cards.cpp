#include "Cards.h"

Cards::Cards() {
    create_deck();
}

void Cards::print_cards() {
    for (size_t index = 0; index < 13; index++) {
        cout << deck_of_cards[index]._value << ' ' << deck_of_cards[index]._name
        << ' ';
    }
    cout << endl;
}

Card Cards::return_card(size_t index) {
    return deck_of_cards[index];
}

void Cards::create_deck() {
    Card new_card;
    for (size_t index = 2; index < 11; index++) {
        char name = (char) index;
        new_card = create_new_card(name, index);
        deck_of_cards.push_back(new_card);
    }
    new_card = create_new_card('J', 10);
    deck_of_cards.push_back(new_card);
    new_card = create_new_card('Q', 10);
    deck_of_cards.push_back(new_card);
    new_card = create_new_card('K', 10);
    deck_of_cards.push_back(new_card);
    new_card = create_new_card('A', 11);
    deck_of_cards.push_back(new_card);
    //print_cards();
}

Card Cards::create_new_card(char name, size_t index) {
    Card new_card;
    new_card._name = name;
    new_card._value = index;
    return new_card;
}
