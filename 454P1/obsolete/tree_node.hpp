//
//  tree_node.hpp
//  454P1
//
//  Created by Will Lucic on 3/2/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <string>

using namespace std;

template <typename T>
class treeNode
{
public:
    treeNode(const treeNode<T>* parent);
    treeNode(const treeNode<T>* parent, const T& value);
    ~treeNode();
    
    treeNode<T>* getParent();
    
    T Value();
    T operator=(const T& value);
    T operator=(const treeNode<T>* node);
    
private:
    treeNode<T>* parent;
    T value;
};
/* tree_node_hpp */
