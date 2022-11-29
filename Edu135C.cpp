#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
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
        map<ll,ll>m1,m2;
        rep(i,0,n)
        {
            cin>>a[i];
            m1[a[i]]++;
        }
        rep(i,0,n)
        {
            cin>>b[i];
            m2[b[i]]++;
        }
        ll ans1=0,ans2=0;
        rep(i,0,n)
        {
            if(m2[a[i]]>0)
            m2[a[i]]--;
            else if(m2[length(a[i])]>0)
            ans1++;
            else
            ans1+=2;
        }
        rep(i,0,n)
        {
            if(m1[b[i]]>0)
            m1[b[i]]--;
            else if(m1[length(b[i])]>0)
            ans2++;
            else
            ans2+=2;
        }
        cout<<min(ans1,ans2)<<endl;
    }
}