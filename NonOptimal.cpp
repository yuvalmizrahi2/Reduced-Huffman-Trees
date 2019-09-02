#include "NonOptimal.hpp"

NonOptimal::NonOptimal(vector<int> l){
    copy(l.begin(), l.end(), back_inserter(this->leaves));
    for(unsigned int i = 0; i < leaves.size(); i++)
        numberOfNode.push_back(0);
}

NonOptimal::~NonOptimal(){
}

int NonOptimal::numberAfterReduce(int high, int low){
    int count = 0;
    if(low % 2 == 1)
        low--;
    count += low;
    high += low/2;
    if(high == 0)
        high = 1;
    high = pow(2, floor(log2(high))) ;
    while(high != 1){
        count += high;
        high /= 2;
    }
    return count;
}

bool NonOptimal::isBetterReduce(int high, int middle, int low){
    return numberAfterReduce(high, middle) > numberAfterReduce(middle, low);
}

bool NonOptimal::chooseReduce(int& index){
    int low, high , indexLow;
    if(isBetterReduce(leaves.at(index-1),leaves.at(index),leaves.at(index+1))){
        high = leaves.at(index-1);
        low = leaves.at(index);
        indexLow = index;
        index-=2;
    }
    else{
        high = leaves.at(index);
        low = leaves.at(index+1);
        indexLow = index + 1;
        index-=1;
    }
    int count = 0;
    if(low % 2 == 1)
        low--;
    leaves.at(indexLow) -= low;
    count += 1;
    high += low/2;
    if(high == 0)
        return false;
    high = pow(2, floor(log2(high))) ;
    leaves.at(indexLow - 1) = leaves.at(indexLow - 1) - high + low/2;
    while(high != 1){
        count += 1;
        high /= 2;
    }
    numberOfNode.at(indexLow - count) ++;
    return true;
}

void NonOptimal::reduceNonOptimal(){
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = leaves.size() - 2; i > 0; i = i - 1){
            flag = chooseReduce(i) || flag;
        }
    }
    for(unsigned i = leaves.size() - 1; i > 0; i--){
            numberOfNode.at(i - 1) = numberOfNode.at(i - 1) + (numberOfNode.at(i) + leaves.at(i))/2;
    }
    cout << "number of nodes after reduce and the new idea for ordering the tree: " << 
        accumulate(numberOfNode.begin(), numberOfNode.end(), 0.0) + accumulate(leaves.begin(), leaves.end(), 0.0) + 1
        << endl;
    
}