//
//  Hand.cpp
//  CardGame
//
//  Created by Nicholas Lau on 3/14/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#include "Hand.h"

void Hand::add(Card * a) {
    this->pushBack(a->getSuit(), a->getRank());
}

/**
 9: Straight Flush = Straight + Flush
 8: Four of a Kind =
 7: Full House = 3 of a kind + 2 of a kind
 6: Flush = 5 of same suit
 5: Straight = 5 in a row (rank)
 4: 3 of a kind
 3: 2 pair
 2: 1 pair
 1: High Card
 */

double Hand::evaluateHand() {
    //turn hand into a hashmap
    map<rank_t,int> hashHand;
    map<rank_t,int> & map = hashHand;
    handToMap(map);
    
    for (int i = 1; i < 14; i++) {
        cout << i << ": " << map[i] <<endl;
    }
    
    
    return 1.00;
}

void Hand::handToMap(map<rank_t, int> & map) {
    for (rank_t index = 1; index < 14; index++) {
        map[index] = 0;
    }
    
    Card * currentCard = this->head;
    while (currentCard != NULL) {
        map[currentCard->getRank()] += 1;
        if (currentCard->getNext() == NULL) {
            break;
        }
        currentCard = currentCard->getNext();
    }

    
}
