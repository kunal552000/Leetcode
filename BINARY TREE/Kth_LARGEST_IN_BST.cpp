/*

Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification 
in Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an 
integer K as inputs and returns the Kth largest element in the given BST.


Expected Time Complexity: O(H + K).
Expected Auxiliary Space: O(H)


Constraints:
1 <= N <= 1000
1 <= K <= N

*/



//CODE


class Solution
{
    public:
    
    int ans;
    
    void solve(Node* root,int k,int& count)
    {
        if(!root)
        return;
        
        solve(root->right,k,count);
        
        if(count == k)
        {
            ans = root->data;
            count++;
            return;
        }
        
        else
        count++;
        
        solve(root->left,k,count);
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        
        int count = 1;
        ans = -1;
        
        solve(root,K,count);
        
        return ans;
        
    }
};