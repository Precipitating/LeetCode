#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int>& vec)
{
	for (size_t i = 1; i < vec.size(); ++i)
	{
		int j = i;

		while (j > 0 && vec[j - 1] > vec[j])
		{
			swap(vec[j], vec[j - 1]);
			--j;
		}



	}
}
int main()
{
	vector<int> nums = { 1,4,2,8,345,123,43,32,5643,63,123,43,2,55,1,234,92 };
	InsertionSort(nums);

	return 0;
}