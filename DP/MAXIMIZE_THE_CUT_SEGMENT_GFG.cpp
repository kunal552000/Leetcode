/*

Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Example 1:

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
Example 2:

Input:
N = 5
x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.
Your Task:
You only need to complete the function maximizeTheCuts() that takes n, x, y, z as parameters and returns max number cuts.

Expected Time Complexity : O(N)
Expected Auxiliary Space: O(N)

Constraints
1 <= N, x, y, z <= 104

*/

//CODE

int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    int arr[3] ={x,y,z};
    int memo[n+1];
    memo[0]= 0;
    for(int i = 1; i<n+1; i++)
    {
        memo[i] = INT_MIN;
        for (int j = 0; j < 3; j++) 
        {
             if ((i - arr[j]) >= 0   && memo[i - arr[j]] != INT_MIN)
             memo[i] = max(memo[i - arr[j]] + 1,  memo[i]); 
        }
    }
    return max(memo[n],0);
    
}