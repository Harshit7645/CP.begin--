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
        ll l,r,x;
        cin>>l>>r>>x;
        ll a,b;
        cin>>a>>b;
        if(a==b)
        {
            cout<<"0\n";
            continue;
        }
        else if(abs(a-b)>=x)
        {
            cout<<"1\n";
            continue;
        }
        else if((abs(a-l)>=x && abs(b-l)>=x)||(abs(b-r)>=x && abs(a-r)>=x))
        {
            cout<<"2\n";
            continue;
        }
        else if((abs(a-l)>=x && abs(l-r)>=x && abs(r-b)>=x) || (abs(a-r)>=x && abs(r-l)>=x && abs(l-b)>=x))
        cout<<"3\n";
        else
        cout<<"-1\n";
    }
}