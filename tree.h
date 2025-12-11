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
    Node<T> *root;

public:
    Tree() {
        root = nullptr;     // Initialize root pointer to nullptr
    }

    void createRoot(const string &id, const T &value) {
//        Case 1: Root already exists
        if (root != nullptr) {
            return;
        }
//        Case 2: Create root
        root = new Node<T>(id, value);      // Allocate memory, assign id, assign data, set as root
    }

    void addNode(const string &parentID, const string &childID, const T &value) {
//        No root to attach a child to
        if (root == nullptr) {
            return;
        }

//        Look for parent node
        Node<T> *parent = findNode(parentID);

        if (parent == nullptr)       // Parent not found
        {
            return;
        }

//        Find existing child node, support repeated children under multiple parents
        Node<T> *child = findNode(childID);

//        If the child does not exist, create a new node.
        if (child == nullptr) {
            child = new Node<T>(childID, value);
        }

//        Link the parent to child.
        parent->children.push_back(child);
    }

    Node<T>* findNode(const string &id)
    {
        // Empty tree, no nodes to find
        if (root == nullptr)
        {
            return nullptr;
        }

        // DFS stack implementation
        vector<Node<T>*> stack;
        stack.push_back(root);

        // Loop until the stack is empty, no remaining nodes
        while (!stack.empty())
        {
            Node<T>* current = stack.back();    // Send current node to back, stack rules (LIFO)
            stack.pop_back();           // Pop node from the stack

            if (current->id == id)      // Check if current node's ID matches the search
            {
                return current;
            }

            // Loop through children
            for (int i = 0; i < current->children.size(); i++)
            {
                Node<T>* child = current->children[i];   // Declare child

                if (child != nullptr)
                {
                    stack.push_back(child);     // Push child onto stack
                }
            }
        }
        return nullptr;     // Node not found
    }

    // Helper function to print a node and its subtree
    void printNode(Node<T>* node)
    {
        if (node == nullptr)
        {
            return;
        }

        cout << "Node " << node->id << ": " << node->data << endl;

        if (node->children.empty())
        {
            cout << "  Child -> (none)" << endl;
        }
        else
        {
            for (int i = 0; i < node->children.size(); i++)
            {
                cout << "  Child -> " << node->children[i]->id << endl;
            }
        }

        cout << endl;

        // Recursively print children
        for (int i = 0; i < node->children.size(); i++)
        {
            printNode(node->children[i]);
        }
    }

    void printAll()     // Prints entire structure in readable form
    {
        if (root == nullptr)
            return;

        printNode(root);
    }


//    ~Tree()     // Destructor
//    {
//        // Case 1: Empty tree
//        if (root == nullptr)
//        {
//            return;
//        }
//
//        // Case 2: Stack for DFS traversal
//        vector<Node<T>*> stack;
//        stack.push_back(root);
//
//        // Case 3: Track visited nodes
//        vector<Node<T>*> visited;
//
//        // DFS loop
//        while (!stack.empty())
//        {
//            // Get node from stack
//            Node<T>* current = stack.back();
//            stack.pop_back();
//
//            // Check if we already deleted this node
//            bool prev = false;
//            for (int i = 0; i < visited.size(); i++)
//            {
//                if (visited[i] == current)
//                {
//                    prev = true;
//                    break;
//                }
//            }
//
//            // Skip if it's already handled
//            if (prev)
//            {
//                continue;
//            }
//
//            // Mark this node as visited
//            visited.push_back(current);
//
//            // Add children to stack for later deletion
//            for (int i = 0; i < current->children.size(); i++)
//            {
//                if (current->children[i] != nullptr)
//                {
//                    stack.push_back(current->children[i]);
//                }
//            }
//
//            // Delete the current node
//            delete current;
//        }
//
//        root = nullptr;
//    }

    ~Tree()
    {
//        If empty, no need to delete. Return
        if (root == nullptr)
        {
            return;
        }

        // Stack for DFS
        vector<Node<T>*> stack;
        stack.push_back(root);

        // Track which nodes we've already deleted
        vector<Node<T>*> visited;

        while (!stack.empty())
        {
            Node<T>* current = stack.back();
            stack.pop_back();

            // Check if we've already seen this node
            bool prev = false;
            for (int i = 0; i < visited.size(); i++)
            {
                if (visited[i] == current)
                {
                    prev = true;
                    break;
                }
            }

            if (prev)
            {
                continue;
            }

            visited.push_back(current);

            // Add children to stack
            for (int i = 0; i < current->children.size(); i++)
            {
                Node<T>* child = current->children[i];
                if (child != nullptr)
                {
                    stack.push_back(child);
                }
            }

            delete current;
        }

        root = nullptr;
    }


    void playGame()
    {
        if (root == nullptr)
        {
            cout << "The story tree is empty. No adventure to play." << endl;
            return;
        }

        cout << "===== Begin Adventure =====" << endl;

        Node<T>* current = root;

        while (true)
        {
            // Show current node's text
            cout << current->data << endl;

            // If no children, the story ends here
            if (current->children.empty())
            {
                cout << "There are no further paths. Your journey ends here." << endl;
                cout << "===== Adventure Complete =====" << endl;
                break;
            }

            // List choices
            cout << "Choose your next action:" << endl;
            for (int i = 0; i < current->children.size(); i++)
            {
                cout << (i + 1) << ". " << current->children[i]->data << endl;
            }

            int selection = 0;

            // Get a valid selection
            while (true)
            {
                cout << "Selection: ";

                if (!(cin >> selection))
                {
                    // Not a number
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    continue;
                }

                // Clear leftover newline
                cin.ignore(1000, '\n');

                // Check range
                if (selection < 1 || selection > current->children.size())
                {
                    cout << "Invalid choice. Please enter a number between 1 and "
                         << current->children.size() << "." << endl;
                    continue;
                }

                break;
            }

            // Move to the chosen child
            current = current->children[selection - 1];
        }
    }

};

#endif //FA25EC3_TREE_H
