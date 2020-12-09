/*

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

0 <= k <= 109
0 <= prices.length <= 1000
0 <= prices[i] <= 1000

*/


//CODE


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0 || k == 0)
            return 0;
        int memo[k+1][n];
        for(int i = 0; i < k+1; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i ==0 || j == 0)
                    memo[i][j] = 0;
            }
        }
        for(int i = 1; i < k+1; i++)
        {
            int maxdiff = -prices[0];
            for(int j = 1; j< n; j++)
            {
             memo[i][j] = max(memo[i][j-1], prices[j]+maxdiff);
            maxdiff = max(maxdiff, memo[i-1][j] - prices[j]);
            }
        }
        return memo[k][n-1];
        
    }
};