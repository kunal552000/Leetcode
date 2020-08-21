/*

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return checker(0,0,inorder.size()-1,preorder,inorder);
        
    }
    public :
        TreeNode* checker(int prestart,int instart, int inend, vector<int> &preorder,vector<int> &inorder)
        {
            if(prestart>preorder.size()-1 || instart>inend)
                return NULL;
            TreeNode* root = new TreeNode(preorder[prestart]);
            int inindex = 0;
            for(int i = instart; i<=inend; i++)
            {
                if(inorder[i]== root->val)
                    inindex = i;
            }
            root->left = checker(prestart+1,instart,inindex-1,preorder,inorder);
            root->right = checker(prestart+inindex+1-instart,inindex+1,inend,preorder,inorder);
            return root;
            
        }
};