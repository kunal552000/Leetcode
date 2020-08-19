/*

Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == NULL)
            return v;
        TreeNode* temp = root;
        stack<TreeNode *>s;
        s.push(root);
        while(!s.empty())
        {
            temp = s.top();
            s.pop();
            v.push_back(temp->val);
            if(temp->right != NULL)
                s.push(temp->right);
            if(temp->left != NULL)
                s.push(temp->left);
            
        }
        return v;
    }
        
        
    
};