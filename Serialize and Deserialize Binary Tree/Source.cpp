#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;


 struct TreeNode
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     ~TreeNode() { delete left; delete right; }
 };

class Codec
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string result;
        LevelOrderSerialize(root, result);
        // level order traversal, can be any traversal method
        return result;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        TreeNode* result = new TreeNode(stoi(data.substr(0, data.find_first_of(' '))));

        if (result->val == INT_MIN) { result = nullptr; }
        

        LevelOrderDeserialize(data, result);



        return result;
    }

    void LevelOrderSerialize(TreeNode* root, string& str)
    {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* curr = q.front(); q.pop();
            if (curr == nullptr)
            {
                str.append(to_string(INT_MIN) + " ");
                continue;
            }
            else
            {
                str.append(to_string(curr->val) + " ");
            }
            
            q.push(curr->left);
            q.push(curr->right);
        }
    }

    void LevelOrderDeserialize(string& str, TreeNode* root)
    {

        str = str.substr(str.find_first_of(' ') + 1);
        stringstream s(str);
        int num;

        queue<TreeNode*> q;
        vector<int> toInt;
        q.push(root);
        TreeNode* tail = root;
        int idx = 0;

        while (s >> num)
        {
            toInt.push_back(num);

        }

        while (!q.empty() && idx < toInt.size())
        {
            auto front = q.front(); q.pop();
            tail = front;


            if (toInt[idx] != INT_MIN)
            {
                tail->left = new TreeNode(toInt[idx]);
                q.push(tail->left);
            }
            if (toInt[idx+1] != INT_MIN)
            {
                tail->right = new TreeNode(toInt[idx+1]);
                q.push(tail->right);
            }
            idx += 2;
            
            
        }

       
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    Codec ser, deser;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    TreeNode* ans = deser.deserialize(ser.serialize(root));
    return 0;
}