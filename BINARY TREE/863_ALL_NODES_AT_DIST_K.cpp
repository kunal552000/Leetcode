/*


Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of 
all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000


*/


//CODE


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void mark(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left)
            {
                q.push(node->left);
                parent[node->left] = node;
            }
            
            if(node->right)
            {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        //first is node.... second is parent
        
	//fnc for keeping track of parent node
        mark(root,parent);
        
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        
        q.push(target);
        vis[target] = true;
        int dist = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            if(dist == k)
                break;
            
            dist++;
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left && vis[node->left] == false)
                {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                
                if(node->right && vis[node->right] == false)
                {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                
                if(parent[node] && vis[parent[node]] == false)
                {
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
                    
            }
        }
        
        vector<int> res;
        
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        
        return res;
    }
};