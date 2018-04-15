#include "LearningBase.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>


using namespace std;

LearningBase::LearningBase()
{
	id = 1;
}

LearningBase::~LearningBase()
{
}

void run(){
	//	LearningBase::ptrArithmeticDemo();
	//	cout << LearningBase::avgDistanceAB("abccaacabcab") << endl;
	//	vector<string> strVector = {
	//		"abc", "test", "vac", "bac", "london", "cba", "cav", "lon", "pst"
	//	};
	//	LearningBase base = LearningBase();
	//	base.anagramSort(strVector);
	//	cout << LearningBase::sayWhatYouSee("aadjdfddkdedmfffffvirewo");
}

int LearningBase::getId() const {
	return id;
}


bool LearningBase::isPalindrome(const string& mystr) {

	cout << "\nLet's analyze '" << mystr << "'...";

	//I guess I don't have to declare this with 'new' because charCount is just a reference that sits on the stack. pretty cool.
	map<char, int> charCount;
	map<char, int>::iterator itr;
	bool isPal = true;

	for (int i = 0; i < mystr.length(); i++) {
		char c = mystr[i];
		itr = charCount.find(c);

		if (itr != charCount.end()) {
			charCount[c] = charCount[c] + 1;
		}
		else {
			charCount[c] = 1;
		}
	}

	int odds = 0;
	//iterate over the map
	for (map<char, int>::iterator itr = charCount.begin(); itr != charCount.end(); ++itr) {
		int times = itr->second;
		if (times%2 != 0) {
			odds++;
		}
		if (odds > 1) {
			cout << "\nWait! Character '" << itr->first << "' appears " << times << " times! And in a palindrome, only ONE character can appear an odd number of times. "
				<< "So '" << mystr << "' CANNOT be a palindrome!!\n\n";
			isPal = false;
			break;
		}
		cout << "\ncharacter '" << itr->first << "' appears " << times << " times,";
	}

	if (isPal == true) {
		cout << "\nCongratulations! '" << mystr << "' is a palindrome.\n\n";
	}

	return isPal;
}

string LearningBase::sayWhatYouSee(const string& input){
	if (input.length() < 1) {
		return "";
	}
	
	ostringstream oss;
	
	//initialize the character type to the first character of the string
	char charType = input[0];
	int charCount = 1;
	
	for (int i = 1; i < input.length(); i++) {
		
		//if the next char is equal to the current char, increment the count
		if (charType == input[i]) {
			charCount++;
		}
		else {//print, clear the count, and reset the charType
			
			//the 'oss' converts the arguments to strings and stores them in a stream/buffer
			oss << charCount << charType;
			charType = input[i];
			charCount = 1;
		}
	}
	//the loop is over, so print the last character and its count
	oss << charCount << charType;
	return oss.str();
}

/*
const std::string& LearningBase::comp3() {
	return "I am only a LearningBase and cannot compress a string.";
}*/

/*
const string LearningBase::virtualTalk() {
	return "\nLearningBase: I AM the virtual function.\n";
}

const string LearningBase::overrideTalk() const {
	return "\nLearningBase: I am a normal, non-virtual function.\n";
}

void LearningBase::ptrArithmeticDemo(){
	
	typedef struct {
		char name;
		int value;
	} miniclass;
	
	std::cout << "This iterates over an array of structs and prints the address, name, and value" << std::endl;
	
	//this memory is allocated on the stack, but not necessarily in linear order.
	miniclass arr[5] = {
		{'a', 1},
		{'b', 2},
		{'c', 3},
		{'d', 4},
		{'e', 5},
	};
	miniclass* ptr = arr;
	
	for(int i = 0; i < 5; i++){
		std::cout << "address: " << ptr << std::endl
							<< "name: " << ptr->name << std::endl
		<< "value: " << ptr->value << std::endl;
		ptr++;
	}
}

const float LearningBase::avgDistanceAB(const string& input){
	int aCount = 0;
	int bCount = 0;
	float aggregateAPositions = 0;
	float aggregateBPositions = 0;
	float avgAPosition = 0;
	float avgBPosition = 0;
	
	for(int i = 0; i < input.length(); i++){
		char c = input[i];
		if(c == 'a'){
			aCount++;
			aggregateAPositions += i;
		} else if(c == 'b'){
			bCount++;
			aggregateBPositions += i;
		}
	}
	
	//for this division, one of the two operands (divisor or dividend) needs to be a float,
	//because the result of dividing an int by an int in C/C++ is also an int.
	
	if(aCount != 0){
		avgAPosition = aggregateAPositions / aCount;
	}
	if(bCount != 0){
		avgBPosition = aggregateBPositions / bCount;
	}
	
	cout << "The average location of the As is: " << avgAPosition << endl;
	cout << "The average location of the Bs is: " << avgBPosition << endl;
	cout << "The average distance between the As and the Bs is: ";
	
	return abs(avgBPosition - avgAPosition);
}*/



