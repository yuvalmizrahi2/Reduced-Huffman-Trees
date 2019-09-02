#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class NonOptimal
{
    private:
        vector<int> leaves;
        vector<int> numberOfNode;
    public:
        NonOptimal(vector<int>);
        ~NonOptimal();
        int numberAfterReduce(int, int);
        bool isBetterReduce(int, int, int);
        bool chooseReduce(int&);
        void reduceNonOptimal();
};


