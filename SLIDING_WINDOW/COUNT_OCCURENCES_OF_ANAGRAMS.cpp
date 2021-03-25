/*


Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
Your Task:
Complete the function search() which takes two strings pat, txt, as input parameters and returns an integer denoting the answer. 
You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256)

Constraints:
1 <= |pat| <= |txt| <= 105
Both string contains lowercase english letters.

*/



//CODE


class Solution{
public:

     bool check(int pathash[26], int txthash[26])
    {
        for(int i =0;i<26;i++)
        {
            if(pathash[i] != txthash[i])
                return false;
        }
        return true;
    }
	int search(string pat, string txt) {
	    // code here

	    int count = 0;
	    int n = txt.size();
	    
	    int k = pat.size(); //window size
	    
        int pathash[26] = {0};
        int txthash[26] = {0};
        
        for(int a = 0; a < k; a++)
            pathash[pat[a]-'a']++;
        
        int i = 0;
        int j = 0;
        
        while(j < n)
        {
            txthash[txt[j]-'a']++;
            
            
            if(j-i+1 < k)
                j++;
            
            else if(j-i+1 == k)
            {
                if(check(pathash,txthash) == true)
                    count++;
                
                txthash[txt[i]-'a']--;
                
                i++;
                j++;
            }
            
        }
        return count;
	}

};
