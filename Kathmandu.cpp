#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
int main()
{
    ll t,d,m,i,flag=0;
    cin>>t>>d>>m;
    ll arr[m+2];
    arr[0]=0;
    rep(i,1,m+1)
    {
        cin>>arr[i];
    }
    arr[m+1]=d;
    rep(i,0,m+1)
    {
        if(arr[i+1]-arr[i]>=t)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    cout<<"Y\n";
    else
    cout<<"N\n";
    return 0;
}
