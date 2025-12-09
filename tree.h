//
// Created by Manju Muralidharan on 11/22/25.
//

#ifndef FA25EC3_TREE_H
#define FA25EC3_TREE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
   TEMPLATE TREE CLASS
   Multiple parents may point to the same child.
   Students must manage storage, pointers, and dynamic allocation.

   Requirements:
   1. Templated Tree class.
   2. Nodes stored dynamically.
   3. Each node has:
      - id
      - data
      - vector of children pointers
   4. Students must prevent memory leaks.
   5. Students must create createRoot, addNode, findNode, print functions, etc.

   DO NOT IMPLEMENT ANYTHING HERE.
   Only placeholders and TODO comments.
*/


template <typename U>
class Node {
public:
    string id;
    U data;
    vector<Node<U>*> children;

    // TODO: Write constructor
    Node(const string &nodeID, const U &value)
    {
        id = nodeID;
        data = value;
    }
};

template <typename T>
class Tree {
private:
    Node<T>* root;

public:
    Tree()
    {
        root = nullptr;     // Initialize root pointer to nullptr
    }

    void createRoot(const string &id, const T &value)
    {
//        Case 1: Root already exists
        if(root != nullptr)
        {
            return;
        }
//        Case 2: Create root
        root = new Node<T>(id, value);      // Allocate memory, assign id, assign data, set as root
    }

    void addNode(const string &parentID, const string &childID, const T &value)
    {
//        No root to attach a child to
        if(root == nullptr)
        {
            return;
        }

//        Look for parent node
        Node<T>* parent = findNode(parentID);

        if(parent == nullptr)       // Parent not found
        {
            return;
        }

//        Find existing child node, support repeated children under multiple parents
        Node<T>* child = findNode(childID);

//        Case 4: If the child does not exist, create a new node.
        if (child == nullptr)
        {
            child = new Node<T>(childID, value);
        }

//        Link the parent to child.
        parent->children.push_back(child);
    }

    Node<T>* findNode(const string &id);
    // TODO: Use DFS or BFS to search tree

    void printAll();
    // TODO: Print entire structure in readable form

    ~Tree();
    // TODO: Free all allocated memory
};

#endif //FA25EC3_TREE_H
