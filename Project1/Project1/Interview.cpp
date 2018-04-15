#include "Interview.h"
#include <map>
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;

Interview::Interview()
{
}


Interview::~Interview()
{
}

void run(){
	
	//add "find smallest integer of rotated sorted array" here.
	vector<int> a0 = {2, 3, 4, 5, 6, 7, 8, 9, 1};
	vector<int> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> a2 = {9, 1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> a3 = {8, 9, 1, 2, 3, 4, 5, 6, 7};
	vector<int> a4 = {7, 8, 9, 1, 2, 3, 4, 5, 6};
	vector<int> a5 = {6, 7, 8, 9, 1, 2, 3, 4, 5};
	vector<int> a6 = {5, 6, 7, 8, 9, 1, 2, 3, 4};
	vector<int> a7 = {4, 5, 6, 7, 8, 95, 1, 2, 3};
	vector<int> a8 = {2, 2, 2, 6, 7, 8, 9, 1, 2};
	vector<int> a9 = {2, 3, 4, 5, 6, 7, 8, 9, 1};
	vector<int> a10 = {7, 7, 7, 7, 7, 7, 7, 7};
	vector<int> a11 = {1, 7, 7, 7, 7, 7, 7, 7, 7};
	vector<int> a12 = {2, 7, 7, 7, 7, 7, 7, 7, 7, 1};
	
	vector<int> aa = {1};
	vector<int> ab = {2, 3};
	vector<int> ac = {3, 2};
	vector<int> ad = {10, 11, 4, 5, 5, 5, 5, 6, 7, 8, 9, 9};
	
	
	cout << "a0: " << Interview::smallestInRotatedSortedArray(a0) << ", should be 1 " << endl;
	cout << "a1: " << Interview::smallestInRotatedSortedArray(a1) << ", should be 1 " << endl;
	cout << "a2: " << Interview::smallestInRotatedSortedArray(a2) << ", should be 1 " << endl;
	cout << "a3: " << Interview::smallestInRotatedSortedArray(a3) << ", should be 1 " << endl;
	cout << "a4: " << Interview::smallestInRotatedSortedArray(a4) << ", should be 1 " << endl;
	cout << "a5: " << Interview::smallestInRotatedSortedArray(a5) << ", should be 1 " << endl;
	cout << "a6: " << Interview::smallestInRotatedSortedArray(a6) << ", should be 1 " << endl;
	cout << "a7: " << Interview::smallestInRotatedSortedArray(a7) << ", should be 1 " << endl;
	cout << "a8: " << Interview::smallestInRotatedSortedArray(a8) << ", should be 1 " << endl;
	cout << "a9: " << Interview::smallestInRotatedSortedArray(a9) << ", should be 1 " << endl;
	cout << "a10: " << Interview::smallestInRotatedSortedArray(a10) << ", should be 7 " << endl;
	cout << "a11: " << Interview::smallestInRotatedSortedArray(a11) << ", should be 1 " << endl;
	cout << "a12: " << Interview::smallestInRotatedSortedArray(a12) << ", should be 1 " << endl;
	cout << "aa: " << Interview::smallestInRotatedSortedArray(aa) << ", should be 1 " << endl;
	cout << "ab: " << Interview::smallestInRotatedSortedArray(ab) << ", should be 2 " << endl;
	cout << "ac: " << Interview::smallestInRotatedSortedArray(ac) << ", should be 2 " << endl;
	cout << "ad: " << Interview::smallestInRotatedSortedArray(ad) << ", should be 4 " << endl;
}

int smallest(int guess, int start, int end, std::vector<int> array){
	int smallest = -1;
	if(start == end){ //Length 1
		smallest = array[guess];
	} else if(end - start == 1 || start - end == 1){ //Length 2
		smallest = (array[end] < array[start]) ? array[end] : array[start];
	}	//Case of array length 3 or greater
	else if(array[guess] < array[guess + 1] && array[guess] < array[guess - 1]){
		smallest = array[guess];
	}
	return smallest;
}

//Determine whether array was rotated left or right. If right, smallest number will be in lower half. If left, smallest number will be in upper half. If right, first element will be bigger than middle elemet. If left, first element will be smaller than middle element.
int Interview::smallestInRotatedSortedArray(std::vector<int> array){
	/*
	 This presented some challenges. How did I solve it?
	 1. Make a separate method for evaluating the guess. The logic for EVALUATING the guess and UPDATING the guess need to be separate.
	 2. Express the logic for choosing the smallest number in terms of the START and END of the range - NOT the range between the start and the guess, or end and the guess.
	 3. Identify the four base cases and code for them separately: 1) the array is not rotated, so the smallest must be at the beginning; 2) the start and end are the same, so the smallest has been found; 3) the start and end are 1 apart, so finding the smallest is trivial; 4) the start and end are more than 1 apart, so comparing the guess to its two nearest neighbors will reveal whether it is the smallest or not.
	 4. Make the "find the guess" method be the loop condition for the while() loop. This way the loop continues until the guess is found, and there doesn't need to be any special stopping logic in the body of the loop.
	 */
	
	int start = 0;
	int guess = array.size() / 2;
	int end = array.size() - 1;
	int result = -1;
	
	//the array is not rotated, so the smallest must be the first.
	if(array[guess] <= array[end] && array[guess] > array[start]){
		return array[start];
	}
	
	while((result = smallest(guess, start, end, array)) == -1){
		//update the guess
		if(array[start] > array[guess]){//smallest is somewhere between start and middle
			end = guess;
			guess = ((guess - start) / 2 ) + start;
		} else { //the smallest is somewhere between middle and end
			start = guess;
			guess = ((end - guess) / 2 ) + guess;
		}
	}
	return result;
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
