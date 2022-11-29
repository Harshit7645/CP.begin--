#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll ans=n;
    while(k--)
    {
        if(n%10!=0)
        n-=1;
        else
        n/=10;
    }
    cout<<n<<"\n";
}