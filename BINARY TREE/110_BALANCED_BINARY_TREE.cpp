/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.

*/

//CODE

//O(n) approach

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
    int dfsh(TreeNode* root){
        if(root == NULL)
            return 0;
        int lh = dfsh(root->left);
        if(lh == -1)
            return -1;
        int rh = dfsh(root->right);
        if(rh == -1)
            return -1;
        if(abs(lh - rh) > 1)
            return -1;
        return max(lh,rh)+1;
            
    }
    bool isBalanced(TreeNode* root) {
        return dfsh(root) != -1;
        
    }
};



//O(n sq) approach

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
    int depth(TreeNode* root){
        if(root==NULL)
            return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int lh = depth(root->left);
        int rh = depth(root->right);
        return abs(lh - rh)<=1 && isBalanced(root->left) && isBalanced(root->right);
        
        
    }
    
};