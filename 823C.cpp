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
        ll n,i;
        string s;
        cin>>s;
        n=s.length();
        char mind=s[n-1];
        map<char,ll>m;
        for(ll i=n-1;i>=0;i--)
        {
            if(s[i]==mind)
            {
                m[s[i]]++;
            }
            else if(s[i]>mind)
            {
                if(s[i]!='9')
                s[i]=s[i]+1;
                m[s[i]]++;
            }
            else
            {
                mind=s[i];
                m[s[i]]++;
            }
        }
        for(auto x:m)
        {
            for(i=0;i<x.second;i++)
            {
                cout<<x.first;
            }
        }
        cout<<endl;
    }
}