#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity) : maxSize(capacity) {}

    int get(int key)
    {
        // if doesn't exist, return -1
        if (map.find(key) == map.end())
        {
            return -1; 
        }

        // if exists, move to recently used (front of list) and return val
        cache.splice(cache.begin(), cache, map[key]);
        return map[key]->second;
    }

    void put(int key, int value)
    {
        // if already exists, update key and push to front
        if (map.find(key) != map.end())
        {
            cache.splice(cache.begin(), cache, map[key]);
            map[key]->second = value;
            return;
        }
        else
        {
            // if over capacity, remove least accessed item and insert new one
            if (cache.size() == maxSize)
            {
                map.erase(cache.back().first);
                cache.pop_back();

            }
            // place the new value to front
            else
            {
                cache.emplace_front(key,value);
                map[key] = cache.begin();
            }
        }
    }

private:
    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int maxSize;
};


int main()
{
    int capacity = 2;
    int key = 0;
    int value = 0;
    LRUCache* obj = new LRUCache(capacity);
    int param_1 = obj->get(key);
    obj->put(key, value);
}