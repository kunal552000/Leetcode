/*

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

//CODE

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 1;
        int n = prices.size();
        if(n == 0)
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