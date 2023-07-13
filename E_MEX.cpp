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

ll mex(ll x, ll y,ll z) {
    rep(i,0,3)
    {
        if (x != i and y != i and z != i) 
        return i;
    }
    return 3;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin>>n;
    ll arr[n];
    rep(i,0,n)
    cin>>arr[i];
    string s;
    cin>>s;
    ll ans=0;
    vector<vector<ll>>prem(n+1,vector<ll>(3,0));
    vector<vector<ll>>postx(n+1,vector<ll>(3,0));
    rep(i,0,n)
    {
        prem[i+1]=prem[i];
        if(s[i]=='M')
        prem[i+1][arr[i]]++;
    }
    // rep(i,0,n+1)
    // {
    //     cout<<prem[i][0]<<" "<<prem[i][1]<<" "<<prem[i][2]<<"\n";
    // }
    repr(i,n-1,0)
    {
        postx[i]=postx[i+1];
        if(s[i]=='X')
        postx[i][arr[i]]++;
    }
    rep(i,0,n)
    {
        if(s[i]=='E')
        {
            rep(j,0,3)
            {
                rep(k,0,3)
                {
                    ans+=prem[i][j]*postx[i+1][k]*mex(j,k,arr[i]);
                }
            }
        }
    }
    cout<<ans<<"\n";
}   
