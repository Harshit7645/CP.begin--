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
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,h;
        cin>>n>>h;
        ll arr[n];
        rep(I,0,n)
        {
            cin>>arr[I];
        }
        sort(arr,arr+n);
        ll totpow=h,c=0,ans1=0;
        ll i=0;
        while(i<n)
        {
            if(totpow>arr[i])
            {
            totpow+=arr[i]/2;
            ans1++;
            i++;
            }
            else
            {
                if(c==0 || c==1)
                totpow*=2;
                else if(c==2)
                totpow*=3;
                else
                {
                    break;
                }
                c++;
            }
        }
        ll ans2=0;
        totpow=h,c=0,i=0;
        while(i<n)
        {
            if(totpow>arr[i])
            {
            totpow+=arr[i]/2;
            ans2++;
            i++;
            }
            else
            {
                if(c==0 || c==2)
                totpow*=2;
                else if(c==1)
                totpow*=3;
                else
                {
                    break;
                }
                c++;
            }
        }
        ll ans3=0;
        totpow=h,c=0,i=0;
        while(i<n)
        {
            if(totpow>arr[i])
            {
            totpow+=arr[i]/2;
            ans3++;
            i++;
            }
            else
            {
                if(c==2 || c==1)
                totpow*=2;
                else if(c==0)
                totpow*=3;
                else
                {
                    break;
                }
                c++;
            }
        }
        cout<<max(ans1,max(ans2,ans3))<<endl;
    }
}