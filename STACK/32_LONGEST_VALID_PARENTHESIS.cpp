/*


Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.


*/


//CODE



class Solution {
public:
    int longestValidParentheses(string s) {
        int count = 0;
        stack<int> st;
        st.push(-1);
        
        
        for(int i = 0; i < s.size(); i++)
        {
           if(s[i] == '(')
               st.push(i);
            
            else
            {
                st.pop();
                if(st.empty())
                    st.push(i);
                
                else
                {
                    int len = i - st.top();
                    count = max(count,len);
                }
            }
        }
        
        return count;
    }
};