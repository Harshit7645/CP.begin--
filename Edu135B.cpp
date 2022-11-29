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
        if(n%2==0)
        {
            for(ll i=n-2;i>=1;i--)
            {
                cout<<i<<" ";
            }
            cout<<n-1<<" "<<n<<endl;
        }
        else
        {
            for(ll i=n-3;i>=2;i--)
            {
                cout<<i<<" ";
            }
            cout<<n-2<<" "<<1<<" "<<n-1<<" "<<n<<endl;
        }
    }
}