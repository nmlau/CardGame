//
//  main.cpp
//  LinkedList
//
//  Created by Nicholas Lau on 11/22/13.
//  Copyright (c) 2013 Nicholas Lau. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"


int main(int argc, const char * argv[])
{
    LinkedList * test = new LinkedList(9);
    LinkedList * test2 = new LinkedList(11);
    test2->addNode(10);
    test2->addNode(9);
    test2->addNode(8);
    test2->print();
    test->print();
   // test2 = test2->subtract(test2, test);
    test2 = test2->subtract(test);
    test2->print();
}
