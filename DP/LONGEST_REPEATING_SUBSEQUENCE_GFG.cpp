/*

Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the length of string str.

The second line of each test case contains the string str consisting only of lower case english alphabets.

Output:

Print the length of the longest repeating subsequence for each test case in a new line.


Constraints:

1<= T <=100

1<= N <=1000


Example:

Input:

2

3

abc

5

axxxy

Output:

0

2

*/

//CODE

#include <iostream>
using namespace std;

int lrs(string &s, string &t, int n)
{
    int memo[n+1][n+1];
    for(int i = 0 ; i <n+1; i++)
    {
        for(int j = 0 ; j < n +1; j++)
        {
            if(i == 0 || j == 0)
            memo[i][j] = 0;
        }
    }
    for(int i = 1; i< n+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            if(s[i-1] == t[j-1] && i != j)
            memo[i][j] = 1 + memo[i-1][j-1];
            else
            memo[i][j] = max(memo[i-1][j] , memo[i][j-1]);
        }
    }
    return memo[n][n];
}

int main() {
	//code
	int t;
	cin>>t;
	for(int i = 0 ; i < t ; i++){
	int n;
	cin>>n;
	string s;
	cin>>s;
	string t;
	t = s;
	int res = lrs(s,t,n);
	cout<<res<<endl;
	}
	return 0;
}