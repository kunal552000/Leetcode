/*


You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4


*/


//CODE



class Solution {
public:
    int unbounded(vector<int>& coins, int amount, int n)
    {
        int memo[n+1][amount+1];
        for(int i = 0; i< n+1; i++)
        {
            for(int j = 0; j<amount+1; j++)
            {
                if(i == 0)
                    memo[i][j] = INT_MAX-1;
                if( j == 0 && i != 0)
                    memo[i][j] = 0;
            }
        }
        int k = 1;
        for(int  j = 1 ;j <amount+1; j++)
        {
            if(j % coins[0] == 0)
                memo[k][j] = j/coins[0];
            else
                memo[k][j] = INT_MAX-1;
        }
        for(int i =2 ; i<n+1; i++)
        {
            for(int j = 1; j< amount+1; j++)
            {
                if(coins[i-1] <= j)
                    memo[i][j] = min(1+memo[i][j-coins[i-1]] , memo[i-1][j]);
                else
                    memo[i][j] = memo[i-1][j];
            }
        }
        if(memo[n][amount] == INT_MAX-1 )
            return -1;
        return memo[n][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n  = coins.size();
        return unbounded(coins,amount,n);
        
    }
};
