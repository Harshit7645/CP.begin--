#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define all(x) x.begin(),x.end()
int M=1e9+7;

ll lcm(ll a,ll b)
{
    return (a / __gcd(a,b)) * b;
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
        ll arr[n],maxm=0;
        set<ll>s;
        rep(i,0,n)
        {
            cin>>arr[i];
            maxm=max(maxm,arr[i]);
            s.insert(arr[i]);
        }
        ll x=1,f=0;
        rep(i,0,n)
        {
            x=lcm(x,arr[i]);
            if(x>maxm)
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            cout<<n<<endl;
            continue;
        }
        map<ll,ll>dp,tempdp;
        dp[1]=0;
        rep(i,0,n)
        {
            tempdp=dp;
            for(auto x:dp)
            {
                ll val=lcm(x.first, arr[i]);
                tempdp[val]=max(tempdp[val],x.second+1);
            }
            dp=tempdp;
        }
        ll ans=0;
        for(auto x:dp)
        {
            if(s.find(x.first)==s.end())
            ans=max(ans,x.second);
        }
        cout<<ans<<endl;
    }   
}   