#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,res=0;
        cin>>a>>b;
        if(a>=b && a%b==0)
        res=a/b;
        else if(b>=a && b%a==0) 
        res=b/a;
        if(res==1 || res==2 || res==4 || res==8 || res==16 || res==32)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}