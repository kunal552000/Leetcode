/*

The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:




We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).
       1 2 3
       4 5 6
       7 8 9
       * 0 #


Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
Example 3:

Input: n = 3
Output: 46
Example 4:

Input: n = 4
Output: 104
Example 5:

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.
 

Constraints:

1 <= n <= 5000

*/


//CODE

class Solution {
public:
    int knightDialer(int n) {
        int mod = pow(10,9)+7;
        if(n==1)
            return 10;
        vector<long long int> button(10,1);
        vector<long long int> temp(10);
        button[5] = 0;
        for(int i = 1; i<n; i++)
        {
            temp[0] = (button[4] + button[6]) % mod;
            temp[1] = (button[6] + button[8]) % mod;
            temp[2] = (button[7] + button[9]) % mod;
            temp[3] = (button[4] + button[8]) % mod;
            temp[4] = (button[3] + button[9] + button[0]) % mod;
            temp[6] = (button[1] + button[7] + button[0]) % mod;
            temp[7] = (button[2] + button[6]) % mod;
            temp[8] = (button[1] + button[3]) % mod;
            temp[9] = (button[2] + button[4]) % mod;
            for(int i =0;i<10;i++)
                button[i] = temp[i];
        }
        int sum = 0;
        for(int i =0; i<10; i++)
            sum = (sum + button[i]) % mod;
        return sum;
        
        
    }
};