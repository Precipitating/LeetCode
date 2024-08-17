#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode()
    {
        delete next;
        next = nullptr;
    }
};

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* current = head;
        ListNode* previous = nullptr;
        SwapNode(current, previous, &head);

        return head;

    }
    void SwapNode(ListNode* current, ListNode* previous, ListNode** head)
    {
        if (current != nullptr)
        {
            ListNode* next = current->next;
            swap(current->next, previous);

            SwapNode(next, current, head);
        }
        else
        {
            *head = previous;
        }



    }

};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    s.reverseList(head);
    return 0;
}