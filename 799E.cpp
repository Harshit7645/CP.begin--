#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
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
        ll i,n,s;
        cin>>n>>s;
        ll arr[n],c=0,ans=0;
        map<ll,ll>m;
        rep(i,0,n)
        {
            cin>>arr[i];
            if(arr[i])
            {
                c++;
                m[1]++;
            }
        }
        if(s>c || s<0)
        cout<<"-1\n";
        else if(c==s)
        {
            cout<<ans<<"\n";
            continue;
        }
        else
        {
            ll rt=0,sum=0;
            ans=-1;
            rep(i,0,n)
            {
                sum+=arr[i];
                while(sum>s)
                {
                    sum-=arr[rt];
                    rt++;
                }
                if(sum==s)
                {
                    if(i-rt+1>ans)
                    ans=i-rt+1;
                }
            }           
            cout<<n-ans<<"\n";   
        }
    }
}