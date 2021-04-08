/*

Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

 

Example 1:

Input: n = 27
Output: true
Example 2:

Input: n = 0
Output: false
Example 3:

Input: n = 9
Output: true
Example 4:

Input: n = 45
Output: false
 

Constraints:

-2^31 <= n <= 2^31 - 1

*/

//CODE


class Solution {
public:
    bool isPowerOfThree(int n) {
        int i = 0;
        while(pow(3,i) <= n)
        {
            if(pow(3,i) == n)
                return true;
            
            i++;
                
        }
        return false;
    }
};