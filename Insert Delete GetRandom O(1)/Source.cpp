#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet 
{
public:
    RandomizedSet() {}
   

    bool insert(int val)
    {
        bool isPresent = false;
        if (map.find(val) == map.end())
        {
            vals.push_back(val);
            map.emplace(val, vals.back());
            isPresent = true;
        }

        return isPresent;


    }

    bool remove(int val)
    {
        bool isPresent = false;
        // swap erase for O(1)
        if (map.find(val) != map.end())
        {
            isPresent = true;
            if (vals.size() > 1)
            {
                int idxToRemove = map[val];
                int lastElem = vals.back();

                // push num to back of vector
                swap(vals[map[val]], vals.back());
                
                // update the idx of swapped elem
                map[lastElem] = idxToRemove;

                // erase from both containers
                map.erase(val);
                vals.pop_back();
            }
            else
            {
                vals.pop_back();
                map.erase(val);
            }


        }

        return isPresent;
    }

    int getRandom()
    {
        return vals[rand() % vals.size()];
    }

private:
    vector<int> vals;
    unordered_map<int,int> map;
};

int main()
{
    RandomizedSet* obj = new RandomizedSet();
    bool param_2 = obj->remove(0);
    bool param_3 = obj->remove(0);
    bool param_4 = obj->insert(0);
    int param_5 = obj->getRandom();
    bool param_6 = obj->remove(0);
    bool param_7 = obj->insert(0);

    return 0;
}
