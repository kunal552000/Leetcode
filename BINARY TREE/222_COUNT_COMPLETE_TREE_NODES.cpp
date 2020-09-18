/*

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

*/

//CODE

//ITERATIVE WAY

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
    void inorder(TreeNode* root,vector<int>&v)
    {
        
        if(root == NULL)
            return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
        
        
    }
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int count = 0;
        vector<int>v;
        inorder(root,v);
        int i;
        for(i=0;i<v.size();i++)
            count++;
        return count;
        
    }
};


//RECURSIVE SOLUTION

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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int lh = 0;
        int rh = 0;
        TreeNode* leftside = root;
        TreeNode* rightside = root;
        while(leftside){
            lh++;
            leftside = leftside->left; 
        }
        while(rightside){
            rh++;
            rightside = rightside->right;
        }
        if(lh == rh)
            return pow(2,lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};