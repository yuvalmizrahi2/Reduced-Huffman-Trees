#pragma once

#include "Node.hpp"
using namespace std;

class freqCompare
{
private:
public:
    bool operator() (const Node*, const Node*);
};
