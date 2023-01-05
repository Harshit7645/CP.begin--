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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q,x,k;
        cin>>n>>q;
        vector<ll> v(n);
        //map<ll,ll>m;
        ll mx=0,maxind=0;
        rep(i,0,n)
        {
            cin>>v[i];
            mx=max(mx,v[i]);
            if(v[i]==mx)
            {
                maxind=i+1;
            }
        }
        ll maxfight=0;
        vector<ll>winners(n);
        ll winby=0,power=0;
        if(v[0]>v[1])
        {
            winby=1;
            power=v[0];
            winners[0]=1;
        }
        else
        {
            winby=2;
            power=v[1];
            winners[0]=2;
        }
        rep(i,2,n)
        {
            if(i==n-1)
            {
                winners[n-1]=maxind;
            }
            if(v[i]>power)
            {
                winby=i+1;
                power=v[i];
            }
            winners[i-1]=winby;
        }
        if(n==2)
        {
            winners[1]=maxind;
        }
        map<ll,ll>m;
        ll c=1;
        for(auto x:winners)
        {
            m[c++]=x;
        }
        rep(i,0,q)
        {
            ll player,k;
            cin>>player>>k;
                ll ans=0;
                rep(j,0,min(k,n))
                {
                    if(winners[j]==player)
                    {
                    ans++;
                    //cout<<ans<<"! "<<player;
                    }
                }
                //cout<<endl;
            if(k<=n)
            cout<<ans<<endl;
            else if(k>n && v[player-1]!=mx)
            cout<<ans<<endl;
            else 
            cout<<ans+(k-n)<<endl;
        }
        //  for(auto x:winners)
        //  cout<<x<<" ";
    }
}