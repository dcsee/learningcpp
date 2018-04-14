#include<string>
#include "LearningBase.h"
#pragma once
class LearningStringCompressor: public LearningBase
{
public:
	LearningStringCompressor();
	~LearningStringCompressor();

	const std::string virtualTalk();
	const std::string overrideTalk();
	static void compress(const std::string& toCompress);
	static void printCharAndCount(char charType, int charCount);
};