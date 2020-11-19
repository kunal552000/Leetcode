/*

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:

1 <= s.length <= 2000
s consists of lower-case English letters only.

*/

//CODE

class Solution {
public:
    
    int memo[2002][2002];
    int pald[2002][2002];

    bool ispalindrome(string &s,int i, int j)
{
     if(i>=j) return 1;
    if(pald[i][j]!=-1) 
        return pald[i][j];
    if(s[i]==s[j]) 
        return pald[i][j]=ispalindrome(s,i+1,j-1);
    return pald[i][j]=0;
}

int solve(string &s, int i, int j)
{
    if(i >= j)
        return 0;
    if(ispalindrome(s,i,j))
        return 0;
    if(memo[i][j] != -1)
        return memo[i][j];
     //if(ispalindrome(s,i,j))
       // return 0;
    int left,right;
    int min = INT_MAX;
    for(int k = i; k < j; k++)
    {
        
        if(memo[i][k] != -1)
            left = memo[i][k];
        else
        {
            left = solve(s,i,k);
            memo[i][k] = left;
        }

         if(memo[k+1][j] != -1)
            right = memo[k+1][j];
        else
        {
            right = solve(s,k+1,j);
            memo[k+1][j] = right;
        }

        int temp = 1 + left + right;

        if(temp < min)
            min = temp;
    }
    return memo[i][j] = min;
}
    int minCut(string s) {
        memset(memo,-1,sizeof(memo));
        memset(pald,-1,sizeof(pald));
        return solve(s,0,s.size()-1);
        
    }
};