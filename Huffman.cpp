#include "Huffman.hpp"

Huffman::Huffman(){
}

Huffman::~Huffman(){
}

int Huffman::countChars(map<char, double>& counts){
    char c;
    int total = 0;
            
    while(cin.get(c))
    {
        counts[c]++;
        total++;
    }
    return total;
}

Node* Huffman::constructTree(map<char, double>& table, int total){
    priority_queue<Node*, vector<Node*>, freqCompare> pq;   
    for(auto& [key, value]: table){
        double freq = value / total;
        Node* node = new Node(freq, key);
        pq.push(node);
    }
    while(pq.size() > 1){
        Node* a = pq.top();
        pq.pop();
        Node* b = pq.top();
        pq.pop();
        Node* internalNode = new Node(*a,*b);
        pq.push(internalNode);
    }
    return pq.top();
}

ReduceNode* Huffman::constructTree(map<char, CodeWord>& table){
    priority_queue<ReduceNode*, vector<ReduceNode*>, bitsCompare> pq;   
    for(auto& [key, value]: table){
        ReduceNode* reducenode = new ReduceNode(key, value.code, value.bits);
        pq.push(reducenode);
    }
    while(pq.size() > 1){
        ReduceNode* a = pq.top();
        pq.pop();
        ReduceNode* b = pq.top();
        pq.pop();
        ReduceNode* internalNode = new ReduceNode(*a,*b);
        pq.push(internalNode);
    }
    return pq.top();
}

void Huffman::getCodeWords(vector<CodeWord>& words, const Node& root, CodeWord currWord){
    if(root.leftChild == nullptr && root.rightChild == nullptr){
        currWord.sym = root.sym;
        words.push_back(currWord);
    }
    else{
        CodeWord childWord;
        childWord.bits = currWord.bits + 1;
        childWord.code = currWord.code << 1;
        childWord.sym = 0;
        getCodeWords(words, *(root.leftChild), childWord);
        childWord.code++;
        getCodeWords(words, *(root.rightChild), childWord);
    }
}

map<char, CodeWord>* Huffman::canonize(vector<CodeWord>& words){
    std::sort(words.begin(), words.end(), CodeWord::codeWordCompare);
    map<char, CodeWord>* bookptr = new map<char, CodeWord>();
    map<char, CodeWord>& book = *bookptr;
    words[0].code = 0;
    book[words[0].sym] = words[0];
    for(int i = 1; i < int(words.size()); i++){
        words[i].code = words[i - 1].code + 1;
        if(words[i].bits < words[i - 1].bits){
            for(int j = words[i].bits; j < words[i - 1].bits; j++){
                words[i].code = words[i].code >> 1;
            }
        }
        book[words[i].sym] = words[i];
    }
    return bookptr;
}

void Huffman::reduce(ReduceNode& node){
    if(node.max - node.min <= 1){
        delete node.leftChild;
        node.leftChild = nullptr;
        delete node.rightChild;
        node.rightChild = nullptr;
        node.child = 1;
    }
    else if(node.leftChild == nullptr && node.rightChild == nullptr)
        return;
    else{
        reduce(*node.leftChild);
        reduce(*node.rightChild);
        node.child = node.rightChild->child + node.leftChild->child + 1;
    }
}

void Huffman::skeleton(ReduceNode& node){
    if(node.max - node.min == 0){
        delete node.leftChild;
        node.leftChild = nullptr;
        delete node.rightChild;
        node.rightChild = nullptr;
        node.child = 1;
    }
    else if(node.leftChild == nullptr && node.rightChild == nullptr)
        return;
    else{
        skeleton(*node.leftChild);
        skeleton(*node.rightChild);
        node.child = node.rightChild->child + node.leftChild->child + 1;
    }
}