#pragma once
#include<string>

class LearningBase
{
public:
	LearningBase();
	~LearningBase();
	int getId() const;
//	static void sayHi();
	static bool isPalindrome(const std::string& mystr);
	virtual const std::string virtualTalk();
	const std::string overrideTalk() const;
	//	virtual const std::string& compress(const std::string& toCompress);

private:
	int id;

};