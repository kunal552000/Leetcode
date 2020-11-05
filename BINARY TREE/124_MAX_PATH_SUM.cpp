/*

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any node sequence from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
 

Constraints:

The number of nodes in the tree is in the range [0, 3 * 104].
-1000 <= Node.val <= 1000

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
    int search(TreeNode* root, int& maxsum)
    {
        if(!root)
            return 0;
        int lefts = search(root->left,maxsum);
        int rights = search(root->right,maxsum);
        if(lefts < 0)
            lefts = 0;
        if(rights < 0)
            rights  = 0;
        if(lefts+rights+root->val > maxsum)
            maxsum = lefts+rights+root->val;
        return root->val+max(lefts,rights);
        }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        search(root, maxsum);
        return maxsum;
        
    }
};