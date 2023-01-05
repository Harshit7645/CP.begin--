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
        ll n,m;
        cin>>n>>m;
        ll twos=0,fives=0;
        ll og=n;
        while(og%2==0)
        {
            og/=2;
            twos++;
        }
        while (og%5==0)
        {//this
            og/=5;
            fives++;
        }
        ll ans=1;
        while(1)
        {
            if(twos>fives && m>=5)
            {
                m/=5;
                fives++;
            }
            else if(fives>twos && m>=2)
            {
                m/=2;
                twos++;
            }
            else if(twos==fives && m>=10)
            {
                twos++;
                fives++;
                m/=10;
            }
            else
            break;
        }
        ans=og*m;
        rep(i,0,twos)
        ans*=2;
        rep(i,0,fives)
        ans*=5;
        cout<<ans<<endl;
        
    }
}