#include <iostream>
#include <queue>
using namespace std;

class MedianFinder 
{
public:
    MedianFinder(){}
    void addNum(int num)
    {
        maxHeap.push(num);

        // correct the number position by pushing it into minHeap if maxHeap is bigger  
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }


        // ensure maxHeap/minHeap size difference is not > 1
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }


        
    }

    double findMedian()
    {
        double ans = 0.0;
        // if heaps are same size, median is avg of both heap roots
        if (maxHeap.size() > minHeap.size())
        {
            ans =  maxHeap.top();  
        }
        else 
        {
            ans =  (maxHeap.top() + minHeap.top()) / 2.0; 
        }

        return ans;





    }
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, std::greater<int>> minHeap;


};


int main()
{
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    double param2 = obj->findMedian();
    obj->addNum(3);
    double param3 = obj->findMedian();


    delete obj;
    return 0;
}