#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void SelectionSort(vector<int>& vec)
{

	for (size_t i = 0; i < vec.size(); ++i)
	{
		vector<int>::iterator firstNum = vec.begin() + i;
		vector<int>::iterator minNum = std::min_element(firstNum, vec.end());

		if (*firstNum != *minNum)
		{
			swap(*firstNum, *minNum);
		}

		

	}

}


int main()
{
	vector<int> nums = { 1,4,2,8,345,123,43,32,5643,63,123,43,2,55,1,234,92 };
	SelectionSort(nums);
	return 0;
}