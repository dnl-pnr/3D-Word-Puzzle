#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include "nodeClass.h"
using namespace std;

vector<string> solve(nodeClass a, vector<string> words) {
	string letters[18] = { "G", "E", "P", "D", "N", "U", "R", "E", "A", "I", "V", "L", "A", "T", "S", "B", "O", "O"};
	int fromStart0 = 0;
	int fromStart1 = 0;
	int fromStart2 = 0;
	int store0 = a.getPos();
	int store1 = a.getPos();
	int store2 = a.getPos();
	int store3 = a.getPos();

	for (int i = 0; i < 6; ++i) {	
		words.push_back(a.letter); //start with origin letter
		a.set(store0); //set position to that letter
		words.push_back(words.at(words.size() - 1) + letters[a.traverse(i)]); //travel a possible direction then add it to the vector
		fromStart2 = words.size(); //store the location of the entry
		store1 = a.getPos(); //store new current position
		for (int i = 0; i < 6; ++i) { //repeat
			a.set(store1);
			words.push_back(words.at(fromStart2 - 1) + letters[a.traverse(i)]);
			fromStart1 = words.size();
			store2 = a.getPos();
			for (int i = 0; i < 6; ++i) { //repeat
				a.set(store2); 
				words.push_back(words.at(fromStart1 - 1) + letters[a.traverse(i)]);
				fromStart0 = words.size();
				store3 = a.getPos();
				for (int i = 0; i < 6; ++i) {
					a.set(store3); //set position to start for this level
					words.push_back(words.at(fromStart0 - 1) + letters[a.traverse(i)]);
				}
			}
		}
	}
	return words;
}

int main()
{
	//declare every node
	nodeClass G0(0, "G");
	nodeClass E1(1, "E");
	nodeClass P2(2, "P");
	nodeClass D3(3, "D"); 
	nodeClass N4(4, "N");
	nodeClass U5(5, "U");
	nodeClass R6(6, "R");
	nodeClass E7(7, "E"); 
	nodeClass A8(8, "A");
	nodeClass I9(9, "I");
	nodeClass V10(10, "V");
	nodeClass L11(11, "L");
	nodeClass A12(12, "A");
	nodeClass T13(13, "T");
	nodeClass S14(14, "S");
	nodeClass B15(15, "B");
	nodeClass O16(16, "O");
	nodeClass O17(17, "O");

	vector<string> words;
	vector<string> hold;

	//solve for each starting position
	words = solve(G0, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(E1, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(P2, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(D3, words);
	hold.insert(hold.end(), words.begin(), words.end()); //copy results to a storage vector
	words.clear();
	words = solve(N4, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(U5, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(R6, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(E7, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(A8, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(I9, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(V10, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(L11, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(A12, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(T13, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(S14, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(B15, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(O16, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();
	words = solve(O17, words);
	hold.insert(hold.end(), words.begin(), words.end());
	words.clear();

	//sorts for real 5 letter words and stores them in vector "answers"
	vector<string> answers;
	set<string> Dictionary;
	cout << "All possible answers:" << endl;
	std::ifstream myfile;
	myfile.open("5-Letter-Dictionary.txt");	
	if (myfile.is_open()) {
		string myline;
		while (getline(myfile, myline)) {
			Dictionary.insert(myline); //copy dictionary to a set 
		}
	}
	else {
		cout << "File not opened.";
		return 0;
	}
	for (auto hold : hold) {
		if (Dictionary.find(hold) != Dictionary.end()) { //compare dictionary to letter combos to get answers
			answers.push_back(hold);
		}
	}

	//sorts answers alphabetically
	string prev = "1";
	string temp;
	for (int i = 0; i < answers.size(); ++i) {
		for (int j = i + 1; j < answers.size(); ++j) {
			if (answers[i] > answers[j]) {
				temp = answers[i];
				answers[i] = answers[j];
				answers[j] = temp;
			}
		}
	}

	//to count answers printed
	int results = 0;

	//prints answers
	for (int i = 0; i < answers.size(); ++i) {

		//does not print if previous cout was the exact same thing
		if (prev != answers[i]) {
			cout << answers[i] << endl;
			++results;
			prev = answers[i];
		}
	}
	cout << "There were " << results << " answers." << endl;
}