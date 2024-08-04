#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    // two pointer, swap in place O(n)
    void reverseString(vector<char>& s)
    {
        int first = 0, last = s.size() - 1;

        while (first < last)
        {
            char temp = s[last];
            s[last] = s[first];
            s[first] = temp;

            ++first;
            --last;

        }


    }
};



int main()
{
    Solution s;
    vector<char> word = { 'A',' ','m','a','n',',',' ','a',' ','p','l','a','n',',',' ','a',' ','c','a','n','a','l',':',' ','P','a','n','a','m','a' };

    s.reverseString(word);
}