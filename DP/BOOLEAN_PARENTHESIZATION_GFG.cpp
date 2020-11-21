/*

Given a boolean expression with following symbols.

Symbols
    'T' ---> true
    'F' ---> false

And following operators filled between symbols

Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR

Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

For Example:
The expression is "T | T & F ^ T", it evaluates true
in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T)
and (T|((T&F)^T)).

Return No_of_ways Mod 1003.

Input:
First line contains the test cases T.  1<=T<=500
Each test case have two lines
First is length of string N.  1<=N<=100
Second line is string S (boolean expression).
Output:
No of ways Mod 1003.
 

Example:
Input:
2
7
T|T&F^T
5
T^F|F

Output:
4
2

*/

//CODE

#include<bits/stdc++.h>
using namespace std;
int memo[1002][1002][2];

int solve(string &s, int i, int j, bool istrue)
{
    if(i > j)
        return false;
    if(i == j)
    {
        if(istrue == true)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    int ans = 0;
    for(int  k = i+1; k < j; k = k +2)
    {
        // lt = solve(s,i,k-1,true);
        //int lf = solve(s,i,k-1,false);
        //int rt = solve(s,k+1,j,true);
        //int rf = solve(s,k+1,j,false);
         int lt,rf,lf,rt;
        if(memo[i][k-1][true] != -1)
        {
            lt =  memo[i][k-1][true];
        }
        else
        {
            lt = solve(s, i ,k-1 , true);
            memo[i][k-1][true] = lt;
        }

        if(memo[k+1][j][false] != -1)
        {
            rf =  memo[k+1][j][false];
        }
        else
        {
            rf = solve(s, k+1 ,j , false);
            memo[k+1][j][false] = rf;
        }

        if(memo[i][k-1][false] != -1)
        {
            lf =  memo[i][k-1][false];
        }
        else
        {
            lf = solve(s, i ,k-1 , false);
            memo[i][k-1][false] = lf;
        }

        if(memo[k+1][j][true] != -1)
        {
            rt = memo[k+1][j][true];
        }
        else
        {
            rt = solve(s, k+1 ,j , true);
            memo[k+1][j][true] = rt;
        }

    if(s[k] == '&')
    {
        if(istrue == true)
            ans = ans + (lt * rt);
        else
            ans = ans + (lt * rf) + (lf * rt) + (lf * rf);
    }
    else if(s[k] == '|')
    {
        if(istrue == true)
            ans = ans + (lt * rt) + (lt * rf) + (lf * rt);
        else
            ans = ans + (lf * rf);
    }
    else if(s[k] == '^')
    {
        if(istrue == true)
            ans = ans + (lt * rf) + (lf * rt);
        else
            ans = ans + (lf * rf) + (lt * rt);
    }
    }
    return memo[i][j][istrue] = ans % 1003;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    memset(memo,-1,sizeof(memo));
    int n;
    cin>>n;
    string s;
   // cout<<"Enter the expression"<<endl;
    cin>>s;
    int res = solve(s,0,s.size()-1,true);
    cout<<res<<endl;
    }
    return 0;
}

