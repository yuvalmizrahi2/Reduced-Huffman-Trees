#pragma once

#include "ReduceNode.hpp"
using namespace std;

class bitsCompare
{
private:
public:
    bool operator() (const ReduceNode*, const ReduceNode*);
};
