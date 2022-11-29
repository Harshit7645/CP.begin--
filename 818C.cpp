#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll a[1000001],b[1000001];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll low,high;
        ll n;
        cin>>n;
        rep(i,1,n+1)
        {
            cin>>a[i];
        }
        rep(i,1,n+1)
        {
            cin>>b[i];
        }

            ll p=0;
            low=1;
            high=1;
            p=2;
            rep(i,1,n+1)
            {
                if(p==n+1)
                p=1;
                if(a[i]>b[i]||((a[i]!=b[i])&&(b[i]-2>=b[i%n+1]))) {
                PNO;
                low=0;
                break;
                }
                p++;
            }
            if(low)
            PYES;
        
        // rep(i,0,n+1)
        // {
        //     cout<<a[i]<<" ";            
        // }
        // cout<<"\n";
        // rep(i,0,n)
        // {
        //     cout<<b[i]<<" ";            
        // }
        // cout<<endl;
        
    }
}