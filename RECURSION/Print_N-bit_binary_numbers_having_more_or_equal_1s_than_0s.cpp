/*


Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s 
than 0’s for any prefix of the number.

Example 1:

Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than 
or equal 1's than 0's
Example 2:

Input:  N = 3
Output: 111 110 101
Explanation: 111, 110 and 101 have more 
than or equal 1's than 0's
User Task:
Your task is to complete the function NBitBinary() which takes a single number as input and returns the list of 
strings in decreasing order. You need not take any input or print anything.

Expected Time Complexity: O(|2N|)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 20

*/

//CODE


class Solution{
public:

   
    vector<string> res;
    
    void solve(string op, int one, int zero, int n)
    {
        if(n == 0)
        {
            res.push_back(op);
            return;
        }
        
        solve(op + '1' , one + 1, zero, n-1);  //choice of 1 is always valid
        
        if(one > zero)
        {
            solve(op + '0' , one, zero + 1, n-1);
            
        }
    }

	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    string op = "";
	    solve(op,0,0,N);
	    return res;
	}
};
