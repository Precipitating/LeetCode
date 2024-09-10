#include <iostream>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node 
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }

    ~Node() { delete next; delete random; next = nullptr; random = nullptr; }
};


class Solution
{
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> map;
        Node* headCopy = nullptr;
        Node* copyTraversal = head;

        // make original pointer a key to the NEW copy
        while (copyTraversal)
        {
            map[copyTraversal] = new Node(copyTraversal->val);
            copyTraversal = copyTraversal->next;

        }
        
        // go thru one more round and assign the next/random using the hash map key pointing to the new ptrs
        copyTraversal = head;
        headCopy = map[copyTraversal];

        while (copyTraversal)
        {
            headCopy->next = map[copyTraversal->next];
            headCopy->random = map[copyTraversal->random];

            headCopy = headCopy->next;
            copyTraversal = copyTraversal->next;
        }

        return map[head];
    }
};

int main()
{
    Solution s;

    Node* node1 = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node1->random = nullptr;
    node2->random = node1;
    node3->random = node5;
    node4->random = node3;
    node5->random = node1;

    s.copyRandomList(node1);


    return 0;
}