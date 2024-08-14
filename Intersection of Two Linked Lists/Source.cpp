#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        while (headA != nullptr || headB != nullptr)
        {
            if (headA != nullptr)
            {
                if (seenNodes.count(headA) == 0)
                {
                    seenNodes.insert(headA);
                    headA = headA->next;
                }
                else
                {
                    return headA;
                }
            }

            if (headB != nullptr)
            {
                if (seenNodes.count(headB) == 0)
                {
                    seenNodes.insert(headB);
                    headB = headB->next;
                }
                else
                {
                    return headB;
                }

            }


        }

        return nullptr;
    }
private:
    unordered_set<ListNode*> seenNodes;
};


int main()
{
    Solution s;
    //ListNode* node = new ListNode(4);
    //ListNode* node1 = new ListNode(1);
    //node->next = node1;
    //ListNode* node2 = new ListNode(8);
    //node1->next = node2;
    //ListNode* node3 = new ListNode(4);
    //node2->next = node3;
    //ListNode* node4 = new ListNode(5);
    //node3->next = node4;
    //


    //ListNode* node01 = new ListNode(5);
    //ListNode* node02 = new ListNode(6);
    //node01->next = node02;
    //ListNode* node03 = new ListNode(1);
    //node02->next = node03;
    //node03->next = node2;


    ListNode* node = new ListNode(1);
    ListNode* node1 = new ListNode(9);
    node->next = node1;
    ListNode* node2 = new ListNode(1);
    node1->next = node2;
    ListNode* node3 = new ListNode(2);
    node2->next = node3;
    ListNode* node4 = new ListNode(4);
    node3->next = node4;



    ListNode* node01 = new ListNode(5);
    ListNode* node02 = new ListNode(6);

    ListNode* node03 = new ListNode(3);
    node03->next = node3;


    cout << s.getIntersectionNode(node, node03)->val;

    delete node; delete node1; delete node2; delete node3; delete node4; delete node01; delete node02; delete node03;
    return 0;
}