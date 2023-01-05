#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/((fact (r))*(fact(n-r))));
}
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
            ll db=4*n*n;
            //vector<ll>req(n);
            ll num=db/n;
            rep(i,num-n+1,num+n)
            {
                if(i!=num-n+1 && i!=num+n-1)
                cout<<i<<" ";
                else if(i==num-n+1)
                cout<<i-1<<" ";
                else
                cout<<i+1<<" ";
                i++;
            }
            cout<<endl;
        }
        else
        {
            ll db=4*n*n;
            ll num=db/n;
            rep(i,num-n,num+n+1)
            {
                cout<<i<<" ";
                if(i==num-n || i==num+n-3)
                i+=2;
                else
                i++;
            }
            cout<<endl;
        }
    }
}