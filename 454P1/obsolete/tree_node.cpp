//
//  tree_node.cpp
//  454P1
//
//  Created by Will Lucic on 3/2/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#include "tree_node.hpp"


template <typename T>
treeNode<T>::treeNode(const treeNode<T>* parent):parent(parent){ }

template <typename T>
treeNode<T>::treeNode(const treeNode<T>* parent, const T& value):parent(parent)
{
    if (sizeof(value) <= sizeof(T)) { this->value = value; }
}

template <typename T>
treeNode<T>::~treeNode() { }

template <typename T>
treeNode<T>* treeNode<T>::getParent()
{
    return parent;
}

template <typename T>
T treeNode<T>::Value()
{
    return value;
}

template <typename T>
T treeNode<T>::operator=(const T &value)
{
    if (sizeof(value) <= sizeof(T)) { this->value = value; }
}

template <typename T>
T treeNode<T>::operator=(const treeNode<T>* node)
{
    this->parent = node->parent;
    this->value = node->value;
}
