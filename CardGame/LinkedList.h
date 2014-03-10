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
#include "Card.h"
using namespace std;
typedef Card * storage_t;

class LinkedList {
private:
    static int s_count;

public:
    
    storage_t head;
    storage_t tail;
    int size;
    
    /**** Constructors ******/
    LinkedList();
    LinkedList(DATA d);
    LinkedList(LinkedList * a);
    ~LinkedList();
    
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
