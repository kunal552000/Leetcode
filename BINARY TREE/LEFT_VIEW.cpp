/*


Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 
The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:

Input:

Output: 10 20 40
Your Task:
You just have to complete the function leftView() that prints the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000


*/


//CODE


vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
   if(!root)
   return res;
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty())
   {
       res.push_back(q.front()->data);
       int size = q.size();
       
       for(int i = 0; i < size; i++)
       {
           Node* node = q.front();
           q.pop();
           
           if(node->left)
           q.push(node->left);
           
           if(node->right)
           q.push(node->right);
       }
   }
   
   return res;
}
