/*

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always 
travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you 
could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already 
included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1
      /   \
     2     3    
   
Output: 1 2 3
Explanation:


Example 2:

Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22
Explanation: 

 

 

 

 

 

 

 

 

Your Task:
This is a function problem. You don't have to take input. Just complete the function printBoundary() that takes the root 
node as input and returns an array containing the boundary values in anti-clockwise.

 

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

 

Constraints:
1 = Number of nodes = 105
1 = Data of a node = 105

*/


//CODE



class Solution {
public:
    
    bool isleaf(Node* root)
    {
        return !root->left && !root->right;
    }
    
    void leftbound(Node* root, vector<int>& res)
    {
        Node* curr = root->left;
        
        
        
        while(curr)
        {
            if(!isleaf(curr))
            res.push_back(curr->data);
            
            if(curr->left)
            curr = curr->left;
        
            else
            curr = curr->right;
        }
        
        
    }
    
    void leaf(Node* root, vector<int>& res)
    {
        if(isleaf(root))
        {
            res.push_back(root->data);
            return;
        }
        
         if (root->left) 
         leaf(root->left, res);
         
         
         if (root->right) 
         leaf(root->right, res);
        
        
    }
    
    void rightbound(Node* root, vector<int>& res)
    {
        Node* curr = root->right;
        vector<int> temp;
        
        
        
        while(curr)
        {
            if(!isleaf(curr))
            temp.push_back(curr->data);
            
            if(curr->right)
            curr = curr->right;
            
            else
            curr = curr->left;
            
        }
        
        for(int i = temp.size()-1 ; i>= 0; i--)
        {
            res.push_back(temp[i]);
        }
        
    }
    
    



    vector <int> printBoundary(Node *root)
    {
        //Your code here
        
        vector<int> res;
        
        if(!root)
        return res;
        
        if(!isleaf(root))
        res.push_back(root->data);
        
        leftbound(root,res);
        
        leaf(root,res);
        
        rightbound(root,res);
        
        
        return res;
    }
};
