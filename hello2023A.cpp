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
        ll rs=0;
        rep(i,0,n)
        {
            rs+=(s[i]=='R');
        }

        if(rs==0||rs==n||(s=="LL" ||s=="RR"))
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
            ll ans=-1,f=0;
            rep(i,0,n-1)
            {
                if(s[i]=='L' && s[i+1]=='R')
                {
                    ans=i+1;
                    break;
                }
                else if(s[i]=='R' && s[i+1]=='L')
                {
                    ans=0;
                    break;
                }
            }
            cout<<ans<<endl;
        }
    }
}