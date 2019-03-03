//
//  Linked.hpp
//  454P1
//
//  Created by Will Lucic on 3/2/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#ifndef linked_hpp
#define linked_hpp

#include <stdio.h>

using namespace std;

class Link;

template <typename T>

class Linked
{
    Linked();
    Link* getTail();
    Link* getValue();
    Link* getNext();
    
    Link* append(Link* prev, T value);
private:
    Link* tail;
};





#endif /* Linked_hpp */
