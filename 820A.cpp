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
        ll a,b,c;
        cin>>a>>b>>c;
         if((abs(b-c)+abs(c-1))>abs(a-1))
        {
            cout<<1<<endl;
        }
        else if((abs(b-c)+abs(c-1))<abs(a-1))
        {
            cout<<2<<endl;
        }
        else
            cout<<3<<endl;

    }
}