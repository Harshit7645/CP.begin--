#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
int main()
{
    ll t;
    cin>>t;
    rep(i,0,t)
    {
        ll n;
        cin>>n;
        ll ans=0,rem;
        rem=n%6;
        if(rem==4 ||rem==5)
        ans+=2;
        else if(rem==2 || rem==3 || rem==1)
        ans+=1;
        if(n>=6)
        ans+=(n-rem)/3;
        if(n==1)
        cout<<"2\n";
        else
        cout<<ans<<endl;
    }

}