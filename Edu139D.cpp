#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        ll n;
        cin>>n;
        rep(i,0,n)
        {
            ll x,y;
            cin>>x>>y;
            if(y==x+1 || x==y+1)
            cout<<"-1\n";
            else
            {
                ll i=x,j=y,ans=0;
                while(1)
                {
                    if(gcd(i,j)==1)
                    ans++;
                    else
                    break;
                    i++;
                    j++;
                }
                cout<<ans<<endl;
            }
        }
}