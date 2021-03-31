/*

Given a string S, find the length of the longest substring without repeating characters.


Example 1:

Input:
S = "geeksforgeeks"
Output:
7
Explanation:
Longest substring is
"eksforg".
Example 2:

Input:
S = "ABDEFGABEF"
Output:
6
Explanation:
Longest substring is
"BDEFGA" and "DEFGAB".
 

Your Task:
You don't need to take input or print anything. 
Your task is to complete the function longestUniqueSubsttr() which takes a string S as and returns the length of the longest substring.

 

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).


Constraints:
1 <= |S| <= 10^4

*/

//CODE

class Solution{
    public:
    int longestUniqueSubsttr(string S){
        
        int n = S.size();
        
        int i = 0;
        int j = 0;
        
        
        
        int res = 0;
        
        unordered_map<char, int> mp;
        
        while(j < n)
        {
            mp[S[j]]++;
            
            
            if(mp.size() == j-i+1)
            {
                res = max(res,j-i+1);
                j++;
            }
            
            else if(mp.size() < j-i+1)
            {
                while(mp.size() < j-i+1)
                {
                    mp[S[i]]--;
                    
                    if(mp[S[i]] == 0)
                    mp.erase(S[i]);
                    
                    i++;
                }
                
                j++;
            }
        }
        return res;
        
    }
};