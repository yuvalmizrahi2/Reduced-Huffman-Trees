#include "ReduceNode.hpp"

ReduceNode::ReduceNode(ReduceNode& left, ReduceNode& right){
    sym = 0;
    leftChild = &left;
    rightChild = &right;
    code = left.code >> 1;
    bits = left.bits - 1;
    max = std::max(left.max,right.max) + 1;
    min = std::min(left.min,right.min) + 1;
    child = left.child + right.child + 1;
}

ReduceNode::ReduceNode(char sym, unsigned int code, unsigned char bits){
    this->sym = sym;
    this->code = code;
    this->bits = bits;
    max = 0;
    min = 0;
    child = 1;
}

ReduceNode::ReduceNode(const ReduceNode& reducenode){
    sym = reducenode.sym;
    code = reducenode.code;
    bits = reducenode.bits;
    leftChild = reducenode.leftChild;
    rightChild = reducenode.rightChild;
    max = reducenode.max;
    min = reducenode.min;
    child = reducenode.child;
}

ReduceNode::~ReduceNode(){
    if(leftChild != nullptr)
        delete leftChild;
    if(rightChild != nullptr)
        delete rightChild;
}

void ReduceNode::print(){  
    print2DUtil(this, 0);  
}

void ReduceNode::print2DUtil(ReduceNode *root, int space){   
    if (root == NULL)  
        return;  
    space += 10;  
    print2DUtil(root->rightChild, space);  
    cout<<endl;  
    for (int i = 10; i < space; i++)  
        cout<<" ";  
    cout<< *root <<"\n";  
    print2DUtil(root->leftChild, space);  
}

ostream& operator<<(ostream& os, const ReduceNode& node){
    os << "sym: " << node.sym << " code: " << node.code << " bits: " << (int)node.bits << " max: " << node.max << " min: " << node.min;
    return os;
}