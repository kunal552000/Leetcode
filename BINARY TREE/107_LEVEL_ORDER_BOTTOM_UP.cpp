/*


Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from 
left to right, level by level from leaf to root).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        
        if(root == NULL)
            return res;
        
        queue<TreeNode*> q;
        //stack<vector<int>> s;
        
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> v;
           for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
                
                
                v.push_back(node->val);
            }
            
          res.push_back(v);
            
        }
        
       // while(!s.empty())
        //{
        //    res.push_back(s.top());
         //   s.pop();
       // }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};
