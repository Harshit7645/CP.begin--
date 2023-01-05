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
bool isPrime(ll n)
{
    if(n<=1)
    return false;
    if(n<=3)
    return true;

    if(n%2==0 || n%3==0 || n%5==0)
    return false;
    for(ll i=6;i<=sqrt(n);i+=5)
    {
        //for (ll i=5;i*i<=n;i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;//return true;
    }
    return true;
}
ll arr[200005];
string t,s;
bool good(ll x)
{
    map<ll,ll>m;
    rep(i,0,x)
    {
        m[arr[i]-1]++;
    }
    ll j=0ll;
    rep(i,0,t.length())
    {
        if(!m[i])
        {
            if(t[i]==s[j])
            j++;
        }
    }
    return j==s.length();
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //string t,s;
    cin>>t>>s;
    ll n=t.length();
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    ll l=0,r=n;
    while(l+1<r)
    {
        ll m=l+r>>1;
        if(good(m))
        l=m;
        else
        r=m;
    }
    cout<<l<<endl;
}