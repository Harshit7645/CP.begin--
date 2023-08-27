#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        string s;
        cin>>s;
        ll n=s.length();
        ll cnt0=0;
        rep(i,0,n)
        {
            cnt0+=(s[i]=='0');
        }
        if(cnt0==0)
        {
            cout<<n*n<<"\n";
            continue;
        }
        else if(cnt0==n)
        {
            cout<<"0\n";
            continue;
        }
        ll cnt=0,maxm=0;
        ll first=-1,last=0;
        rep(i,0,n)
        {
            if(s[i]=='0')
            {
                first=i;
                break;
            }
        }
        repr(i,n-1,0)
        {
            if(s[i]=='0')
            {
                last=i;
                break;
            }
        }
        rep(i,0,n)
        {
            if(s[i]=='0')
            continue;
            ll cnt=1;
            while(s[i]=='1')
            {
                cnt++;
                i++;
            }
            maxm=max(maxm,cnt);
        }
        maxm=max(maxm,first+n-last);
        ll ans=0;
        rep(i,0,maxm/2+1)
        {
            ans=max(ans,(maxm-i)*i);
        }
        cout<<ans<<"\n";
    }
}   