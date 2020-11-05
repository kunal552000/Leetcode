/*

Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input:
First line consists of T test cases. First line of every test case consists of n, denoting the size of array. Second line of every test case consists of price of ith length piece.

Output:
For each testcase, in a new line, print a single line output consists of maximum price obtained.

Constraints:
1 <= T <= 100
1 <= n <= 100
1 <= Ai <= 100

Example:
Input:
1
8
1 5 8 9 10 17 17 20
Output:
22

*/

//CODE

#include <iostream>
using namespace std;

int unboundedknapsack(int price[], int length[], int n)
{
    int memo[n+1][n+1];
    for(int i = 0; i<n+1; i++)
    {
        for(int j = 0 ; j< n+1; j++)
        {
            if(i==0 || j ==0)
            memo[i][j] = 0;
            
        }
    }
    for(int i = 1; i< n+1; i++)
    {
        for(int j =1 ; j< n+1; j++)
        {
            if(length[i-1] <= j)
            memo[i][j] = max(price[i-1] + memo[i][j-length[i-1]] , memo[i-1][j]);
            else
            memo[i][j] = memo[i-1][j];
            
        }
    }
    return memo[n][n];
}

int main() {
	int t;
	cin>>t;
	for(int z = 0; z < t;z++)
	{
	    int n;
	    cin>>n;
	    int price[n];
	    for(int i = 0; i< n;i++)
	    cin>>price[i];
	    int length[n];
	    for(int i = 0;i<n;i++)
	    length[i] = i+1;
	    int res = unboundedknapsack(price,length,n);
	    cout<<res<<endl;
	}
	return 0;
}