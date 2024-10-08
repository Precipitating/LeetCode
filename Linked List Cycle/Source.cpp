#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ~ListNode() { delete next; }
};

class Solution 
{
public:
 //   // hash map method
 //   bool hasCycle(ListNode* head) 
	//{
 //       while (head != nullptr)
 //       {
 //           if (seenNodes.count(head) == 0)
 //           {
 //               seenNodes[head] = idx;
 //               ++idx;
 //           }
 //           else
 //           {
 //               isCycle = true;
 //               break;
 //           }
 //           head = head->next;

 //       }
 //       return isCycle;
 //   }

    // hare and tortoise method, faster
    bool hasCycle(ListNode* head)
    {
        ListNode* hare = head;
        ListNode* tortoise = head;
        while (hare != nullptr && hare->next != nullptr)
        {
            hare = hare->next->next;
            tortoise = tortoise->next;

            if (hare == tortoise)
            {
                isCycle = true;
                break;
            }


        }
        return isCycle;
    }
private:
    unordered_map<ListNode*, int> seenNodes;
    bool isCycle = false;
    int idx = 0;
};
int main()
{
	Solution s;
    ListNode* head = new ListNode(3);
    ListNode* next1 = new ListNode(2);
    head->next = next1;
    ListNode* next2 = new ListNode(0);
    next1->next = next2;
    ListNode* next3 = new ListNode(-4);
    next2->next = next3;
    next3->next = next1;
    cout << s.hasCycle(head);
	return 0;
}