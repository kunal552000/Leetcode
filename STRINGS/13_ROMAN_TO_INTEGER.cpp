/*


Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, 
the number four is written as IV. Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.


*/


//CODE


class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        
        int res = 0;
        
        int i = 0;
        
        while(i < n)
        {
            if(s[i] == 'I' && s[i+1] == 'V')
            {
                res = res + 4;
                i = i+2;
            }
            
            else if(s[i] == 'I' && s[i+1] == 'X')
            {
                res = res + 9;
                i = i + 2;
            }
            
            else if(s[i] == 'X' && s[i+1] == 'L')
            {
                res = res + 40;
                i = i + 2;
                
            }
            
            else if(s[i] == 'X' && s[i+1] == 'C')
            {
                res = res + 90;
                i = i + 2;
                
            }
            
            else if(s[i] == 'C' && s[i+1] == 'D')
            {
                res = res + 400;
                i = i + 2;
                
            }
            
            else if(s[i] == 'C' && s[i+1] == 'M')
            {
                res = res + 900;
                i = i + 2;
                
            }
            
            
            else
            {
                if(s[i] == 'I')
                    res = res + 1;
                
                else if(s[i] == 'V')
                    res = res + 5;
                
                else if(s[i] == 'X')
                    res = res + 10;
                
                else if(s[i] == 'L')
                    res = res + 50;
                
                else if(s[i] == 'C')
                    res = res + 100;
                
                else if(s[i] == 'D')
                    res = res + 500;
                
                else if(s[i] == 'M')
                    res = res + 1000;
                
                i++;
            }
        }
        
        
        return res;
                    
                        
                    
                 
        
    }
};