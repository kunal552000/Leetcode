/*

Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two space-separated strings.

Output:
For each testcase, in a new line, output the length of the required string.

Expected Time Complexity: O(Length(str1) * Length(str2)).
Expected Auxiliary Space: O(Length(str1) * Length(str2)).

Constraints:
1 <= T <= 100
1<= |str1|, |str2| <= 100

Example:
Input:
2
abcd xycd
efgh jghi
Output:
6
6
Explanation:
Test Case 1: One of the shortest answer can be abxycd, which is of length 6.
*/

//code

// approach is to add the length of the strings and subtract it with lcs

#include <iostream>
using namespace std;


int scs(string &s1, string &s2, int m, int n)
{
    int memo[m+1][n+1];
    for(int i = 0; i< m+1; i++)
    {
        for(int j = 0; j<n+1; j++)
        {
            if(i == 0 || j == 0)
            memo[i][j] = 0;
        }
    }
    for(int i = 1; i <m+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            if(s1[i-1] == s2[j-1])
            memo[i][j] = 1 + memo[i-1][j-1];
            else 
            memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
        }
    }
    int lcs = memo[m][n];
    return m+n-lcs;
}

int main() {
	int t;
	cin>>t;
	for(int z  = 0 ;z <t;z++)
	{
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    int m = s1.size();
	    int n = s2.size();
	    int res = scs(s1,s2,m,n);
	    cout<<res<<endl;
	}
	return 0;
}