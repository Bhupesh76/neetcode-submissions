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

class Solution {
public:
    bool issametree(TreeNode* p, TreeNode* q)
    {
        if(p == NULL || q == NULL)
        {
            return p == q;
        }

        if(p->val != q->val) return false;  

        bool left = issametree(p->left,q->left);
        bool right = issametree(p->right,q->right);

        return left && right && p->val == q->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root == NULL) return false;

        if(issametree(root,subRoot)) return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
