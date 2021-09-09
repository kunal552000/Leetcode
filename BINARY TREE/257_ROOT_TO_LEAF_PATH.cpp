/*


Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100


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
    
    void solve(TreeNode* root, string s, vector<string>& res)
    {
        
        
        if(!root->left && !root->right)
        {
            res.push_back(s);
            return;
        }
        
       if(root->left)
            solve(root->left, s + "->" + to_string(root->left->val), res);
        
      if(root->right)
           solve(root->right, s + "->" + to_string(root->right->val), res);
        
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> res;
        
        if(!root)
            return res;
        
        string s = "";
        
        s = s + to_string(root->val);
        
        
        solve(root,s,res);
        
        return res;
            
    }
};