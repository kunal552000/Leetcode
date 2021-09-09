/*


Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path 
equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000


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
    
    void haspath(TreeNode* root,int target,vector<int> &sum, vector<vector<int>>& res)
    {
        if(!root)
            return;
        
        sum.push_back(root->val);
        
        if(!root->left && !root->right)
        {
            if(target-root->val == 0)
            {
                
                res.push_back(sum);
            }
            
        }
        
       
        
        if(root->left)
        {
            
             haspath(root->left,target - root->val,sum,res);
            
        }
        if(root->right)
        {
            
            haspath(root->right,target - root->val,sum,res);
            
    
        }
        
        sum.pop_back();
    }
        
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> sum;
        
        if(!root)
            return res;
        
        haspath(root,targetSum,sum,res);
        
        return res;
    }
};


