/*

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer

*/

//CODE

class Solution {
public:
    int coinchange(vector<int>& coins, int n, int amount)
    {
        int memo[n+1][amount+1];
        for(int i =0;i<n+1;i++)
        {
            for(int j = 0; j< amount+1; j++)
            {
                if(i == 0)
                    memo[i][j] = 0;
                if(j == 0)
                    memo[i][j] = 1;
            }
        }
        for(int i =1 ; i<n+1; i++)
        {
            for(int j = 1 ; j<amount+1; j++)
            {
                if(coins[i-1] <= j)
                    memo[i][j] = memo[i][j-coins[i-1]] + memo[i-1][j];
                else
                    memo[i][j] = memo[i-1][j];
            }
        }
        return memo[n][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return coinchange(coins,n,amount);
        
    }
};