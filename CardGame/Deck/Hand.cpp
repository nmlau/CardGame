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
 contant int numOfDifferentCardsTotal = 14
 
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
const int numOfDifferentCardsTotal = 14;

double Hand::evaluateHand() {
    //turn hand into a hashmap
    map<rank_t,int> rankHashed;
    map<rank_t,int> & rankMap = rankHashed;
    map<suit_t,int> suitHashed;
    map<suit_t,int> & suitMap = suitHashed;

    handToMap(rankMap, suitMap);
    
    return evaluateHandHashMap(rankMap, suitMap);
}

double Hand::evaluateHandHashMap(map<rank_t, int> & rankMap, map<suit_t, int> & suitMap) {
    
    bool isStraight = false;
    bool isFlush = false;
    bool isFourOfAKind = false;
    bool isThreeOfAKind = false;
    bool isTwoPair = false;
    bool isOnePair = false;
    bool isHighCard = false;
    
//    double highCard = 0.00; //this isn't a complete implementation
    
    for (int i = 0; i<suitMap.size(); i++) {
        if (suitMap[i] == 5) {
            isFlush = true;
        }
    }
    
    for (int i = 0, straightCount = 0; i<rankMap.size(); i++) {
        if (rankMap[i] > 0) {
            straightCount++;
        }
        else {
            straightCount = 0;
        }
        if (straightCount == 5) {
            isStraight = true;
        }
        if (rankMap[i] == 4) {
            isFourOfAKind = true;
        }
        if (rankMap[i] == 3) {
            isThreeOfAKind = true;
        }
        if (rankMap[i] == 2) {
            if(isOnePair) isTwoPair = true;
            isOnePair = true;
        }
        if (rankMap[i] == 1) {
            isHighCard = true;
        }
    }
    if (isFlush && isStraight) {
        return 9.00;
    }
    else if (isFourOfAKind) {
        return 8.00;
    }
    else if (isThreeOfAKind && isTwoPair) {
        return 7.00;
    }
    else if (isFlush) {
        return 6.00;
    }
    else if (isStraight) {
        return 5.00;
    }
    else if (isThreeOfAKind) {
        return 4.00;
    }
    else if (isTwoPair) {
        return 3.00;
    }
    else if (isOnePair) {
        return 2.00;
    }
    else if (isHighCard) {
        return 1.00;
    }
    else {
        return 0.00;
    }
}

void Hand::handToMap(map<rank_t, int> & rankMap, map<suit_t, int> & suitMap) {
    rankToMap(rankMap);
    suitToMap(suitMap);
    
}

/********** Private helper functions *********/

void Hand::rankToMap(map<rank_t, int> & map) {
    for (rank_t index = 1; index < numOfDifferentCardsTotal; index++) {
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

void Hand::suitToMap(map<suit_t, int> & map) {
    for (rank_t index = 1; index < numOfDifferentCardsTotal; index++) {
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

