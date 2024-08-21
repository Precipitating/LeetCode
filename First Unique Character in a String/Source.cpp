#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
	int firstUniqChar(string s)
	{
		int result = -1;
		unordered_map<char, int> seenChars;

		for (const char& c : s)
		{
			++seenChars[c];
		}
		

		for (size_t i = 0; i < s.size(); ++i)
		{
			if (seenChars[s[i]] == 1)
			{
				result = i;
				break;
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	cout << s.firstUniqChar("aabb");
	return 0;
}