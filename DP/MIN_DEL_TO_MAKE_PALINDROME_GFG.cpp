/*

Given a string of S as input. Your task is to write a program to remove or delete minimum number of characters from the string so that the resultant string is palindrome.

Note: The order of characters in the string should be maintained.

Input:
First line of input contains a single integer T which denotes the number of test cases. Then T test cases follows. First line of each test case contains a string S.

Output:
For each test case, print the deletions required to make the string palindrome.

Constraints:
1<=T<=100
1<=length(S)<=10000

Example:
Input:
2
aebcbda
geeksforgeeks
Output:
2
8

*/

//code

#include <iostream>
using namespace std;

int lps(string &s, string &t, int n)
{
    int memo[n+1][n+1];
    for(int i = 0 ; i < n+1; i++)
    {
        for(int j = 0; j< n+1; j++)
        {
            if(i == 0 || j == 0)
            memo[i][j] = 0;
        }
    }
    for(int i = 1; i <n+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            if(s[i-1] == t[j-1])
            memo[i][j] = 1 + memo[i-1][j-1];
            else
            memo[i][j] = max(memo[i-1][j] , memo[i][j-1]);
        }
    }
    return n - memo[n][n];
}

int main() {
	int t;
	cin>>t;
	for(int i = 0; i < t; i++)
	{
	    string s;
	    cin>>s;
	    string t = "";
	    for(int i  = s.size()-1; i >= 0; i--)
	    t = t + s[i];
	    int res = lps(s,t,s.size());
	    cout<<res<<endl;
	}
	return 0;
}