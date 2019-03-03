//
//  link.hpp
//  454P1
//
//  Created by Will Lucic on 3/2/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#ifndef link_hpp
#define link_hpp

#include <stdio.h>

template <typename T>

class Link
{
public:
    Link<T>(Link* parent, Link* prev, T value);
    T getValue();
    Link<T>* getParent();
private:
    Link<T>* prev;
    Link<T>* parent;
    T value;
    
};

#endif /* link_hpp */
