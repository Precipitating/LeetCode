#include <iostream>
#include <queue>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        // if params empty then return other list
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        // assign head to the lowest value from both list
        if (head == nullptr)
        {
            if (list1->val <= list2->val)
            {
                head = new ListNode(list1->val);
                tail = head;
                list1 = list1->next;

            }
            else
            {
                head = new ListNode(list2->val);
                tail = head;
                list2= list2->next;
            }
        }
       
        
        while (list1 != nullptr && list2 != nullptr)    
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;

        }


        if (list1 != nullptr)
        {
            tail->next = list1;
        }

        if (list2 != nullptr)
        {
            tail->next = list2;
        }


        return head;
    }
};



int main()
{

    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* head2 = new ListNode(1);

    ListNode* num3 = new ListNode(4);
    ListNode* num = new ListNode(2,num3);

    ListNode* num2 = new ListNode(4);

    ListNode* num4 = new ListNode(3,num2);

    head->next = num;
    head2->next = num4;


    s.mergeTwoLists(head, head2);

    delete head;
    delete head2;





    return 0;
}