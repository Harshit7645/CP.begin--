#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"TIDAK\n"
#define PYES cout<<"YA\n"
typedef vector<ll> vll;
bool solve()
{
    ll n,m,k;
        cin>>n>>m>>k;
        ll arr[k];
        rep(i,0,k)
        {
            cin>>arr[i];
        }
    ll tom=k,spacesleft=n*m-2;
            vector<ll>vis(k+1,0);
            ll f=0;
            rep(i,0,k)
            {
                vis[arr[i]]=1;

                if(arr[i]==tom)
                {
                    if(spacesleft>=2)
                    {
                        tom--;
                        while(vis[tom])
                        {
                            spacesleft++;
                            tom--;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    spacesleft--;
                }
            }
        return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        bool t=solve();
        if(t)
        PYES;
        else
        PNO;
    }
}