/*

Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings

Example 1:

Input:
S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".
 

Example 2:

Input:
S = "AB"
Output: (A B)(AB)

Your Task:  
You don't need to read input or print anything. Your task is to complete the function permutation() which takes the string S 
as input parameters and returns the sorted array of the string denoting the different permutation (DON'T ADD '(' and ')' 
it will be handled by the driver code only).

Expected Time Complexity: O(2^n)
Expected Auxiliary Space: O(1)

 

CONSTRAINTS:
1 < |S| < 10
S only contains lowercase and Uppercase English letters.

*/


//CODE


class Solution{
public:

   vector<string> res;
   
   void solve(string ip, string op)
   {
       if(ip.length() == 0)
       {
           res.push_back(op);
           return;
           
       }
       
       string op1 = op;
       string op2 = op;
       
       op1 = op1 + " ";
       op1.push_back(ip[0]);
       op2.push_back(ip[0]);
       
       ip.erase(ip.begin() + 0);
       
       solve(ip,op1);
       solve(ip,op2);
       
       return;
   }

    vector<string> permutation(string S){
        // Code Here
        
        string op = "";
        op.push_back(S[0]);
        
        S.erase(S.begin() + 0);
        solve(S,op);
        
        return res;
    }
};