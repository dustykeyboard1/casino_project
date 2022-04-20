#include "blackjack.h"



BlackJack::BlackJack() {
    Cards _deck;
    _current_balance = 0;
    _starting_balance = 0;
    srand(time(0));
}

void BlackJack::deal_hand(vector<Card>& vect, size_t num_to_deal) {
    //cout << "called" << endl;
    //Card new_card;
    size_t index;
    for (size_t i = 0; i < num_to_deal; i++) {
        index = rand() % 13;
    //cout << "random: " << index << endl;
        _current = _deck.return_card(index);
        vect.push_back(_current);
    }
    //cout << endl;
}

void BlackJack::set_balance(size_t balance) {
  _starting_balance = balance;
}

void BlackJack::play_game() {
    _player_hand.clear();
    _dealer_hand.clear();
    string input = " ";
    deal_hand(_player_hand, 2);
    size_t sum_of_cards;
    //deal_hand(_player_hand);
    deal_hand(_dealer_hand, 2);
    cout << "Your Hand: ";
    show_hand(_player_hand, _player_hand.size());
    cout << "Dealer Hand: ";
    show_hand(_dealer_hand, 1);
    //calculate_total(_dealer_hand);
    cout << "Hit or Stick" << endl;
    cout << "Or enter 'end' to quit" << endl;
    while (calculate_total(_player_hand) <= 21 && input != "end") {
        cin >> input;
        if (input == "hit") {
            deal_hand(_player_hand, 1);
            sum_of_cards = calculate_total(_player_hand);
            if (sum_of_cards > 21) {
                ace_check(_player_hand);
            }
            show_hand(_player_hand, _player_hand.size());

        } else if (input == "stick") {
            finish_dealer();
            show_hand(_dealer_hand, _dealer_hand.size());
            input = "end";
        }
    }
    cout << "The Final Hands were:" << endl;
    cout << "Your Hand:";
    show_hand(_player_hand, _player_hand.size());
    cout << "Dealer Hand:";
    show_hand(_dealer_hand, _dealer_hand.size());
}

void BlackJack::show_hand(vector<Card>& vect, size_t num) {

    //cout << vect[0]._value << endl;
    for (size_t index = 0; index < num; index++) {
        if (vect[index]._value > 10) {
            cout << vect[index]._name << ' ';
        } else {
            cout << vect[index]._value << ' ';
        }
    }
    cout << endl;
}

void BlackJack::finish_dealer() {
    size_t sum_of_Dhand;
    while (calculate_total(_dealer_hand) < (size_t) 17) {
        deal_hand(_dealer_hand, 1);
        sum_of_Dhand = calculate_total(_dealer_hand);
        if (sum_of_Dhand > 21) {
            ace_check(_dealer_hand);
        }

    }
}

size_t BlackJack::calculate_total(vector<Card>& vect) {
    size_t total = 0;
    for (size_t index = 0; index < vect.size(); index++) {
        total += vect[index]._value;
    }
    return total;
}

void BlackJack::ace_check(vector<Card>& vect) {
    for (size_t index = 0; index < vect.size(); index++) {
        if (vect[index]._name == 'A') {
            vect[index]._value = 1;
        }
    }
}
