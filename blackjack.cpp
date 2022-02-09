#include "blackjack.h"



BlackJack::BlackJack() {
    Cards _deck;
    _current_balance = 0;
    _starting_balance = 0;
    srand(time(0));
}

void BlackJack::deal_hand(vector<Card> vect) {
    //cout << "called" << endl;

    size_t index = rand() % 13;
    cout << "random: " << index << endl;
    Card new_card = _deck.return_card(index);
    cout << "New Card: " << new_card._value << endl;
    vect.push_back(new_card);
    cout << vect.size() << endl;
}

void BlackJack::set_balance(size_t balance) {
  _starting_balance = balance;
}

void BlackJack::play_game() {
    string input = " ";
    deal_hand(_player_hand);
    deal_hand(_player_hand);
    deal_hand(_dealer_hand);
    cout << "Your Hand: ";
    show_hand(_player_hand);
    //cout << "Dealer Hand: ";
    show_hand(_dealer_hand);
    cout << "Hit or draw" << endl;
    cout << "Or enter 'end' to quit" << endl;
    while (calculate_total(_player_hand) <= 21 && input != "end") {
        cin >> input;
        if (input == "hit") {
            deal_hand(_player_hand);
            //show_hand(_player_hand);

        } else if (input == "stick") {
            finish_dealer();
            //show_hand(_dealer_hand);
        }
        show_hand(_dealer_hand);
        show_hand(_player_hand);

    }
}

void BlackJack::show_hand(vector<Card> vect) {
    //cout << "size" << _player_hand.size() << endl;
    //cout << vect[0]._value << endl;
    for (size_t index = 0; index < vect.size(); index++) {
        cout << vect[index]._name << ' ' << vect[index]._value << ' ';
    }
    cout << endl;
}

void BlackJack::finish_dealer() {
    while (calculate_total(_dealer_hand) < (size_t) 17) {
        deal_hand(_dealer_hand);
        //calculate_total(_dealer_hand);
    }
}

size_t BlackJack::calculate_total(vector<Card> vect) {
    size_t total = 0;
    for (size_t index = 0; index < vect.size(); index++) {
        total += vect[index]._value;
    }
    return total;
}
