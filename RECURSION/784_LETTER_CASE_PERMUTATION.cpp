/*

Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

 

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]
Example 3:

Input: s = "12345"
Output: ["12345"]
Example 4:

Input: s = "0"
Output: ["0"]
 

Constraints:

s will be a string with length between 1 and 12.
s will consist only of letters or digits.

*/


//CODE

class Solution {
public:
    
    vector<string> res;
    
    void solve(string ip, string op)
    {
        if(ip.length() == 0)
        {
            res.push_back(op);
            return;
        }
        
        if(isalpha(ip[0]))
        {
            string op1 = op;
            string op2 = op;
            
            op1.push_back(tolower(ip[0]));
            op2.push_back(toupper(ip[0]));
            
            ip.erase(ip.begin() + 0);
            
            solve(ip,op1);
            solve(ip,op2);
        }
        
        else
        {
            string op1 = op;
            op1.push_back(ip[0]);
            
            ip.erase(ip.begin() + 0);
            
            solve(ip,op1);
        }
        
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        string op = "";
        
        solve(s,op);
        
        return res;
        
    }
};