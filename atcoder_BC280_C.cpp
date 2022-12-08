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
    string s1,s2;
    cin>>s1>>s2;
    ll n=s1.length();
    //map<ll,ll>m1,m2;
    ll temp=0,f=0;
    rep(i,0,n)
    {
        if(s1[i]!=s2[i])
        {
            temp=i;
            f=1;
            break;
        }
    }
    if(f)
    {
        cout<<temp+1<<endl;
    }
    else
    cout<<n+1<<endl;
}