#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) 
    {
        if (!root) { return nullptr; }
        if (root->left && root->right)
        {
            root->left->next = root->right;
        }

        Solve(root->left);
        Solve(root->right);

        return root;

    }

    void Solve(Node* side)
    {
        if (!side) { return; }
        if (side->next != nullptr)
        {
            if (side->left) { side->left->next = side->right; }
            if (side->right) { side->right->next = side->next->left; }
        }
        else
        {
            if (side->left) { side->left->next = side->right; }


        }
        Solve(side->left);
        Solve(side->right);

    }

};
int main()
{
    Solution s;
    //Node* node = new Node(1, new Node(2, new Node(4), new Node(5),nullptr), new Node(3, new Node(6), new Node(7),nullptr),nullptr);
    Node* node = new Node(0);
    s.connect(node);
    return 0;
}