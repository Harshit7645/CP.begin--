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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll value=0;
        string zero="";
        rep(i,0,n)
        {
            zero+="0";
        }
        if(zero==s)
        {
            cout<<0<<"\n";
            continue;
        }
        rep(i,0,n)
        {
            value+=(s[i]=='1');
        }
        ll l=0,r=n-1;
        while(s[l]=='0')
        l++;
        while(s[r]=='0')
        r--;
        value*=11;
        if(value==11){
            if(k>=(n-1-r))
            {
                k-=(n-1-r);
                value-=10;
            }
            else if(k>=(l))
            {
                value-=1;
            }
        }
        else
        {
            if(k>=(n-1-r))
            {
                k-=(n-1-r);
                value-=10;
            }
            if(k>=(l))
            {
                value-=1;
            }
        }
        cout<<value<<endl;
    }
}