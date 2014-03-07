//
//  Node.cpp
//  LinkedList
//
//  Created by Nicholas Lau on 11/29/13.
//  Copyright (c) 2013 Nicholas Lau. All rights reserved.
//

#include "Node.h"

Node::Node() {
    prev = NULL;
    next = NULL;
    value = NULL;
}
Node::Node(DATA d) {
    prev = NULL;
    next = NULL;
    value = d;
}
Node::Node(Node * p, Node * n, DATA d) {
    if (p != NULL) {
        prev = p;
    }
    if (n != NULL) {
        next = n;
    }
    value = d;
}
/* getters and setters */
void Node::setValue(DATA a) {value = a;}
DATA Node::getValue() {return value;}
void Node::setPrevNode(Node * a) {prev = a;}
Node * Node::getPrevNode() {return prev;}
void Node::setNextNode(Node * a) {next = a;}
Node * Node::getNextNode() {return next;}

/* inserts node between nodes
   is declared static in .h     */
void Node::join(Node * a, Node * b) {
    if (b != NULL) {
        a->next = b;
        b->prev = a;
    }
    else {
        a->next = NULL;
    }
}
