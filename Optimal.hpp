#pragma once
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;

class Optimal
{
private:
    static int num_to_bits[16]; 
    static int N1B(int);
public:
    Optimal();
    ~Optimal();
    static void optimalReduced(vector<int>);
};
