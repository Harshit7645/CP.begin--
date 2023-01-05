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
        ll n,x;
        cin>>n>>x;
        //ll p=n%x;
        if((n%x)!=0)
        {
            cout<<"-1\n";
            continue;
        }
        vector<ll>req(n);
        rep(i,0,n)
        {
            req[i]=i+1;
        }
        req[0]=x;
        req[n-1]=1;
        rep(i,2*x,n+1)
        {
            if(n%i==0)
            {
                req[x-1]=i;
                x=i;
            }
            i+=(x-1);
        }
        rep(i,0,n)
        {
            cout<<req[i]<<" ";
        }
        cout<<endl;
    }
}