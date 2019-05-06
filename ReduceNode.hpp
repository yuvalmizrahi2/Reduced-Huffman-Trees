#pragma once
#include <iostream>
#include<algorithm> 
using namespace std;

class ReduceNode
{
private:
    void print2DUtil(ReduceNode*, int);
public:
    char sym;
    unsigned int code;
    unsigned char bits;
    int max;
    int min;
    int child;
    ReduceNode* leftChild = nullptr;
    ReduceNode* rightChild = nullptr;
    ReduceNode(ReduceNode&, ReduceNode&);
    ReduceNode(char, unsigned int, unsigned char);
    ReduceNode(const ReduceNode&);
    ~ReduceNode();
    void print();
    friend ostream& operator<<(ostream& os, const ReduceNode&);
};
