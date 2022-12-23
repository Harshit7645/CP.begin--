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
      ll n;
        cin>>n;
        string s;
        cin>>s;
        ll zero=0,one=0;
        rep(i,0,n)
        {
            zero+=(s[i]=='0');
            one+=(s[i]=='1');
        }
        rep(i,pow(2,one),pow(2,n)-(pow(2,zero)-1)+1)
        {
            cout<<i<<" ";
        }
}