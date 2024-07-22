#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);
/*
	Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

	You may assume that each input would have exactly one solution, and you may not use the same element twice.

	You can return the answer in any order.

	nums = [2,7,11,15]

	target = 9
*/


int main()
{
	vector<int> nums = { 2,7,11,15 };
	int target = 9;

	auto s = twoSum(nums, target);

	for (auto x : s)
	{
		cout << x << ' ';
	}
	return 0;
}


// solution 1: 973 ms runtime, 16mb memory
//vector<int> twoSum(vector<int>& nums, int target)
//{
//	unordered_map<int, int> toMap;
//
//	for (int i = 0; i < nums.size(); ++i)
//	{
//		toMap.insert({ i, nums[i] });
//	}
//
//	for (int i = 0; i < toMap.size(); ++i)
//	{
//		for (int j = i + 1; j < toMap.size(); ++j)
//		{
//			if ((toMap.at(i) + toMap.at(j)) == target)
//			{
//				return { i, j };
//			}
//		}
//	}
//	return nums;
//}

// solution 2: hash map, subtracting target with current number and checking if it exists in map.
// if not, then add to map, and repeat.

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> toMap;

	for (int i = 0; i < nums.size(); ++i)
	{
		int subtractedResult = target - nums[i];
		if (toMap.count(subtractedResult))
		{
			return { toMap[subtractedResult], i  };
		}

		toMap[nums[i]] = i;

	}



}
