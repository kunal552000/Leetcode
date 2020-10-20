/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

*/

//CODE

class Solution {
public:
   vector<string> res;
    void dfs(string s, int openingbracket, int closingbracket)
    {
        if(openingbracket)
            dfs(s+'(', openingbracket-1, closingbracket);
        if(closingbracket > openingbracket)
            dfs(s+')', openingbracket, closingbracket-1);
        if(!closingbracket)
            res.push_back(s);
    }
    vector<string> generateParenthesis(int n) {
        
        dfs("",n,n);
        return res;
    }
};