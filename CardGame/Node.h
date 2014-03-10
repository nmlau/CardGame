//
//  Node.h
//  LinkedList
//
//  Created by Nicholas Lau on 11/29/13.
//  Copyright (c) 2013 Nicholas Lau. All rights reserved.
//

#ifndef __LinkedList__Node__
#define __LinkedList__Node__

#include <iostream>
typedef int DATA;

class Node {
    
public:
    /**** Constructors ******/
    Node();
    Node(DATA d);
    Node(Node * p, Node * n, DATA d);
    
    /* getters and setters */
    void setValue(DATA a);
    DATA getValue();
    void setPrevNode(Node * a);
    Node * getPrevNode();
    void setNextNode(Node * a);
    Node * getNextNode();
    
    /* inserts node between nodes */
    static void join(Node * a, Node * b);

private:
    Node * prev;
    Node * next;
    DATA value;
};


#endif /* defined(__LinkedList__Node__) */
