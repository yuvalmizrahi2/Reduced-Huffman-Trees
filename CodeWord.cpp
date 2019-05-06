#include "CodeWord.hpp"

CodeWord::CodeWord(){
}

CodeWord::~CodeWord(){
}

bool CodeWord::codeWordCompare(const CodeWord& a, const CodeWord& b){
    if(a.bits > b.bits)
        return true;
    else if(a.bits < b.bits)
        return false;
    else if(a.sym <= b.sym)
        return true;
    return false;
}

ostream& operator<<(ostream& os, const CodeWord& codeword){
    os << "sym: " << codeword.sym << " code: " << codeword.code << " bits: " << (int)codeword.bits;
    return os;
}