//
//  tree.hpp
//  454P1
//
//  Created by Will Lucic on 3/2/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <set>

#include "tree_node.hpp"

using namespace std;

template<typename T>
class tree
{
public:
    tree();
    ~tree();
    treeNode<T>* add(const treeNode<T>* parent, T value);
    
private:
    const treeNode<T>* root;
    set<treeNode<T>> leaves;
    void deleteBranch(treeNode<T>* leaf);
};
/* tree_hpp */
