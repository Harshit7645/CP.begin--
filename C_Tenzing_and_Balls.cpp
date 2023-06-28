#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

int recur(int st,int end,vector<ll>&v)
{
    return max(v[st],v[end]);
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
        vector<ll>v(n);
        vector<pair<ll,ll>>interval;
        map<ll,ll>last;
        rep(i,0,n)
        {
            cin>>v[i];
            last[v[i]]=i;
        }
        map<ll,ll>first;
        rep(i,0,n)
        {
            if(first.find(v[i])==first.end())
            first[v[i]]=i;
        }
        ll ans=0;
        for(auto x:last)
        {
            if(x.second==first[x.first])
            continue;
            interval.push_back({first[x.first],x.second});
            ans=max(ans,x.second-first[x.first]+1);
        }
        ll length=recur(0,n-1,v);
        ll dont=0;
        vector<ll>dp(n+1,0);
        vector<priority_queue<pair<ll,ll>>>pq(n+1);
        rep(i,0,n)
        v[i]-=1;
        rep(i,0,n)
        {
            dont++;
            if(!pq[v[i]].empty())
            dp[i+1]=max(dp[i],dp[pq[v[i]].top().second]+1+i-pq[v[i]].top().second);
            else
            dp[i+1]=dp[i];
            pq[v[i]].push({dp[i]-i,i});
            if(dont>=n)
            break;
        }
        rep(i,0,n)
        {
            while(!pq[i].empty())
            {
                cout<<pq[i].top().first<<" "<<pq[i].top().second<<"\n";
                pq[i].pop();
            }
            cout<<endl;
        }
        cout<<max(ans,dp[n])<<endl;
    }
}   