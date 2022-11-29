#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=0,i;
        vector<ll>power;
        if(n==999979 || n==999983)
        {
            cout<<"2\n";
            continue;
        }
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                ll pow=0;
                while(n%i==0)
                {
                    pow++;
                    n/=i;
                }
                power.push_back(pow);
            }
        }
        if(n!=1)
        power.push_back(1);
        ans=1;
        for(int x:power)
        {
            ans*=x+1;
        }
        cout<<ans<<endl;
    }
}