#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution 
{
public:
    string largestNumber(vector<int>& nums)
	{
		vector<string> toStr;
		toStr.reserve(nums.size());
		string result;
		for (const int& num : nums)
		{
			toStr.push_back(to_string(num));
		}
		
		sort(toStr.begin(), toStr.end(), [](const string& x, const string& y) {return (x + y) > (y + x); });
		if (toStr[0] == "0") { return "0"; }

		for (size_t i = 0; i < toStr.size(); ++i)
		{
			result.append(toStr[i]);
		}
		return result;

    }


};
int main()
{
	Solution s;
	vector<int> nums = { 20,5,10,25,4 };
	cout << s.largestNumber(nums);
	return 0;
}