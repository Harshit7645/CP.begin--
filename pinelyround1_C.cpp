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
        ll n;
        cin>>n;
        string s;
        vector<string>v;
        vector<ll>req;
        vector<vector<ll>>ans(n);
        rep(i,0,n)
        {
            cin>>s;
            v.push_back(s);
        }
        rep(i,0,n)
        {
            ll temp=0;
            rep(j,0,n)
            {
                if(v[i][j]=='0')
                temp++;
            }
            req.push_back(temp);
        }
        rep(i,0,n)
        ans[i].push_back(i+1);
        
        rep(i,0,n)
        {
            rep(j,0,n)
            {
                if(v[i][j]=='1')
                ans[j].push_back(i+1);
            }
        }
        rep(i,0,n)
        {
            cout<<ans[i].size()<<" ";
            for(auto x:ans[i])
            cout<<x<<" ";
            cout<<endl;
        }
    }
}