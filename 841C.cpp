#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/((fact (r))*(fact(n-r))));
}
//below function is taken from geeksforgeeks.org
int subarrayXor(ll arr[], ll n, ll m)
{
      //declaring the hashtable
      //and initializing it with a count of 1
      //for 0
    unordered_map <int, int> HashTable;
    HashTable[0] = 1;
    int count = 0, curSum = 0;
    for (int i = 0; i < n; i++)
    {
        curSum ^= arr[i];
        if (HashTable[curSum ^ m] > 0)
            count += HashTable[curSum ^ m];
        HashTable[curSum]++;
    }
    return(count);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n+1];
        rep(i,1,n+1)
        {
            cin>>arr[i];
        }
        vector<ll>perf;
        perf.push_back(0);
        ll c=1,n1=0;
        //n1=pow(2,n1);
        n1=1;
        rep(i,1,n+1)
        {
            if(n1<n)
            n1*=2;
        }
        n1*=2;
        while(c*c<n1)
        {
            perf.push_back(c*c);
            c++;
        }
        ll ans=0,count[n1+1];
        rep(i,0,n1)
        {
            count[i]=0;
        }
        count[0]=1;
        ans=0;
        ll curr=0ll;
        rep(i,1,n+1)
        {
            curr=curr^arr[i];
            for(ll j=0;j<perf.size();j++)
            {
                ans+=count[curr^perf[j]];
            }
            count[curr]++;
        }
        cout<<1ll*n*(n+1)/2-ans<<endl;
    }
}