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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,f=0;
        cin>>n;
        string s;
        cin>>s;
        if(n==1)
        f=1;
        else
        {
            vector<ll>v;
            rep(i,1,n-1)
            {
                if(s[i]=='W')
                v.push_back(i);
            }
            //ll f=0;
            rep(i,0,v.size()-1)
            {
                if(v[i+1]-v[i]%2==1)
                {
                    f=1;
                    //PNO;
                    break;
                }                
            }
        }
        if(f==0)
        PYES;
        else
        PNO;
    }
}