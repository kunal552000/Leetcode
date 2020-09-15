/*

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

*/

/*
We will do level order traversal and print the last node of the each level
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *>queue;
        vector<int>res;
        if(!root)
            return res;
        queue.push(root);
        while(!queue.empty()){
            res.push_back(queue.back()->val);
            for(int i = queue.size();i>0;i--){
                TreeNode* temp = queue.front();
                queue.pop();
                if(temp->left)
                    queue.push(temp->left);
                if(temp->right)
                    queue.push(temp->right);
            }
        }
        return res;
        
    }
};