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
        string s;
        cin>>s;
        ll n,i;
        n=s.length();
        set<double>pos;
        double res=0.5;
        pos.insert(0.5);
        pos.insert(0);
        pos.insert(1);
        auto itr=pos.begin()++;
        for(i=0;i<n;i++)
        {
            if(s[i]=='l')
            {
                auto it=lower_bound(s.begin(),s.end(),res);
                
            }
        }
    }
}