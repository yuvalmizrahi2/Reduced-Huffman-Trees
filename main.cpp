#include "Node.hpp"
#include "Huffman.hpp"
#include "CodeWord.hpp"
#include "ReduceNode.hpp"
#include "NonOptimal.hpp"
#include "Optimal.hpp"
#include <iostream>


int main(int argc, char const *argv[])
{
    
    Huffman huffman;
    map<char, double> counts;
    int total = huffman.countChars(counts);
    cout << "number of the Σ of our file: " << counts.size() << endl;
    Node* root = huffman.constructTree(counts, total);
    vector<CodeWord>* wordsptr = new vector<CodeWord>();
    vector<CodeWord>& words = *wordsptr;
    CodeWord initWord;
    initWord.code = initWord.bits = initWord.sym = 0; 
    huffman.getCodeWords(words, *root, initWord);
    vector<int> vc(words.size(),0);
    for(auto& word: words){
        vc.at(((int)word.bits) - 1)++;
    }
    delete root;
    map<char, CodeWord>* bookptr = huffman.canonize(words);
    map<char, CodeWord>& book = *bookptr;
    delete wordsptr;
    ReduceNode* reduceroot = huffman.constructTree(book);
    cout << "number of the node befor after canonize: " << reduceroot->child << endl;
    huffman.skeleton(*reduceroot);
    cout << "number of the node after skeleton and canonize: " << reduceroot->child << endl;
    reduceroot = huffman.constructTree(book);
    huffman.reduce(*reduceroot);
        cout << "number of the node after reduce and canonize: " << reduceroot->child << endl;

    // vector <int> vc={0,0,3,7,5,2};
    NonOptimal tree(vc);
    tree.reduceNonOptimal();
    Optimal::optimalReduced(vc);
    return 0;
}
