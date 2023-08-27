#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

bool solve(int n)
{
    map<string,int>m;
    while(n!=1)
    {
        string s=to_string(n);
        if(m[s])
        return 0;
        m[s]++;
        ll val=0;
        rep(i,0,s.length())
        {
            val+=(s[i]-48)*(s[i]-48);
        }
        n=val;
    }
    return 1;
}

int main()
{
    cout<<solve(2000001);
}   