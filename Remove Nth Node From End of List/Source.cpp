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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (n == 1 && head->next == nullptr)
        {
            head = nullptr;
            return head;
        }
        // check ahead, so we can determine if its nullptr which = end of list;
        int nAhead = n;

        head = GetNodeN(head, n);


        return head;

    }
    ListNode* GetAhead(ListNode* head, int n, int count )
    {
        if (count == n)
        {
            return head;
        }

        if (head != nullptr)
        {
            head = head->next;
        }


       return GetAhead(head, n, count+1);

        

    }

    ListNode* GetNodeN(ListNode* head, int n)
    {
        ListNode* curr = head;
        ListNode* ahead = GetAhead(curr, n, 0);

        if (ahead == nullptr)
        {
            head = head->next;
        }
        else if (ahead->next == nullptr)
        {
            head->next = head->next->next;
        }
        else
        {
            GetNodeN(head->next, n);
        }



        return head;



    }



};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    //ListNode* head = new ListNode(1, new ListNode(2));
    //ListNode* head = new ListNode(1);
    head = s.removeNthFromEnd(head, 2);

    delete head;
    return 0;
}