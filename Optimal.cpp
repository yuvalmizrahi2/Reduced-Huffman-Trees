#include "Optimal.hpp"

int Optimal::num_to_bits[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

Optimal::Optimal(){
}

Optimal::~Optimal(){
}

void Optimal::optimalReduced(vector<int> q){
    q.insert(q.begin(), 0);
    int** PT = new int*[q.size()];
    PT[0] = new int[1];
    PT[0][0] = 0;
    for (int i = 1; i < (int)q.size(); i++)
    {
        PT[i] = new int[q.at(i) + 1];
        for (int j = 0; j <= q.at(i); j++)
        {
            PT[i][j] = numeric_limits<int>::max();
        }
    }
    for (int i = 1; i < (int)q.size(); i++)
    {
     for (int y = 0; y <= q.at(i); y++)
        {
            for (int x = 0; x <= q.at(i-1) ; x++)
            {
                PT[i][y] = min(PT[i][y], PT[i-1][x] + N1B(2*(q.at(i-1) - x) + y));
            }
        }
        
    }
    cout << "number of nodes after optimal reduce: " <<  2 * PT[q.size()-1][q.at(q.size()-1)] - 1 << endl;
}

int Optimal::N1B(int z){
    int nibble = 0;  
    if (0 == z)  
        return num_to_bits[0];  
      
    // Find last nibble  
    nibble = z & 0xf;  
      
    // Use pre-stored values to find count  
    // in last nibble plus recursively add  
    // remaining nibbles.  
    return num_to_bits[nibble] +  
            N1B(z >> 4);  
}