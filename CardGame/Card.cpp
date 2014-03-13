//
//  Card.cpp
//  CardGame
//
//  Created by Nicholas Lau on 3/7/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#include "Card.h"


Card::Card() {
    prev = NULL;
    next = NULL;
    rank = NULL;
    suit = NULL;
}
Card::Card(suit_t s, rank_t r) {
    prev = NULL;
    next = NULL;
    suit = s;
    rank = r;
}
Card::Card(Card * p, Card * n, suit_t s, rank_t r) {
    if (p != NULL) {
        prev = p;
    }
    if (n != NULL) {
        next = n;
    }
    suit = s;
    rank = r;
}

/*deep copy */
Card::Card(Card * c) {
    if (c->prev != NULL) { prev = c->prev; }
    if (c->next != NULL) { next = c->next; }
    suit = c->suit;
    rank = c->rank;
}

suit_t Card::getSuit() {return suit;}
rank_t Card::getRank() {return rank;}
void Card::setPrev(Card * a) {prev = a;}
Card * Card::getPrev() {return prev;}
void Card::setNext(Card * a) {next = a;}
Card * Card::getNext() {return next;}


bool Card::checkSuitRank(suit_t s, rank_t r) {
    if (getSuit() == s && getRank() == r) {
        return true;
    }
    return false;
}

/* inserts node between nodes
 is declared static in .h     */
void Card::join(Card * a, Card * b) {
    if (b != NULL && a != NULL) {
        a->next = b;
        b->prev = a;
    }
    else if (a != NULL) {
        a->next = NULL;
    }
    else if (b != NULL) {
        b->prev = NULL;
    }
}

void Card::removeAndDelete() {
    join(this->prev, this->next);
    delete this;
}