/*

Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr

Your Task:
You dont need to read input or print anything. Complete the function reverseWords() which takes string S as input parameter 
and returns a string containing the words in reversed order. Each word in the returning string should also be separated by '.' 


Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)


Constraints:
1 <= |S| <= 2000

*/



//CODE



class Solution{
  public:
    string reverseWords(string S) 
    { 
        // code here 
        vector<string> res;
        string temp = "";
        int n = S.size();
        string ans = "";
        
        for(int i = 0; i < n ; i++)
        {
            if(S[i] == '.')
            {
                res.push_back(temp);
                res.push_back(".");
                temp = "";
            }
            else
            {
                temp = temp + S[i];
            }
        }
        res.push_back(temp);
        
        for(int i = res.size()-1; i>=0; i--)
        ans = ans + res[i];
        
        return ans;
        
        
    } 
};





