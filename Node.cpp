#include "Node.hpp"

Node::Node(Node& left, Node& right){
    freq = left.freq + right.freq;
    sym = 0;
    leftChild = &left;
    rightChild = &right;
    child = left.child + right.child + 1;
}

Node::Node(double frequency, char symbol){
    freq = frequency;
    sym = symbol;
    child = 1;
}

Node::Node(const Node& node){
    freq = node.freq;
    sym = node.freq;
    leftChild = node.leftChild;
    rightChild = node.rightChild;
    child = node.child;
}

Node::~Node()
{
    if(leftChild != nullptr)
        delete leftChild;
    if(rightChild != nullptr)
        delete rightChild;
}

void Node::print(){  
    print2DUtil(this, 0);  
} 

void Node::print2DUtil(Node *root, int space)  
{   
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

ostream& operator<<(ostream& os, const Node& node){
    os << "sym: " << node.sym << " freq: " << node.freq;
    return os;
}