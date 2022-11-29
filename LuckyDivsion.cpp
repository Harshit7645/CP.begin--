#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll nod(ll n)
{
    ll ans=0;
    while(n!=0)
    {
        ans++;
        n/=10;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n,i;
    cin>>n;
    ll arr[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
    ll f=0;
    rep(i,0,14)
    {
        if(n%arr[i]==0)
        {
            f=1;
            PYES;
            break;
        }        
    }
    if(f==0)
    PNO;
}