#include<bits/stdc++.h>
using namespace std;
vector<int>prime(1000001,0);
#define ll long long 
void sieve()
{   
  prime[1] = 1;
  for(int i = 2;i<=1000000;i++)
  {
    prime[i] = i;
  }
  for(int i = 2;i<=1000000;i++)
  {
    if(prime[i] == i && (long long)i*i <= 1000000)
    {
      for(int j = i*i;  (long long)j <= 1000000 ; j+=i)
      {
        prime[j] = i;
      }
    }
  }
}
int query(int n)
{
  set<int>ans;
  while(n != 1)
  {
    ans.insert(prime[n]);
    n/=prime[n];
  }
  return ans.size();
}
int main()
{
  sieve();
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<vector<int>>G(n,vector<int>(n,0));
    for(int i = 0;i<n;i++)
    {
      for(int j = 0;j<n;j++)
      {
        cin>>G[i][j];
      }
    }
    vector<vector<int>>distinctprime(n,vector<int>(n));
    for(int i = 0;i<n;i++)
    {
      for(int j = 0;j<n;j++)
      {
        distinctprime[i][j] = query(G[i][j]);
      }
    }
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>pq;
    vector<vector<ll>>dist(n,vector<ll>(n,LONG_MAX));
    dist[0][0] = 0LL;
    pq.push({0LL,{0,0}});
   // cout<<dist[n-1][n-1];
    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int x = it.second.first;
        int y = it.second.second;
        ll val = distinctprime[x][y];   
        for(int k = -val+x;k<=x+val;k++)
        {
          for(int j = -val+y;j<=y+val;j++)
          {
            if(k<0 || j<0 || k>=n || j>=n) continue;
            if(k == x && j==y) continue;
            if( abs(x-k) + abs(y-j) <= val)
            {
               if(dist[k][j] > dist[x][y] + sqrt(G[x][y])*1LL)
               {
                dist[k][j] =  dist[x][y] + sqrt(G[x][y])*1LL;           
                pq.push({dist[k][j],{k,j}});
               }
            }
          }
        }
    } 
      
    cout<<dist[n-1][n-1]<<"\n";
}
return 0;
}