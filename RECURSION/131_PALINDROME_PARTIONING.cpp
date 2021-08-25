/*


Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.


*/


//CODE


class Solution {
public:
    
    
    bool ispal(string s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
    
    
    void solve(int index, string s, vector<string> &ds, vector<vector<string>>& res)
    {
        if(index == s.size())
        {
            res.push_back(ds);
            return ;
        }
        
        for(int i = index; i < s.size(); i++)
        {
            if(ispal(s,index,i))
            {
                ds.push_back(s.substr(index , i - index + 1));
                solve(i+1,s,ds,res);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        
        solve(0,s,ds,res);
        return res;
    }
};



