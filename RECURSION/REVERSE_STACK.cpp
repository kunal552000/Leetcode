/*

reverse a stack

*/


//CODE




#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>& s, int ele)
{
    if(s.empty())
    {
        s.push(ele);
        return;
    }

    int temp = s.top();
    s.pop();

    insert(s,ele);
    s.push(temp);

    return;
}


void reverse(stack<int>& s)
{
    if(s.size() == 1)
        return;
    int temp = s.top();
    s.pop();

    reverse(s);
    insert(s,temp);

    return;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);



    reverse(s);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;



}
