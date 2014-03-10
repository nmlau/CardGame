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
#include "Node.h"
typedef char* suit_t;
typedef char* rank_t;

class Card {
public:
    Card();
    Card(suit_t s, rank_t r);
    Card(DATA d);
    Card(Node * n);
    
    void setSuit(suit_t a);
    suit_t getSuit();
    void setRank(rank_t a);
    rank_t getRank();
    void setNode(Node * a);
    Node * getNode();

private:
    suit_t suit;
    rank_t rank;
    Node * node;
    
};

#endif /* defined(__CardGame__Card__) */
