/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.

*/


//CODE


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        
        sort(strs.begin(),strs.end());
        
        string a = strs[0];
        string b = strs[n-1];
        
        int as = a.size();
        int bs = b.size();
        
        string res = "";
        int i = 0;
        
        while(i < as && i < bs)
        {
            if(a[i] != b[i])
                return res;
            
            else
                res = res + a[i];
            i++;
        }
        
        return res;
    }
};