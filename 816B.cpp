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
        ll n,k,b,s,i;
        cin>>n>>k>>b>>s;
       if(s<k*b || s>(k*b+n*(k-1)))
       cout<<"-1";
       else
       {
            ll arr[n];
            arr[0]=k*b;s-=k*b;
            rep(i,0,n)
            arr[i]=0;
            arr[0]=k*b;
            if(s>0)
            {
                arr[0]+=min(s,k-1);
                s-=min(s,k-1);
            }
            for(ll i=1;i<n;i++)
            {
                if(s>0)
                {
                    arr[i]=min(s,k-1);
                    s-=min(s,k-1);
                }
                else
                arr[i]=0;
            }
            rep(i,0,n)
            cout<<arr[i]<<" ";
       }
       cout<<endl;
    }
}