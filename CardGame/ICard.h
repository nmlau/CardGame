//
//  ICard.h
//  CardGame
//
//  Created by Nicholas Lau on 3/9/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#ifndef __CardGame__ICard__
#define __CardGame__ICard__

#include <iostream>
#include "Node.h"
typedef char* suit_t;
typedef char* rank_t;

class ICard: public Node {
public:
    ICard(): Node() {}
    ICard(DATA d): Node(d) {}
    ICard(Node * p, Node * n, DATA d): Node(p, n, d) {}
    
protected:
    suit_t suit;
    rank_t rank;
    
};


#endif /* defined(__CardGame__ICard__) */
