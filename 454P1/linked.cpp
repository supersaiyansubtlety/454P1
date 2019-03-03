//
//  Linked.cpp
//  454P1
//
//  Created by Will Lucic on 3/2/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#include "linked.hpp"


Linked::Linked()
{
    tail = Link<T>(NULL, NULL, 0);
}

Link* getValue()
{
    return tail->value;
}

Linked::Link* getTail()
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




