/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    void preorder(TreeNode* root,string &ans)
    {
        if(root == NULL) 
        {
            ans += "#,";
            return;
        }

        ans += to_string(root->val) + ",";
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    string serialize(TreeNode* root) 
    {
        string ans = "";
        preorder(root,ans);
        return ans;
    }

    TreeNode* build (queue<string> &q)
    {
        string val = q.front();
        q.pop();
        if(val == "#")
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(val));

        root->left = build(q);
        root->right = build(q);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        queue<string> q;
        stringstream ss(data);
        string val;

        while(getline(ss,val,','))
        {
            q.push(val);
        }
        return build(q);
    }
};
