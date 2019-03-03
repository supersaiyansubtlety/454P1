//
//  Linked.cpp
//  454P1
//
//  Created by Will Lucic on 3/2/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#include "Linked.hpp"
using namespace std;

Linked::Linked()
{
    tail = Link(NULL, NULL, 0);
}

Link* Linked::Linked getValue()
{
    return tail->value;
}

Link* Linked::Linked getTail()
{
    return tail->getParent();
}

Linked::Link* getNext()
{
    return link->getNext();
}

Linked::Link* append(Linked* parent, T value)
{
    return tail = new Link(tail, parent, value);
}



Link::Link(Link* parent, Link* prev, T value):parent(parent), prev(prev), value(value){}

Link::Link* getParent()
{
    return parent;
}

Link::Link* getValue()
{
    return value;
}

Link::getPrev()
{
    return prev;
}
