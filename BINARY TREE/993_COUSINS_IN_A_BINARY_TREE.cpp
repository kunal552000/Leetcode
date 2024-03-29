/*


Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the 
nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:


Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.


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
    bool isCousins(TreeNode* root, int x, int y) {
        
        if(x == root->val || y == root->val)
            return false;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int xlev,ylev;
        int level = 0;
        
        while(!q.empty())
        {
            level++;
            int size = q.size();
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->val == x)
                    xlev = level;
                
                if(curr->val == y)
                    ylev = level;
                
                if(curr->left && curr->right)
                {
                    if((curr->left->val == x && curr->right->val == y) || (curr->left->val == y && curr->right->val == x))
                    return false;
                }
                
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
                
            }
            
        }
        
        if(xlev == ylev)
            return true;
        
        return false;
        
    }
};