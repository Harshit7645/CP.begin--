#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll length(ll n)
{
    ll ans=0;
    while(n>0)
    {
        ans++;
        n/=10;
    }
    return ans;
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
        ll a[n],b[n];
        priority_queue<ll> m1,m2;
        rep(i,0,n)
        {
            cin>>a[i];
            m1.push(a[i]);
        }
        rep(i,0,n)
        {
            cin>>b[i];
            m2.push(b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        if(a==b)
        {
            cout<<0<<endl;
            continue;
        }
        ll ans=0;
        repr(i,n-1,0)
        {
            ll x=0,y=0;
                x=m1.top(),y=m2.top();
                while(x!=y)
                {
                    ans++;
                    if(x>y)
                    {
                        m1.pop();
                        m1.push(length(x));
                        x=m1.top();
                    }
                    else
                    {
                        m2.pop();
                        m2.push(length(y));
                        y=m2.top();
                    }
                }
                m1.pop();
                m2.pop();
        }
        cout<<ans<<endl;
    }
}