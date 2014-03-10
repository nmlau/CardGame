//
//  Card.cpp
//  CardGame
//
//  Created by Nicholas Lau on 3/7/14.
//  Copyright (c) 2014 Nicholas Lau. All rights reserved.
//

#include "Card.h"


Card::Card(DATA d) {
    node = new Node(d);
}
Card::Card(Node * n) {
    node = n;
}

void Card::setNode(Node * a) {node = a;}
Node * Card::getNode() {return node;}