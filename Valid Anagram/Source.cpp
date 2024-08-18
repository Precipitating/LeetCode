#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // using hash map O(n) runtime, O(k) space complexity.
    bool isAnagram(string s, string t)
    {
        bool result;
        unordered_map<char,int> map;
        unordered_map<char,int> map2;

        if (s.length() != t.length())
        {
            return false;
        }

        for (const char& c : s)
        {
            map[c] += 1;
        }

        for (const char& c : t)
        {
            map2[c] += 1;
        }

        result = (map == map2) ? true : false;

        return result;

    }
};


int main()
{
    Solution s;
    cout << s.isAnagram("anagram", "nagaram");
    return 0;
}
