//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Nicholas Lau on 11/22/13.
//  Copyright (c) 2013 Nicholas Lau. All rights reserved.
//

#include "LinkedList.h"

int LinkedList::s_count = 0;

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
    s_count++;
}

LinkedList::LinkedList(DATA d) {
    storage_t n = new Card(d);
    head = n;
    tail = n;
    size = 1;
    s_count++;
}

LinkedList::LinkedList(LinkedList * a) {
    storage_t index = a->head;
    //LinkedList newList = new LinkedList(index->data);
    storage_t n = new Card(index->getNode()->getValue());
    head = n;
    tail = n;
    size = 1;
    while ((index->getNode()->getNextNode()) != NULL) {
        index->setNode(index->getNode()->getNextNode());
        Node::join(tail->getNode(),new Node(index->getNode()->getValue()));
        tail->setNode(tail->getNode()->getNextNode());
        size++;
    }
    s_count++;
}

LinkedList::~LinkedList() {
    s_count--;
}

void LinkedList::addNode(DATA d) {
    //add a null data check
    storage_t newTail = new Card(d);
    Node::join(this->tail->getNode(), newTail->getNode());
    this->tail = newTail;
    size++;
}

//prob a bug here if you call it on head

void LinkedList::removeNode(DATA d) {
    storage_t checkNode = this->head;
    while (checkNode != NULL) {
        storage_t temp = new Card(checkNode->getNode()->getNextNode());
        if(checkNode->getNode()->getValue() == d) {
            Node::join(checkNode->getNode()->getPrevNode(),checkNode->getNode()->getNextNode());
            delete(checkNode);
            size--;
        }
        checkNode = temp;
    }
}


void LinkedList::print() {
    cout << "print out linked list" << endl;
    storage_t printNode = this->head;
    cout << printNode->getNode()->getValue() << endl;
    while (printNode->getNode()->getNextNode() != NULL) {
        printNode->setNode(printNode->getNode()->getNextNode());
        cout << printNode->getNode()->getValue() << endl;
    }
    cout << "end print" << endl;
}

/* static */
void LinkedList::countInstantiations() {
    cout << "There is/are " << s_count << " Linked List Instantiation(s)" << endl;
}

/* static */
LinkedList * LinkedList::join(LinkedList * a, LinkedList * b) {
    LinkedList * deepCopyA = new LinkedList(a);
    LinkedList * deepCopyB = new LinkedList(b);
    deepCopyA->concatenate(deepCopyB);
    
    return deepCopyA;
}

/*
 Concatenates a deep copy of paramter 'a' onto calling object
 */
void LinkedList::concatenate(LinkedList * a) {
    Node::join(this->tail->getNode(),a->head->getNode());
    this->tail = a->tail;
}


void LinkedList::removeDuplicates() {
    storage_t current = this->head;
    while (current->getNode()->getNextNode() != NULL) {
        storage_t index = current;
        while (index->getNode()->getNextNode() != NULL) {
            index->setNode(index->getNode()->getNextNode());
            if(current->getNode()->getValue() == index->getNode()->getValue()) {
                Node::join(index->getNode()->getPrevNode(), index->getNode()->getNextNode());
                delete(index);
            }
        }
        //need this check incase the nested while loop deleted the node after current and current is now then end of the list
        if(current->getNode()->getNextNode() != NULL) {
            current->setNode(current->getNode()->getNextNode());
        }
    }
}


LinkedList * LinkedList::subtract(LinkedList * a) {
    LinkedList * result = new LinkedList(this);
    storage_t current = result->head;
    while (current->getNode()->getNextNode() != NULL) {
        storage_t index = a->head;
        do {
            storage_t temp = new Card(index->getNode()->getNextNode());
            if(current->getNode()->getValue() == index->getNode()->getValue()) {
                Node::join(current->getNode()->getPrevNode(), current->getNode()->getNextNode());
                delete(index);
            }
            if (temp != NULL) {
                index = temp;
            }
        } while (index->getNode()->getNextNode() != NULL);
        current->setNode(current->getNode()->getNextNode());
    }
    return result;
}

