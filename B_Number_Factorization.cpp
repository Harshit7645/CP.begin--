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

bool comp(pair<int,int>p1,pair<int,int>p2)
{
    return p1.second>p2.second;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll>>v;
        rep(i,2,sqrt(n)+1)
        {
            if(n%i==0)
            {
                int c=0;
                while(n%i==0)
                {
                    n/=i;
                    c++;
                }
                v.push_back({i,c});
            }
        }
        if(n>1)
        {
            v.push_back({n,1});
        }
        //sort(v.begin(),v.end(),comp);
         sort(v.begin(),v.end(),[](pair<ll,ll>&a,pair<ll,ll>&b){
              return a.second>b.second;
             });
             ll prod=1,ans=0;
            rep(i,0,v.size())
             {
                 prod*=v[i].first;
                 if(i+1<v.size())
                 ans+=(prod*(v[i].second-v[i+1].second));
                 else{
                     ans+=(prod*(v[i].second));
                 }
                 cout<<ans<<" ";
             }
             cout<<ans<<'\n';
    }
}   
