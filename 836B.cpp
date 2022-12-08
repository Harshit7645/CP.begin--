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
        if(n%2==1)
        {
            rep(i,0,n)
            cout<<n<<" ";
            cout<<endl;
        }
        else
        {
            cout<<"1 3 ";
            rep(i,0,n-2)
            {
                cout<<2<<" ";
            }
            cout<<endl;
        }
    }
}