#include <iostream>
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
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode* sortedHead = nullptr;
        ListNode* odd = nullptr;
        ListNode* even = nullptr;
        ListNode* evenHead = nullptr;
        int idx = 1;

        while (head != nullptr)
        {
            if (idx % 2 == 0)
            {
                if (!even)
                {
                    even = head;
                    evenHead = head;
                }
                else
                {
                    even->next = head;
                    even = even->next;
                }
            }
            else
            {
                if (!odd)
                {
                    odd = head;
                    sortedHead = odd;
                }
                else
                {
                    odd->next = head;
                    odd = odd->next;
                }
            }

            ++idx;
            head = head->next;


        }
        if (even) { even->next = nullptr; }
        if (odd)  { odd->next = evenHead;}
        

        return sortedHead;
    }
};

int main()
{
    Solution s;

    ListNode* node = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    s.oddEvenList(node);
    delete node;
    return 0;
}