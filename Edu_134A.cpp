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
        string s1,s2;
        cin>>s1;
        cin>>s2;
        ll ans=0,n=4;
        map<ll,ll>m;
        m[s1[0]]++;m[s1[1]]++;
        m[s2[0]]++;m[s2[1]]++;
        cout<<m.size()-1<<endl;
    }
}