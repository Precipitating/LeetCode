#include <iostream>
#include <vector>
using namespace std;




void Merge(const vector<int>& leftVec, const vector<int>& rightVec, vector<int>& nums)
{
	int i = 0, j = 0, k = 0;

	while (j < leftVec.size() && k < rightVec.size())
	{
		if (leftVec[j] < rightVec[k])
		{
			nums[i++] = leftVec[j++];
		}
		else
		{
			nums[i++] = rightVec[k++];
		}

	}

	// store leftovers
	while (j < leftVec.size())
	{
		nums[i++] = leftVec[j++];
	}

	while (k < rightVec.size())
	{
		nums[i++] = rightVec[k++];
	}

}

void MergeSort(vector<int>& nums)
{
	int n = nums.size();
	if (n <= 1) return;

	int mid = n / 2;

	vector<int> leftVec(mid);
	vector<int> rightVec(n - mid);

	// left vec
	int i = 0;

	// right vec
	int j = 0;


	// add original nums to two halves: left and right vectors
	for (int i = 0; i < mid; ++i)
	{
		leftVec[i] = nums[i];
	}

	for (int i = mid; i < n; ++i)
	{
		rightVec[i - mid] = nums[i];
	}

	// recurse both vectors until split 
	MergeSort(leftVec);
	MergeSort(rightVec);

	// merge sorted values back to nums
	Merge(leftVec, rightVec, nums);


}


int main()
{
	vector<int> nums = { 1,4,2,8,345,123,43,32,5643,63,123,43,2,55,1,234,92 };
	MergeSort(nums);
	return 0;
}