
#pragma once
#include <vector>
#include <string>
#include <map>

class LearningBase
{
public:
	LearningBase();
	~LearningBase();
	int getId() const;
	static bool isPalindrome(const std::string& mystr);
//	virtual const std::string virtualTalk();
//	const std::string overrideTalk() const;
	static std::string sayWhatYouSee(const std::string& input);
//	static void ptrArithmeticDemo();
	
	//find the average distance between all the As and Bs in a string
	static const float avgDistanceAB(const std::string& input);
	
	//sort the anagrams in a string
	void anagramSort(std::vector<std::string> strList);
	static std::map<std::string, int> anagramIDs;
	
private:
	int id;
	void countChars(std::map<char, int>& charCount, const std::string& str);
	bool stringsAreAnagrams(const std::map<char, int>& mapToCompare, const std::string& str);
	static bool compare(std::string a, std::string b);
};