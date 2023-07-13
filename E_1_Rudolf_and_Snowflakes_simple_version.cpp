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

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        map<ll,ll>m;
        ll k=2,sum=1+k;
        ll i=k;
        while(k<1000)
        {
            i=k;
            sum=1+k;
            while(i<=1e6)
            {
                i*=k;
                sum+=i;
                m[sum]=1;
            }
            k++;
        }
        if(m[n])
        PYES;
        else
        PNO;
    }
}   