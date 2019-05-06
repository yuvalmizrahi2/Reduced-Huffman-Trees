#pragma once
#include "Node.hpp"
#include "freqCompare.hpp"
#include <map>
#include <queue>
#include "CodeWord.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>
#include "ReduceNode.hpp"
#include "bitsCompare.hpp"
using namespace std;

class Huffman
{
private:
    /* data */
public:
    Huffman();
    ~Huffman();
    int countChars(map<char, double>&);
    Node* constructTree(map<char, double>&, int = 1);
    ReduceNode* constructTree(map<char, CodeWord>&);
    void getCodeWords(vector<CodeWord>&, const Node&, CodeWord);
    map<char, CodeWord>* canonize(vector<CodeWord>&);
    void reduce(ReduceNode&);
    void skeleton(ReduceNode&);
};

