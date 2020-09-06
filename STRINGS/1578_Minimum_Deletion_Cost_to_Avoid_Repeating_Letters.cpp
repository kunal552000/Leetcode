/*

Given a string s and an array of integers cost where cost[i] is the cost of deleting the character i in s.

Return the minimum cost of deletions such that there are no two identical letters next to each other.

Notice that you will delete the chosen characters at the same time, in other words, after deleting a character, the costs of deleting other characters will not change.

 

Example 1:

Input: s = "abaac", cost = [1,2,3,4,5]
Output: 3
Explanation: Delete the letter "a" with cost 3 to get "abac" (String without two identical letters next to each other).
Example 2:

Input: s = "abc", cost = [1,2,3]
Output: 0
Explanation: You don't need to delete any character because there are no identical letters next to each other.
Example 3:

Input: s = "aabaa", cost = [1,2,3,4,1]
Output: 2
Explanation: Delete the first and the last character, getting the string ("aba").
 

Constraints:

s.length == cost.length
1 <= s.length, cost.length <= 10^5
1 <= cost[i] <= 10^4
s contains only lowercase English letters.

*/

//CODE

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int mincost = 0;
        int i = 0;
        int j = 1;
        while(i<s.size()-1){
            if(s[i]==s[j])
            {
                if(cost[i] <= cost[j]){
                    mincost = mincost + cost[i];
                    i = j;
                    j++;
                }
                else if(cost[i] > cost[j]){
                    mincost = mincost + cost[j];
                    j++;
                }
            }
            else{
                i=j;
                j++;
            }
        }
        return mincost;
        
    }
};