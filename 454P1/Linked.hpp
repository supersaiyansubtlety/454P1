//
//  Linked.hpp
//  454P1
//
//  Created by Will Lucic on 3/2/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#ifndef Linked_hpp
#define Linked_hpp

#include <stdio.h>

using namespace std;

template <class T>

class Linked;
class Link;

class Linked
{
    Linked();
    
    Link* getTail();
    Link* getValue();
    Link* getNext();
    
    Link* append(Linke* prev, T value);
private:
    Link* tail;
};

class Link
{
public:
    Link(Link* parent, Link* prev, T value);
    T getValue();
    Link* getParent();
private
    Link* prev;
    Link* parent;
    T value;
    
};



#endif /* Linked_hpp */
