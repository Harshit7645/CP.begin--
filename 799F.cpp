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
        ll n;
        cin>>n;
        ll arr[n];
        map<ll,ll>m;
        vector<ll>ans;
        rep(i,0,n)
        {
            cin>>arr[i];
            m[arr[i]%10]++;
            if(m[arr[i]%10]>3)
            continue;
            else
            ans.push_back(arr[i]%10);
        }
        if(m[1]==3)
        {
            PYES;
            continue;
        }
        ll f=0;
        rep(i,0,ans.size())
        {
            rep(j,i+1,ans.size())
            {
                rep(k,j+1,ans.size())
                {
                    if((ans[i]+ans[j]+ans[k])%10==3)
                    {
                        PYES;
                        f=1;
                        break;
                    }
                }
                if(f==1)
                break;
            }
            if(f==1)
            break;
        }
        if(f==0)
        PNO;
        // for(auto x:ans)
        // cout<<x<<" ";
        // cout<<"\n";
    }
}