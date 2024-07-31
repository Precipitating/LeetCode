#include <iostream>
#include <string>
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
    // simulate addition by hand
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* answer = new ListNode();
        ListNode* empty = new ListNode();
        ListNode* tail = answer;
        int remainder = 0;
        int currentVal;


        while (l1 != nullptr || l2 != nullptr)
        {
            // add the numbers.
            if (!l1) { currentVal = l2->val; }
            else if (!l2) { currentVal = l1->val; }
            else { currentVal = l1->val + l2->val; }

            if (remainder == 1) { ++currentVal; --remainder; }

            // check if > 10, and handle the remainder
            if (currentVal >= 10)
            {
                tail->val = currentVal % 10;
                ++remainder;
            }
            else
            {
                tail->val = currentVal;
            }


            if ((l1 != nullptr && l1->next != nullptr) || (l2 != nullptr && l2->next != nullptr))
            {
                tail->next = new ListNode();
                tail = tail->next;
            }

            
            
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;



        }

        if (remainder == 1)
        {
            tail->next = new ListNode(1);
        }

        return answer;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(9);
    ListNode* num5 = new ListNode(9);
    ListNode* num4 = new ListNode(9,num5);
    ListNode* num3 = new ListNode(9,num4);
    ListNode* num2 = new ListNode(9,num3);
    ListNode* num1 = new ListNode(9,num2);
    ListNode* num = new ListNode(9,num1);

    ListNode* head2 = new ListNode(9);
    ListNode* num03 = new ListNode(9);
    ListNode* num02 = new ListNode(9, num03);
    ListNode* num01 = new ListNode(9,num02);



    head->next = num;
    head2->next = num01;
    s.addTwoNumbers(head, head2);



    delete head;
    delete head2;
    delete num;
    delete num1;
    delete num2;
    delete num3;
    delete num4;
    delete num5;
    delete num01;
    delete num02;
    delete num03;

}