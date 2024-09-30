#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() { delete next; }
};

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty()) { return nullptr; }
        ListNode* result = nullptr;
        ListNode* tail = nullptr;
        auto comparator = [](const ListNode* node1, const ListNode* node2)
            {
                return node1->val > node2->val;
            };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comparator)> queue(comparator);

        for (int i = 0; i < lists.size(); ++i)
        {
            while (lists[i] != nullptr)
            {
                queue.push(lists[i]);             
                lists[i] = lists[i]->next;
            }
        }

        while (!queue.empty())
        {
            // set tail
            if (!result)
            {
                result = queue.top();
                tail = result;
            }
            else
            {
                queue.top()->next = nullptr;
                tail->next = queue.top();
                tail = tail->next;

            }
            queue.pop();
        }
        return result;

    }
};

int main()
{
    Solution s;
    //vector<ListNode*> lists = { {new ListNode(1,new ListNode(4, new ListNode(5)))},
    //                            {new ListNode(1,new ListNode(3, new ListNode(4)))},
    //                            {new ListNode(2,new ListNode(6))} };

    vector<ListNode*> lists = { {new ListNode(-1,new ListNode(-1, new ListNode(-1)))},
                            {new ListNode(-2,new ListNode(-2, new ListNode(-1)))} };

    s.mergeKLists(lists);



    return 0;
}
