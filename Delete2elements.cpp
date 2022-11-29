#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        double arr[n],sum=0;
        rep(i,0,n)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        double avg,av1=0.0;
        avg=(sum)/n;
        ll ans=0,diff=n,temp=0;
        sort(arr,arr+n);
        rep(i,0,n-1)
        {
            if(arr[i]-(int)avg<diff)
            {
                diff=arr[i+1]-(int)avg;
                temp=i;
            }
        }
        rep(i,0,temp)
        {
            for(ll j=temp;j<n;j++)
            {
                av1=((arr[i]+arr[j])*1LL)/2;
                if(av1==avg)
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}