/*Anagram Sort
 Sort a list of words such that anagrams are grouped together:
 Input: ['abc','test','vac', 'bac', 'london', 'cba', 'cav', 'lon', 'pst']
 Output: ['abc', 'bac', 'cba', 'vac', 'cav', 'london', 'test', 'lon', 'pst']
 */

std::map<std::string, int> LearningBase::anagramIDs = std::map<std::string, int>();

bool LearningBase::compare(string a, string b){
	return anagramIDs[a] < anagramIDs[b];
//	return a.length() > b.length();
}

void LearningBase::countChars(map<char, int>& charCount, const string& str){
	charCount.clear();
	for(int i = 0; i < str.length(); i++){
		charCount[str[i]] = charCount[str[i]] + 1;
	}
}

bool LearningBase::stringsAreAnagrams(const map<char, int>& mapToCompare, const string& str){
	
	map<char, int> charCount = map<char, int>();
	bool isMatch = true;
	
	for(int i = 0; i < str.length(); i++){
		charCount[str[i]] = charCount[str[i]] + 1;
	}
	
	//this checks the two maps for equality
	if(mapToCompare.size() == charCount.size()){
		for(auto it = charCount.begin(); it != charCount.end(); ++it){
			if(mapToCompare.find((*it).first) == mapToCompare.end() ||
				 mapToCompare.at((*it).first) != (*it).second){
				isMatch = false;
				break;
			}
		}
	}
	else {
		isMatch = false;
	}
	return isMatch;
}

void LearningBase::anagramSort(vector<string> strList){
	cout << "Input: ['abc','test','vac', 'bac', 'london', 'cba', 'cav', 'lon', 'pst']" << endl
	<< "Expected Output: ['abc', 'bac', 'cba', 'vac', 'cav', 'london', 'test', 'lon', 'pst']" << endl;
	
	map<char, int> charCount = map<char, int>();
	int anagramID = 0;
	
	for(int i = 0; i < strList.size(); i++){
		//if this anagram hasn't been encountered yet, "register" it with a unique number
		if(LearningBase::anagramIDs[strList[i]] == 0){
			anagramID++;
			LearningBase::anagramIDs[strList[i]] = anagramID;
			
			//count the occurrences of each char in the string - fills the charCount map
			countChars(charCount, strList[i]);
			
			//now check if all the subsequent strings match this anagram
			for(int j = i + 1; j < strList.size(); j++){
				if(stringsAreAnagrams(charCount, strList[j])){
					LearningBase::anagramIDs[strList[j]] = anagramID;
				}
			}
		}
	}
	
	//lastly, sort the list and print it. figure out why this is not working. make anagramIDs
	//a static member of LearningBase if necessary.
	std::sort(strList.begin(), strList.end(), &(LearningBase::compare));
	cout << "Actual output: [ " << endl;
	for(int i = 0; i < strList.size(); i++){
		cout << strList[i] << " ";
	}
	cout << " ]" << endl;
}
