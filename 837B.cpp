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
        ll n,m,t1=0,t2=0;
        cin>>n>>m;
        vector<set<ll>>vec(n+1);
        rep(i,0,m)
        {
            // t1,t2;
            cin>>t1;
            cin>>t2;
            if(t1>t2)
            vec[t2].insert(t1);
        }
        ll tempomin=10e5,ans=n;
        vector<ll>vis(n+1,-10e5);
        repr(i,n,0)
        {
            tempomin=10e5;
            if(vec[i].size()>=1)
            {
                for(auto x:vec[i])
                {
                    t1=x;
                    break;
                }
                tempomin=min(tempomin,t1);
            }
            vis[i]=tempomin;
        }
        ans=ans*(n+1)/2;
        rep(i,1,n+1)
        {
            if(vis[i]==-10e5)
            continue;
            t2=vis[i];
            ans=ans-(n-t2+1);
        }
        cout<<ans<<endl;
    }    
}