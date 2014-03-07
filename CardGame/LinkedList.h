//
//  LinkedList.h
//  LinkedList
//
//  Created by Nicholas Lau on 11/22/13.
//  Copyright (c) 2013 Nicholas Lau. All rights reserved.
//

#ifndef __LinkedList__LinkedList__
#define __LinkedList__LinkedList__

#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList {
private:
    static int s_count;

public:
    
    Node * head;
    Node * tail;
    int size;
    /**** Constructors ******/
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
        s_count++;
    }
    LinkedList(DATA d) {
        Node * n = new Node(d);
        head = n;
        tail = n;
        size = 1;
        s_count++;
    }
    LinkedList(LinkedList * a) {
        Node * index = a->head;
        //LinkedList newList = new LinkedList(index->data);
        Node * n = new Node(index->getValue());
        head = n;
        tail = n;
        size = 1;
        while ((index->getNextNode()) != NULL) {
            index = index->getNextNode();
            Node::join(tail,new Node(index->getValue()));
            tail = tail->getNextNode();
            size++;
        }
        s_count++;
    }
    ~LinkedList() {
        s_count--;
    }
    /***** Methods ******/
    void addNode(DATA d);
    void removeNode(DATA d);
    void print();
    static void countInstantiations();
    static LinkedList * join(LinkedList * a, LinkedList * b);
    void concatenate(LinkedList * a);
    void removeDuplicates();
    LinkedList * subtract(LinkedList * a);
};


#endif /* defined(__LinkedList__LinkedList__) */
