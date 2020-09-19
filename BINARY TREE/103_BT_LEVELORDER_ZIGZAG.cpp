/*

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        TreeNode* dummy = root;
        vector<vector<int>> res;
        if(dummy == NULL)
            return res;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(root);
        while(!s1.empty() || !s2.empty())
        {
            vector<int> temp ;
            while(!s1.empty()){
                dummy = s1.top();
                s1.pop();
                temp.push_back(dummy->val);
                if(dummy->left != NULL)
                    s2.push(dummy->left);
                if(dummy->right != NULL)
                    s2.push(dummy->right);
                
            }
            res.push_back(temp);
            temp.clear();
            while(!s2.empty())
            {
                dummy = s2.top();
                s2.pop();
                temp.push_back(dummy->val);
                if(dummy->right != NULL)
                    s1.push(dummy->right);
                if(dummy->left != NULL)
                    s1.push(dummy->left);
                
            }
            if(!temp.empty())
                res.push_back(temp);
            
                
        }
        return res;
        
    }
};