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
    ll first,sec;
    ll f=0;
    for(ll i=1;i<=7;++i)
    {
        for(ll j=i+1;j<=7;++j) 
        {
            cout<<"? "<<i<<" "<<j<<"\n";
            cin>>first;
            cout<<"? "<<j<<" "<<i<<"\n";
            cin>>sec;
            if(first==-1)
            {
                cout<<"! "<< max(j,i)-1<<"\n";
                f=1;
                break;
            }
            if(first!=sec) 
            {
                cout<<"! "<<first+sec<<"\n";
                f=1;
                break;
            }
        }
        if(f==1)
        break;
    }
}