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
    ll i,n;
    cin>>s;
    n=s.length();
    vector<ll>v;
    for(i=0;i<n;i+=2)
    {
        v.push_back((int)s[i]-48);
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size()-1;i++)
    {
        cout<<v[i]<<"+";
    }
    cout<<v[v.size()-1];
    cout<<endl;
}