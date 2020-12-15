/*

Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Example 1:

Input:
N = 2, K = 10
Output: 4
Example 2:

Input:
N = 3, K = 5
Output: 3
Your Task:
Complete the function eggDrop() which takes two positive integer N and K as input parameters and returns the minimum number of attempts you need in order to find the critical floor.

Expected Time Complexity : O(N*K)
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=10
1<=K<=50

*/

//CODE

int memo[12][52];
    int solve(int K, int N)
    {
        if(K == 1 || N == 1 || N == 0)
            return N;
        if(memo[K][N] != -1)
            return memo[K][N];
        int mn = INT_MAX;
    for(int k = 1; k <= N; k++)
    {
        int temp = 1 + max(solve(K-1,k-1) , solve(K,N-k) );
        mn = min(mn, temp);
    }
    return memo[K][N] = mn;
    }
int eggDrop(int n, int k) 
{
    // your code here
    int K = n;
    int N = k;
     memset(memo,-1,sizeof(memo));
        return solve(K,N);
}