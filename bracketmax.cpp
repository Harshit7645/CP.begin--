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


int solve(string s)
{
    int n=s.length();
    vector<int> prefix(n), suffix(n);
    prefix[0] = (s[0] != '>')?1:0;
    rep(i,1,n)
    prefix[i] = (s[i] != '>')?prefix[i - 1] + 1:prefix[i-1];

    suffix[n - 1] = (s[n - 1] != '<')?1:0;
    repr(i,n-2,0)
    suffix[i] = (s[i] != '<')?suffix[i + 1] + 1:suffix[i+1];
    rep(i,0,n)
    {
        cout<<prefix[i]<<" ";
    }
    cout<<"\n";
    rep(i,0,n)
    {
        cout<<suffix[i]<<" ";
    }
    cout<<"\n";
    int ans = 0;
    for(int i = 0; i < n; i++)
    ans = max(ans, 2 * min(prefix[i], suffix[i]));
    return ans;
}

int main()
{
    cout<<solve("<<<?>>");
}   