#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,p;
    cin>>n>>p;
    ll arr[n],stot=0;
    rep(i,0,n)
    {
        cin>>arr[i];
        stot+=arr[i];
    }
    ll s1=0,score=0,max=0;
    rep(i,0,n-1)
    {
        s1+=arr[i];
        score=(s1%p)+(stot-s1)%p;
        if(max<score)
        max=score;
    }
    cout<<max<<endl;
}