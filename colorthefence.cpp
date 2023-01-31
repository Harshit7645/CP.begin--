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
    rep(i,1,n+1)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/((fact(r))*(fact(n-r))));
}
ll power(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        result*=a;
        a*=a;
        b/=2;
    }
    return result;
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
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //ll t;
    //cin>>t;
    //while(t--)
    {
        ll n;;
        cin>>n;
        vector<ll>color(10);
        map<ll,ll>m;
        rep(i,1,9+1)
        {
            cin>>color[i];
            m[i]=color[i];
        }
        ll f=0;
        rep(i,1,10)
        {
            if(color[i]<=n)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<-1<<endl;
        }
        else
        {
            ll req;
            ll mn=10e9;
            req=0;
            rep(i,1,9+1)
            {
                mn=min(mn,color[i]);
                if(mn==color[i])
                req=i;
            }
            string s="";
           // rep(i,0,n/color[req])
            //s+=(char)(req+48);
            ll nums=(n/mn);
            ll rem=n-(nums)*mn;
            rep(i,0,nums)
            {
                repr(j,9,1){
                if(rem-color[j]+mn>=0){
                    rem-=color[j]-mn;
                    cout<<char(j+'0');
                    break;
                }
                }
            }
            //cout<<s;
        }
    }
}