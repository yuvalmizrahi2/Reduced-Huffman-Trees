#pragma once
#include <iostream>

using namespace std;

class CodeWord
{
private:
    
public:
    char sym;
    unsigned int code;
    unsigned char bits;
    CodeWord();
    ~CodeWord();
    static bool codeWordCompare(const CodeWord&, const CodeWord&);
    friend ostream& operator<<(ostream& os, const CodeWord&);
};
