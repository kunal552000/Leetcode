/*


Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false
 

Constraints:

1 <= num <= 2^31 - 1


*/


//CODE


class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        
        int start = 1;
        int end = num;
        long mid;
        
        while(start <= end)
        {
            mid = start + (end - start) / 2;
            
            if((mid * mid) == num)
                return true;
            
            else if(mid * mid > num)
                end = mid-1;
            
            else
                start = mid+1;
            
            
        }
        return false;
    }
    
    
    
};