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
    virtual void setValue(DATA a);
    virtual DATA getValue();
    virtual void setPrevNode(Node * a);
    virtual Node * getPrevNode();
    virtual void setNextNode(Node * a);
    virtual Node * getNextNode();
    
    /* inserts node between nodes */
    virtual void join(Node * a, Node * b);

private:
    Node * prev;
    Node * next;
    DATA value;
};


#endif /* defined(__LinkedList__Node__) */
