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
        cin>>s;
        map<char,ll>m;
        rep(i,0,n)
        {
            m[s[i]]++;
        }
        if(m['T']==1 && m['i']==1 && m['m']==1 && m['u']==1 && m['r']==1 &&m.size()==5)
        PYES;
        else
        PNO;
    }
}