#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution 
{
public:
	int minStickers(vector<string>& stickers, string target)
	{
		int result = 0;
		unordered_set<string> visited;

		// stickers/target to frequencies
		vector<vector<int>> stickerFreq(stickers.size(), vector<int>(26));
		vector<int> targetFreq(26);

		for (size_t i = 0; i < stickers.size(); ++i)
		{
			for (const char& c : stickers[i])
			{
				++stickerFreq[i][c - 'a'];
			}
		}

		for (const char& c : target)
		{
			++targetFreq[c - 'a'];
		}

		// bfs

		queue<vector<int>> q;
		q.push(targetFreq);

		for (size_t result = 0; !q.empty(); ++result)
		{
			for (int k = q.size(); k > 0; --k)
			{
				auto currFreq = q.front(); q.pop();

				// get current string from frequency count
				string currStr;
				for (size_t i = 0; i < 26; ++i)
				{
					if (currFreq[i] > 0)
					{
						// appends the character (i) currFreq[i] times (freq)
						currStr += string(currFreq[i], i);
					}
				}

				if (currStr.empty()) { return result; }

				// check if visited already, and continue if so
				if (visited.count(currStr)) { continue; }
				visited.insert(currStr);

				char seeking = currStr[0];
				for (auto v : stickerFreq)
				{
					if (v[seeking] > 0)
					{
						q.push(currFreq);

						for (size_t i = 0; i < 26; ++i)
						{
							q.back()[i] -= v[i];
						}
					}
				}
			}



		}


		return -1;

	}
};
int main()
{
	Solution s;
	vector<string> stickers = { "with", "example", "science" };
	string target = "thehat";
	s.minStickers(stickers, target);
	
	return 0;
}