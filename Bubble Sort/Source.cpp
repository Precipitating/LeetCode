#include <iostream>
#include <vector>
using namespace std;


void BubbleSort(vector<int>& vec)
{
	bool swappedThisIteration;

	for (size_t i = 0; i < vec.size(); ++i)
	{
		swappedThisIteration = false;
		for (size_t j = 0; j < vec.size() - i - 1; ++j)
		{
			if (vec[j] > vec[j + 1])
			{
				swap(vec[j], vec[j + 1]);
				swappedThisIteration = true;
			}
		}

		if (!swappedThisIteration)
		{
			break;
		}
	}
	






};

int main()
{
	vector<int> unSortedVector = { 1,4,2,8,3 };
	BubbleSort(unSortedVector);
	return 0;
}