/*

Print all permutations of a string keeping the sequence but changing cases.
Examples: 
 

Input : ab
Output : AB Ab ab aB

Input : ABC
Output : abc Abc aBc ABc abC AbC aBC ABC

*/


//CODE




#include <bits/stdc++.h>
using namespace std;


void solve(string ip, string op)
{
    if(ip.length() == 0)
    {
        cout<<op<<" ";
        return;
    }

    string op1 = op;
    string op2 = op;

    op1.push_back(ip[0]);
    op2.push_back(toupper(ip[0]));

    ip.erase(ip.begin() + 0);

    solve(ip,op1);
    solve(ip,op2);

    return;
}

int main()
{
    string s;
    cout<<"Enter string in lower case"<<endl;
    cin>>s;

    string op = "";
    solve(s,op);
    return 0;

}





