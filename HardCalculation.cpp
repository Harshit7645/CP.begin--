#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,ld1,ld2,flag=0;
    cin>>a>>b;
    while(a!=0 && b!=0)
    {
        ld1=a%10;
        ld2=b%10;
        if(ld1+ld2>9)
        {
            flag=1;
            break;
        }
        a/=10;
        b/=10;
    }
    if(flag==0)
    cout<<"Easy\n";
    else
    cout<<"Hard\n";
}