//
//  tree.cpp
//  454P1
//
//  Created by Will Lucic on 3/2/19.
//  Copyright © 2019 Will-Martin. All rights reserved.
//

#include "tree.hpp"

template <typename T>
treeNode<T>::treeNode(const treeNode<T>* parent):parent(parent){ }

template <typename T>
treeNode<T>::treeNode(const treeNode<T>* parent, const T& value):parent(parent)
{
    if (sizeof(value) <= sizeof(T)) { this->value = value; }
}

//template <typename T>
//treeNode<T>::~treeNode() { }

template <typename T>
treeNode<T>* treeNode<T>::getParent()
{
    return parent;
}

template <typename T>
T treeNode<T>::getValue()
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


template<typename T>
tree<T>::tree():root(new treeNode<T>()) { }

template<typename T>
tree<T>::~tree() {  for (auto leaf : leaves) { deleteBranch(leaf); }  }

template<typename T>
treeNode<T>* tree<T>::getRoot()
{
    return root;
}

template<typename T>
treeNode<T>* tree<T>::add(const treeNode<T>* parent, T value)
{
    treeNode<T>* node = new treeNode<T>(parent, value);
    leaves.erase(leaves.find(parent));
    leaves.insert(node);
}

template<typename T>
void tree<T>::deleteBranch(treeNode<T>* leaf)
{
    if (leaf->getParent()) { deleteBranch(leaf->getParent()); }
    delete leaf;
}
