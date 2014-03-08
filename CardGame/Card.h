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

class Card: public Node {
public:
    Card(): Node() {}
    Card(DATA d): Node(d) {}
    Card(Node * p, Node * n, DATA d): Node(p, n, d) {}
    
protected:
    suit_t suit;
    rank_t rank;
    
    
};


#endif /* defined(__CardGame__Card__) */
