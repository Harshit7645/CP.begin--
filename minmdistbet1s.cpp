#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
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
        cin>>s;
        vector<ll>v;
        rep(i,0,n)
        {
            if(s[i]=='1')
            v.push_back(i);
        }
        ll mn=10e9;
        rep(i,0,v.size()-1)
        {
            mn=min(mn,v[i+1]-v[i]);
        }
        mn=2;
        rep(i,0,v.size()-1)
        {
            if((v[i+1]-v[i])%2==0)
            continue;
            else
            {
                mn=1;
                break;
            }
        }
        cout<<mn<<endl;
        //cout<<"\n";
    }
}