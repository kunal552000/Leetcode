/*

Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of
the denominations in Indian currency, i.e., we have an infinite supply
 of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the
 minimum number of coins and/or notes needed to make the change?

 */


 //CODE




#include<bits/stdc++.h>
using namespace std;

int main(){

    int deno[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};

    int n = sizeof(deno)/sizeof(deno[0]);

    int v;
    cout<<"Enter the amount"<<endl;
    cin>>v;

    int coins = 0;

    for(int i = n-1; i >= 0; i--)
    {
        while(v >= deno[i])
        {
            v = v - deno[i];
            coins++;
        }
    }

    cout<<"The min no of coins req is "<<coins<<endl;

	return 0;
}
