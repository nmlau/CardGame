//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Nicholas Lau on 11/22/13.
//  Copyright (c) 2013 Nicholas Lau. All rights reserved.
//

#include "LinkedList.h"

int LinkedList::s_count = 0;

void LinkedList::addNode(DATA d) {
    //add a null data check
    Node * newTail = new Node(d);
    newTail->join(this->tail, newTail);
    this->tail = newTail;
    size++;
}

//prob a bug here if you call it on head

void LinkedList::removeNode(DATA d) {
    Node * checkNode = this->head;
    while (checkNode != NULL) {
        Node * temp = checkNode->getNextNode();
        if(checkNode->getValue() == d) {
            checkNode->join(checkNode->getPrevNode(),checkNode->getNextNode());
            delete(checkNode);
            size--;
        }
        checkNode = temp;
    }
}


void LinkedList::print() {
    cout << "print out linked list" << endl;
    Node * printNode = this->head;
    cout << printNode->getValue() << endl;
    while (printNode->getNextNode() != NULL) {
        printNode = printNode->getNextNode();
        cout << printNode->getValue() << endl;
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
    (this->tail)->join(this->tail,a->head);
    this->tail = a->tail;
}


void LinkedList::removeDuplicates() {
    Node * current = this->head;
    while (current->getNextNode() != NULL) {
        Node * index = current;
        while (index->getNextNode() != NULL) {
            index = index->getNextNode();
            if(current->getValue() == index->getValue()) {
                index->join(index->getPrevNode(), index->getNextNode());
                delete(index);
            }
        }
        //need this check incase the nested while loop deleted the node after current and current is now then end of the list
        if(current->getNextNode() != NULL) {
            current = current->getNextNode();
        }
    }
}


LinkedList * LinkedList::subtract(LinkedList * a) {
    LinkedList * result = new LinkedList(this);
    Node * current = result->head;
    while (current->getNextNode() != NULL) {
        Node * index = a->head;
        do {
            Node * temp = index->getNextNode();
            if(current->getValue() == index->getValue()) {
                current->join(current->getPrevNode(), current->getNextNode());
                delete(index);
            }
            if (temp != NULL) {
                index = temp;
            }
        } while (index->getNextNode() != NULL);
        current = current->getNextNode();
    }
    return result;
}

