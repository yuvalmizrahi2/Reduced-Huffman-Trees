#include "bitsCompare.hpp"

bool bitsCompare::operator() (const ReduceNode* a, const ReduceNode* b){
    if(((int)a->bits) < ((int)b->bits))
        return true;
    else if(((int)a->bits) > ((int)b->bits))
        return false;
    else if(a->code > b->code)
        return true;
    return false;
}
