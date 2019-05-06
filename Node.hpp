#pragma once
#include <iostream>

using namespace std;

class Node
{
private:
    void print2DUtil(Node*, int);
public:
    char sym;
    double freq;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
    int child;
    Node(Node&, Node&);
    Node(double, char);
    Node(const Node&);
    ~Node();
    void print();
    friend ostream& operator<<(ostream& os, const Node&);
};
