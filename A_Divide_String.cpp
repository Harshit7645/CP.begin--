#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
int M=1e9+7;


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n,f=0;
        cin>>n;
        string s;
        cin>>s;
        vector<ll>ind;
        rep(i,1,n)
        {
            string temp=s.substr(0,i);
            string rem=s.substr(i);
            if(temp<rem)
            {
                f=1;
                break;
            }
        }
        if(!f)
        PNO;
        else
        PYES;
    }
}   