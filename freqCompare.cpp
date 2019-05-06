#include "freqCompare.hpp"

bool freqCompare::operator() (const Node* a, const Node* b){
    return a->freq >= b->freq;
}