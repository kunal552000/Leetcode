/*

You are given K eggs, and you have access to a building with N floors from 1 to N. 

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 

Your goal is to know with certainty what the value of F is.

What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

 

Example 1:

Input: K = 1, N = 2
Output: 2
Explanation: 
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.
Example 2:

Input: K = 2, N = 6
Output: 3
Example 3:

Input: K = 3, N = 14
Output: 4
 

Note:

1 <= K <= 100
1 <= N <= 10000

*/

//CODE

class Solution {
public:
    int memo[102][10002];
    int solve(int K, int N)
    {
        if(K == 1 || N == 1 || N == 0)
            return N;
        if(memo[K][N] != -1)
            return memo[K][N];
        int mn = INT_MAX;
       int l=1,h=N,temp=0;
       while(l<=h)
        {
            int mid = (l+h)/2;
            int left = solve(K-1,mid-1);   //egg broken check for down floors of mid
            int right = solve(K,N-mid) ;   // not broken check for up floors of mid
            temp = 1 + max(left,right);          //store max of both 
            if(left<right){                  //since right is more than left and we need more in worst case 
              l = mid + 1;                       // so l=mid+1 to gain more temp for worst case : upward
            }
            else                             //left > right so we will go downward 
            {    
                h = mid - 1;
            }
            mn = min(mn,temp);               //store minimum attempts
        } 
    return memo[K][N] = mn;
    }
    int superEggDrop(int K, int N) {
       memset(memo,-1,sizeof(memo));
        return solve(K,N);
        
        
        
    }
};