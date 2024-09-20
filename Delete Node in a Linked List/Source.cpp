#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode* node)
    {
        while (node)
        {
            if (node->next)
            {
                node->val = node->next->val;

                if (!node->next->next)
                {
                    node->next = nullptr;
                }
                node = node->next;
            }

        }
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);
    s.deleteNode(head->next->next);


    return 0;
}