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
        cout<<"Division ";
        if(n<=1399)
        cout<<"4\n";
        else if(n>=1400 && n<=1599)
        cout<<"3\n";
        else if(n>=1600 && n<1900)
        cout<<"2\n";
        else
        cout<<"1\n";
    }
}