#include "Node.hpp"
#include "Huffman.hpp"
#include "CodeWord.hpp"
#include "ReduceNode.hpp"
#include <iostream>


int main(int argc, char const *argv[])
{
    Huffman huffman;
    map<char, double> counts;
    int total = huffman.countChars(counts);
    cout << "total: " << counts.size() << endl;
    // for(auto& [key, value]: counts){
    //     cout << "symbol: " << key << " freq: " << value << endl;
    // }
    Node* root = huffman.constructTree(counts, total);
    cout << "num of the node: " << root->child << endl;
    // root->print();
    vector<CodeWord>* wordsptr = new vector<CodeWord>();
    vector<CodeWord>& words = *wordsptr;
    CodeWord initWord;
    initWord.code = initWord.bits = initWord.sym = 0; 
    huffman.getCodeWords(words, *root, initWord);
    // for(auto& word: words){
    //     cout << word << endl;
    // }
    delete root;
    map<char, CodeWord>* bookptr = huffman.canonize(words);
    map<char, CodeWord>& book = *bookptr;
    delete wordsptr;
    // for(auto& [key, value]: book){
    //     cout << "symbol: " << key << " " << value << endl;
    // }
    ReduceNode* reduceroot = huffman.constructTree(book);
    // reduceroot->print();
    cout << "num of the node: " << reduceroot->child << endl;
    huffman.skeleton(*reduceroot);
    // reduceroot->print();
    cout << "num of the node: " << reduceroot->child << endl;
    return 0;
}
