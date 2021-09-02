/*


Given below is a binary tree. The task is to print the top view of binary tree. 
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function 
topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right. 
Print endline after end of printing the top view.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 = N = 105
1 = Node Data = 105
 

*/


//CODE


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> res;
        
        if(!root)
        return res;
        
        queue<pair<Node*,int>>q;
        //int denotes the vertical 
        
        map<int,int> mp;
        //first is vertical .. second is value
        
        q.push({root,0});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int vert = it.second;
            
            if(mp.find(vert) == mp.end())
            mp[vert] = node->data;
            
            if(node->left)
            q.push({node->left,vert-1});
            
            if(node->right)
            q.push({node->right,vert+1});
            
        }
        
        for(auto it : mp)
        res.push_back(it.second);
        
        
        return res;
    }

};