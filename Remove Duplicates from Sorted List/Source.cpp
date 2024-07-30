#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {

        if (head == nullptr) { return head; }
        ListNode* tail = head;
        ListNode* search = nullptr;

        while (tail->next != nullptr)
        {
            // if next element has same value,
            if (tail->next->val == tail->val)
            {
                // create copy of ptr of next element after the dupe
                search = new ListNode(tail->next->val, tail->next);

                // if next element after dupe is invalid, end of linked list
                if (search->next == nullptr)
                {
                    tail->next = nullptr;
                }
                else
                {
                    while (search != nullptr)
                    {
                        if (search->next == nullptr)
                        {
                            // if next elem is last element and is a dupe, then end of list.
                            if (search->val == tail->val)
                            {
                                tail->next = nullptr;
                                search = nullptr;
                            }
                            else
                            {
                                tail->next = search;
                                tail = tail->next;
                                search = nullptr;
                            }

                        }
                        else
                        {
                            if (search->val != tail->val)
                            {
                                tail->next = search;
                                tail = tail->next;
                                search = nullptr;
                            }
                            else
                            {
                                search = search->next;

                            }
                            
                        }


                    }
                }

            }
            else
            {
                tail = tail->next;
            }
        }


        return head;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* num3 = new ListNode(3);
    ListNode* num2 = new ListNode(3,num3);
    ListNode* num1 = new ListNode(2, num2);
    ListNode* num = new ListNode(1, num1);
    head->next = num;
    s.deleteDuplicates(head);



    delete head;
    delete num;
    delete num1;
    delete num2;

}