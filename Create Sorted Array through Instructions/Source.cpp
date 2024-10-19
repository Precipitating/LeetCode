#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int createSortedArray(vector<int>& instructions)
    {
        vector<pair<int, int>> pairVec;
        vector<int> lesser(instructions.size()), greater(instructions.size());
        for (int i = 0; i < instructions.size(); ++i)
        {
            pairVec.emplace_back(instructions[i],i);

        }
        MergeSort(0, pairVec.size() - 1, pairVec, lesser, greater);

        int result = 0;
        int mod = 1e9 + 7;
        for (size_t i = 0; i < instructions.size(); i++)
        {
            result += min(lesser[i], greater[i]);
            result %= mod;
        }

        return result;
    }

    void MergeSort(int first, int last, vector<pair<int,int>>& pairVec, vector<int>& lesser, vector<int>& greater)
    {
        if (first >= last) { return; }
        int mid = first + (last - first) / 2;

        MergeSort(first, mid, pairVec, lesser, greater);
        MergeSort(mid+1, last, pairVec, lesser, greater);
        Merge(first, mid, last, pairVec, lesser, greater);


    }

    void Merge(int first, int mid, int last, vector<pair<int, int>>& pairVec, vector<int>& lesser, vector<int>& greater)
    {
        // assign the lower/greater than i
        int firstTmp = first, k = first;
        for (int i = mid + 1; i <= last; ++i)
        {
            while (firstTmp <= mid && pairVec[firstTmp].first < pairVec[i].first)
            {
                ++firstTmp;
            }
            while (k <= mid && pairVec[k].first <= pairVec[i].first)
            {
                ++k;
            }
            lesser[pairVec[i].second] += firstTmp - first;
            greater[pairVec[i].second] += mid - k + 1;
        }


        // merge 
        vector<pair<int,int>> temp(last - first + 1);

        int f = first, m = mid + 1, r = 0;

        while (f <= mid && m <= last)
        {
            if (pairVec[f].first <= pairVec[m].first)
            {
                temp[r++] = pairVec[f++];
            }  
            else
            {
                temp[r++] = pairVec[m++];
            }
                
        }

        while (f <= mid)
        {
            temp[r++] = pairVec[f++];
        }
        while (m <= last)
        {
            temp[r++] = pairVec[m++];
        }

        move(temp.begin(), temp.end(), pairVec.begin() + first);

    }
};


int main()
{
    Solution s;
    vector<int> instr = { 1,5,6,2 };
    s.createSortedArray(instr);
    return 0;
}