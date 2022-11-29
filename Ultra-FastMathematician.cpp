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
    string s1,s2;
    cin>>s1>>s2;
    ll n=s1.length();
    rep(i,0,n)
    {
        if(s1[i]!=s2[i])
        cout<<1;
        else
        cout<<0;
    }
    cout<<endl;
}