#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define M 998244353;
ll bigpower(ll x,ll y)
{
    x%=M;
    ll req=0,res=1;
    while(y)
    {
        if(y%2==1)
        {
            req=res*x;
            res=req%M;
        }
        y/=2;
        x=x*x%M;
    }
    return res;
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
        string s;
        cin>>s;
        ll zeros=0,ones=0,ans=1,locate=0,tell=0;
        ans++;
        rep(i,0,n)
        {
            if(i==0)
            {
                zeros+=(s[i]=='0');
                ones+=(s[i]=='1');
                continue;
            }
            zeros+=(s[i]=='0');
            ones+=(s[i]=='1');
            locate++;
            if(s[i-1]!=s[i] && s[i]=='1')
            {       
                tell=zeros-ones;
                if(tell>=0)
                {
                    ones+=tell+1;
                    locate-=tell+1;
                }
            }
            else if(s[i]!=s[i-1])
            {
                tell=ones-zeros;
                if(tell>=0)
                {
                    zeros+=(tell+1);
                    locate-=(tell+1);
                }
            }
            ans+=bigpower(2,locate);
            ans=ans%M;
        }
        cout<<ans-1<<endl;
    }
}