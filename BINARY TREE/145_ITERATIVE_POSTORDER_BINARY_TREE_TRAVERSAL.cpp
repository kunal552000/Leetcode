/*

Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?

*/

//CODE

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == NULL)
            return v;
        
        stack<TreeNode* >s1;
        stack<TreeNode* >s2;
        s1.push(root);
        while(!s1.empty())
        {
            root = s1.top();
            s1.pop();
            s2.push(root);
            if(root->left != NULL)
                s1.push(root->left);
            if(root->right != NULL)
                s1.push(root->right);
        }
        while(!s2.empty())
        {
            root = s2.top();
            s2.pop();
            v.push_back(root->val);
        }
        return v;
        
    }
};