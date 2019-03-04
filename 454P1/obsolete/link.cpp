//
//  link.cpp
//  454P1
//
//  Created by Will Lucic on 3/2/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#include "link.hpp"

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
