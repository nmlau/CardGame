//
//  Card.h
//  CardGame
//
//  Created by Nicholas Lau on 3/7/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#ifndef __CardGame__Card__
#define __CardGame__Card__

#include <iostream>
typedef int suit_t;
typedef int rank_t;

class Card {
public:
    Card();
    Card(suit_t s, rank_t r);
    Card(Card * p, Card * n, suit_t s, rank_t r);
    
    /*getters and setters */
    void setSuit(suit_t a);
    suit_t getSuit();
    
    void setRank(rank_t a);
    rank_t getRank();
        
    void setPrev(Card * a);
    Card * getPrev();
    
    void setNext(Card * a);
    Card * getNext();
    
    bool checkSuitRank(suit_t s, rank_t r);
    static void join(Card * a, Card * b);
    void remove();

private:
    suit_t suit;
    rank_t rank;
    Card * prev;
    Card * next;
};

#endif /* defined(__CardGame__Card__) */
