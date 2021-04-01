/*

John is at a toy store, help him pick maximum number of toys. 
He can only select in a continuous manner and he can select only two types of toys.


Example:
Input:

s = abaccab

Output : 4 (acca)

*/

//This is exact as longest substr with K unique char with K  = 2

#include<bits/stdc++.h>
using namespace std;

int longsubstr(string &s, int k)
{
    int n = s.size();
    int i = 0;
    int j = 0;
    int ans = 0;
    
    unordered_map<char,int> mp;
    
    while(j < n)
    {
        mp[s[j]]++;
        
        if(mp.size() < k)
        j++;
        
        else if(mp.size() == k)
        {
            ans = max(ans,j-i+1);
            j++;
        }
        
        else if(mp.size() > k)
        {
            while(mp.size() > k)
            {
                mp[s[i]]--;
                
                if(mp[s[i]] == 0)
                mp.erase(s[i]);
                
                i++;
            }
            j++;
        }
    }
    return ans;
}

int main()
{
    string s;
    cout<<"Enter the string"<<endl;
    cin>>s;
    
    int k = 2;
    
    int res = longsubstr(s,k);
    cout<<"Max no of toys is "<<res<<endl;
    return 0;
}