#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin>>s;
    ll n=s.length();ll ans=0;
    rep(i,0,n)
    {
        if(s[i]=='4' || s[i]=='7')
        ans++;
    }
    ll f=0;
    if(ans==0){
    PNO;
    return 0;
    }
    while(ans>0)
    {
        if(ans%10==4 || ans%10==7)
        ans/=10;
        else{
        f=1;break;
        }
    }
    if(f==1)
    PNO;
    else
    PYES;
}