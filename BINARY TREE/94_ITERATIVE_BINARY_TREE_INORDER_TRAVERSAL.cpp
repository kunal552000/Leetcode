/*

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == NULL)
            return v;
        stack<TreeNode* >s;
        TreeNode* temp = root;
        while(true){
            if(root!=NULL)
            {
                s.push(root);
                root = root->left;
            }
            else{
                if(s.empty())
                    break;
                root = s.top();
                s.pop();
                v.push_back(root->val);
                root = root->right;
            }
            
        }
        return v;
        
    }
};