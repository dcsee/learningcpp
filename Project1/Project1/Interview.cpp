#include "Interview.h"
#include <map>
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

Interview::Interview()
{
}


Interview::~Interview()
{
}

void Interview::sortMapByKey() {
	std::map<std::string, int> mapOfWordCount = { { "aardvark", 10 },{ "zed", 41 },
	{ "b", 62 },{ "crayfishing", 13 } };

	for (auto itr = mapOfWordCount.begin(); itr != mapOfWordCount.end(); ++itr) {
		std::cout << "key: " << (*itr).first << ", value: " << (*itr).second << "; ";
	}

	//typedef the function that accepts two pairs and returns a bool. Name this type Comparator
	//you must #include 'functional' for this to work
	typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;
	int captured = 1;

	//declare the comparator
	Comparator compFunctor =
		[captured](std::pair<std::string, int> elem1, std::pair<std::string, int> elem2)
	{
		std::cout << captured << " was captured!" << std::endl;
		return elem1.second < elem2.second;
	};

	//declare a set, which will be used to sort the map by key after copying it into the set
	std::set<std::pair<std::string, int>, Comparator> setOfWords(mapOfWordCount.begin(), mapOfWordCount.end(), compFunctor);

	std::cout << std::endl;

	for (std::pair<std::string, int> element : setOfWords) {
		std::cout << "key: " << element.first << ", value: " << element.second << "; ";
	}
}