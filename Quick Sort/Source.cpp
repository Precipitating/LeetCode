#include <iostream>
#include <vector>
using namespace std;


int Partition(vector<int>& nums, int start, int end)
{
	int pivot = nums[end];

	int i = start - 1;
	
	for (int j = start; j <= end - 1; ++j)
	{
		if (nums[j] < pivot)
		{
			++i;
			swap(nums[i], nums[j]);
		}
	}
	++i;

	swap(nums[i], nums[end]);

	return i;

}



void QuickSort(vector<int>& nums, int start, int end)
{
	if (end <= start) return;

	int pivot = Partition(nums, start, end);

	QuickSort(nums, start, pivot - 1);
	QuickSort(nums, pivot + 1, end);


}


int main()
{
	vector<int> nums = { 1,4,2,8,345,123,43,32,5643,63,123,43,2,55,1,234,92 };
	QuickSort(nums, 0, nums.size() - 1);
	return 0;
}