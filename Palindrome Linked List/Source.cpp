#include <iostream>
#include <stack>
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
    bool isPalindrome(ListNode* head)
    {
        bool result = true;
        ListNode* headCopy = head;
        stack<int> numberList;

        while (head != nullptr)
        {
            numberList.push(head->val);
            head = head->next;
        }
        head = headCopy;

        while (head != nullptr)
        {
            if (head->val != numberList.top())
            {
                result = false;
                break;
            }

            numberList.pop();
            head = head->next;


        }



        return result;

    }




};

int main()
{
    Solution s;
    ListNode* node = new ListNode(1, new ListNode(5, new ListNode(1)));
    cout << s.isPalindrome(node);


    delete node;

    return 0;
}