#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

vector<ll> printDivisors(int n)
{
    vector<ll>temp;
    rep(i,1,sqrt(n))
    {
        if (n%i == 0)
        {
            temp.push_back(i);
            temp.push_back(n/i);
        }
    }
    return temp;
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
        ll arr[n],lc=1;
        rep(i,0,n)
        {
            cin>>arr[i];
            lc=lcm(lc,arr[i]);
        }
        ll req=1,f=0;
        repr(i,n-1,0)
        {
            req*=arr[i];
            if(req>=lc)
            {
                f=1;
                break;
            }
        }
        if(f)
        PYES;
        else
        PNO;
    }    
}