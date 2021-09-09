/*


Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
Example 2:

Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node 
of the Binary Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, 
return the size of the complete Binary Tree. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 = Number of nodes = 105
1 = Data of a node = 106


*/


//CODE



class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    vector<int> solve(Node* root)
    {
        if(!root)
        return {1,0,INT_MAX,INT_MIN};
        
        if(!root->left && !root->right)
        return {1,1,root->data,root->data};
        
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        
        if(l[0] == 1 && r[0] == 1)
        {
            //compare root with max in left and min in right
            if(root->data > l[3] && root->data < r[2])
            {
                int leftval = l[2];
                int rightval = r[3];
                
                if(leftval == INT_MAX)
                leftval = root->data;
                
                if(rightval == INT_MIN)
                rightval = root->data;
                
                return {1, l[1]+ r[1] + 1, leftval, rightval};
            }
        }
        
        return {0, max(l[1],r[1]),0,0};
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	
    	vector<int> res = solve(root);
    	//res[0] is boolean for checking isbst
    	//res[1] is size
    	//res[2] is min 
    	//res[3] is max
    	
    	return res[1];
    }
};