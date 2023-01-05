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
        ll n;
        cin>>n;
        vector<ll>arr(n);
        //map<ll,ll>m;
        ll f=1;
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        rep(i,0,n)
        {
            rep(j,i+1,n)
            {
                if(arr[i]==arr[j])
                {
                    f=0;
                    break;
                }
            }
        }
        // if(odd>=2 && even>=2)
        // {
        //     f=-1;
        //     //break;
        // }
        rep(i,2,n+1)
        {
            vector<ll> cnt(i);
            rep(j,0,n)
            {
                cnt[arr[j]%i]+=1;
            }
            //cout<<*min_element(cnt.begin(),cnt.end())<<" ";
            // for(auto x:cnt)
            // cout<<x<<" ";
            // cout<<endl;
            if(*min_element(cnt.begin(),cnt.end())>=2)
            {
                f=0;
                break;
            }
        }
        if(f==1)
        PYES;
        else
        PNO;
        //cout<<f<<" ";
    }
}