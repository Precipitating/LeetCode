#include <iostream>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() { delete next; next = nullptr; }
};

class Solution 
{
public:
    ListNode* sortList(ListNode* head)
    {
        if (!head || head->next == nullptr) { return head; }

        // split list in half
        ListNode* left = head;
        ListNode* right = GetMiddle(head);
        ListNode* rightTemp = right->next;
        right->next = nullptr;
        right = rightTemp;

        // recursively half both halves and sort them via merge sort.
        left = sortList(left);
        right = sortList(right);


        return Merge(left,right);
    }

    ListNode* Merge(ListNode* left, ListNode* right )
    {
        // curr will include merged list
        ListNode* curr = new ListNode();
        // stored value to head to return, as curr will traverse thru
        ListNode* dummy = curr;

        // assign lower value from each half first
        while (left && right)
        {
            if (left->val < right->val)
            {
                curr->next = left;
                left = left->next;
            }
            else
            {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        // assign rest of values to end if theres still some remaining
        if (left) { curr->next = left; }
        if (right) { curr->next = right; }

        return dummy->next;

    }

    // get middle element (hare and tortoise method)
    ListNode* GetMiddle(ListNode* node)
    {

        ListNode* hare = node->next;
        ListNode* tortoise = node;

        while (hare && hare->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;

        }

        return tortoise;

    }

};


int main()
{
    Solution s;
    ListNode* node = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    s.sortList(node);

    delete node;

    return 0;
}