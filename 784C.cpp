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
        ll arr[n];
        rep(i,0,n)
        cin>>arr[i];
        ll m1,m2,f=0;
        if(n<=2)
        f=0;
        else
        {
            rep(i,0,n)
            arr[i]%=2;
            m1=arr[0];
            m2=arr[1];
            f=0;
            rep(i,0,n)
            {
                f=0;
                if((i%2==0 && arr[i]%2==m1) || (i%2==1) && arr[i]%2==m2)
                {
                    f=0;
                }
                else
                {
                    f=1;
                }
                if(f==1)
                break;
            }
        }
        if(f==0)
        PYES;
        else
        PNO;
    }
}