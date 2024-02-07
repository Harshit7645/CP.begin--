#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
#define all(x) x.begin(),x.end()
int M=1e9+7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    //cin>>tt;
    while(tt--)
    {
        string s;
        cin>>s;
        ll f=0;
        rep(i,1,s.length()-1)
        {
            if(s[i]<'a' || s[i]>'z')
            {
                f=1;
                break;
            }
        }
        if((s[0]>='A' && s[0]<='Z') && f==0)
        PYES;
        else
        PNO;
    }
}   