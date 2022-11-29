#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
int main() 
{
    ll n,i,ans=0,temp;
    cin>>n;
    ll arr[]={100,20,10,5,1};
    rep(i,0,5)
    {
        if(n<=0)
        break;
        temp=n/arr[i];
        n-=temp*arr[i];
        ans+=temp;
    }
    cout<<ans<<" ";
}