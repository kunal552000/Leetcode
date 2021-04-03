/*

Given a string of lower case english letters and a substring length, determine the substring of that length 
that contains the most vowels. Vowels are in the set {a,e,i,o,u}. If there are more than 1 substrings with max no
of vowels, return the ones that start at lowest index.
If no substring return "Not found!"

Input :
	s = caberqiitefg
	k = 5
output :
 	erqii

*/

//CODE


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'findSubstring' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string findSubstring(string s, int k) {
       int n = s.size();
       int count = 0;
       int index;
       int c = 0;
       string res = "";
       int i = 0;
       int j = 0;
       string ans = "Not found!";
       while(j < n)
       {
           if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
           {
               count++;
               
           }
           if(j-i+1 < k)
           j++;
           
           else if(j-i+1 == k)
           {
               if(c < count)
               {
                   c = count;
                   index = i;
               }
               
               if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
           {
               count--;
               
           }
           i++;
           j++;
               
           }
       }
       
       if(c == 0)
       return ans;
       
       for(int a = index; a < index+k ; a++)
       res = res + s[a];
       
       return res;
}
