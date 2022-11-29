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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll a,b,c,i;
            if(k%4==0)
            cout<<"NO\n";
            else{
            cout<<"YES\n";
            if(k%4==1 || k%4==3){
            for(i=1;i<=n;i+=2)
            cout<<i<<" "<<i+1<<endl;
            }
            else if(k%4==2)
            {
                for(i=3;i<=n;i+=4)
                {
                    cout<<i<<" "<<i+1<<endl;
                }
                for(i=2;i<=n;i+=4)
                {
                    cout<<i<<" "<<i-1<<"\n";
                }
            }}
        
    }
}