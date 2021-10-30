/*


Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input: 
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.

Example 2:

Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.

Your Task: 
You dont need to read input or print anything. Complete the function check() which takes root node as input parameter and returns 
true/false depending on whether all the leaf nodes are at the same level or not.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 = N = 10^3


*/

//CODE


class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        if(!root)
        return true;
        
        if(!root->left && !root->right)
        return true;
        
        int level = 0;
        int compare = -1;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            level++;
            
            for(int i = 0; i < size; i++)
            {
                Node* curr = q.front();
                q.pop();
                
                if(!curr->left && !curr->right)
                {
                    if(compare == -1)
                    compare = level;
                    
                    else
                    {
                        if(compare != level)
                        return false;
                    }
                }
                
                if(curr->left)
                q.push(curr->left);
                
                if(curr->right)
                q.push(curr->right);
            }
        }
        
        return true;
    }
};