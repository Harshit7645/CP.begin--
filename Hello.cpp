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
    string s;
    cin>>s;
    ll n;
    n=s.length();
    char arr[5]={'h','e','l','l','o'};
    ll j=0;
    rep(i,0,n)
    {
        if(s[i]==arr[j])
        {
            j++;
        }
    }
    if(j>4)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}