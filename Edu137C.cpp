#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b;i>=a;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
typedef vector<ll> vll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll arr[n];
        rep(i,0,n)
        cin>>arr[i];
        ll ans=0;
        rep(i,0,n)
        {
            if(s[i]=='1'){
            ans+=arr[i];
            continue;
            }
            if(s[i]=='0' && s[i+1]=='1')
            {
                ll tsum=arr[i],j=i+1,mn=arr[i];
                while(j<n)
                {
                    if(s[j]=='1')
                    {
                        tsum+=arr[j];
                        mn=min(mn,arr[j]);
                        j++;
                    }
                    //j++;
                    else 
                    break;
                }
                //ans-=mn;
                tsum-=mn;
                i=j-1;
                ans+=tsum;
            }
        }
        cout<<ans<<endl;
    } 
}