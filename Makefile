CXX=g++ -std=c++1z
CXXFLAGS=-Wall -Werror -Wvla

a.out: Huffman.o freqCompare.o CodeWord.o Node.o ReduceNode.o bitsCompare.o NonOptimal.o Optimal.o main.o
	$(CXX) $(CXXFLAGS) Huffman.o freqCompare.o CodeWord.o Node.o ReduceNode.o bitsCompare.o NonOptimal.o Optimal.o main.o -o a.out

Huffman.o: Huffman.cpp Huffman.hpp
	$(CXX) $(CXXFLAGS) -c Huffman.cpp -o Huffman.o

freqCompare.o: freqCompare.cpp freqCompare.hpp
	$(CXX) $(CXXFLAGS) -c freqCompare.cpp -o freqCompare.o

CodeWord.o: CodeWord.cpp CodeWord.hpp
	$(CXX) $(CXXFLAGS) -c CodeWord.cpp -o CodeWord.o

Node.o: Node.cpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Node.cpp -o Node.o

ReduceNode.o: bitsCompare.cpp bitsCompare.hpp
	$(CXX) $(CXXFLAGS) -c bitsCompare.cpp -o bitsCompare.o

ReduceNode.o: ReduceNode.cpp ReduceNode.hpp
	$(CXX) $(CXXFLAGS) -c ReduceNode.cpp -o ReduceNode.o

NonOptimal.o: NonOptimal.cpp NonOptimal.hpp
	$(CXX) $(CXXFLAGS) -c NonOptimal.cpp -o NonOptimal.o

Optimal.o: Optimal.cpp Optimal.hpp
	$(CXX) $(CXXFLAGS) -c Optimal.cpp -o Optimal.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o a.out
