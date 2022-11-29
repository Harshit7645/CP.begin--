#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll m,i,j,time,ans;
        cin>>m;
        ll arr[2][m];
        rep(i,0,2)
        {
            rep(j,0,m)
            {
                cin>>arr[i][j];
            }
        }
        i=0,j=0,time=0,ans=0;
        while(1)
        {
            if(i==0)
            {
                if(arr[i][j+1]>arr[i+1][j])
                ans+=arr[i+1][j]+1;
                time++;
            }
            else if(i==1)
            {
                if(arr[0][j]==0)
                ans+=arr[0][j]-time+1;
            }
        }
    }
}