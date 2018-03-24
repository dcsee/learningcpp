#include "LearningBase.h"
#include<map>
#include<string>
#include<iostream>

LearningBase::LearningBase()
{
	id = 1;
}


LearningBase::~LearningBase()
{
}
/*
static void sayHi() {
	std::cout << "hi";
}*/

int LearningBase::getId() const {
	return id;
}

//in a method declaration, you need to use the scope resolution operator '::' to indicate that the method is a member of the class.
//this is because you can have other, non-member functions declared in the same .cpp file, so the compiler needs the '::' syntax
//to know which functions are members of the class and which aren't.
bool LearningBase::isPalindrome(const std::string& mystr) {

	std::cout << "\nLet's analyze '" << mystr << "'...";

	//I guess I don't have to declare this with 'new' because charCount is just a reference that sits on the stack. pretty cool.
	std::map<char, int> charCount;
	std::map<char, int>::iterator itr;
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
	for (std::map<char, int>::iterator itr = charCount.begin(); itr != charCount.end(); ++itr) {
		int times = itr->second;
		if (times%2 != 0) {
			odds++;
		}
		if (odds > 1) {
			std::cout << "\nWait! Character '" << itr->first << "' appears " << times << " times! And in a palindrome, only ONE character can appear an odd number of times. "
				<< "So '" << mystr << "' CANNOT be a palindrome!!\n\n";
			isPal = false;
			break;
		}
		std::cout << "\ncharacter '" << itr->first << "' appears " << times << " times,";
	}

	if (isPal == true) {
		std::cout << "\nCongratulations! '" << mystr << "' is a palindrome.\n\n";
	}

	return isPal;
}

/*
const std::string& LearningBase::comp3() {
	return "I am only a LearningBase and cannot compress a string.";
}*/

const std::string LearningBase::virtualTalk() {
	return "\nLearningBase: I AM the virtual function.\n";
}

const std::string LearningBase::overrideTalk() const {
	return "\nLearningBase: I am a normal, non-virtual function.\n";
}

/*const std::string& LearningBase:: compress(const std::string& toCompress) {
	return "I am only a LearningBase and cannot compress a string.";
}*/