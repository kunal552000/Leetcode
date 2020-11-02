/*

We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose any two rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the smallest possible weight of this stone (the weight is 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0 so the array converts to [1] then that's the optimal value.
 

Note:

1 <= stones.length <= 30
1 <= stones[i] <= 100

*/

//CODE

//THIS IS SAME AS MINIMUM SUBSET SUM DIFFERENCE


class Solution {
public:
    int subset(vector<int>& stones, int n)
    {
        int sum = 0;
        for(int i = 0; i<n;i++)
            sum = sum + stones[i];
        bool memo[n+1][sum+1];
        for(int i = 0; i< n+1; i++)
        {
            for(int j = 0 ; j<sum+1;j++)
            {
                if(i==0)
                    memo[i][j] = false;
                if( j==0)
                    memo[i][j] = true;
            }
        }
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<sum+1;j++)
            {
                if(stones[i-1] <= j)
                    memo[i][j] = memo[i-1][j-stones[i-1]] || memo[i-1][j];
                else
                    memo[i][j] = memo[i-1][j];
            }
        }
        vector<int> v;
        int l = n;
        for(int j = 0;j<=sum/2;j++)
        {
            if(memo[l][j] == true)
                v.push_back(j);
        }
        int res = INT_MAX;
        for(int i = 0;i<v.size();i++)
            res = min(res,sum-2*v[i]);
        return res;
    }
    int lastStoneWeightII(vector<int>& stones) {
        return subset(stones,stones.size());
        
    }
};