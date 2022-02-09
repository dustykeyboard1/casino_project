#include <iostream>
//#include "Player.h"
#include <iostream>
//#include <vector>
#include <cstdlib>
#include<ctime>
#include "Cards.h"

using namespace std;

#ifndef BLACKJACK_H
#define BLACKJACK_H

class BlackJack {

public:
    BlackJack();
    void play_game();
    void set_balance(size_t _starting_balance);
    void show_hand(vector<Card> vect);
    void deal_hand(vector<Card> vect);
    void finish_dealer();
    size_t calculate_total(vector<Card> vect);

private:
    size_t _starting_balance;
    size_t _current_balance;
    vector<Card> _dealer_hand;
    vector<Card> _player_hand;
    Cards _deck;




};

#endif
