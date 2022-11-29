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
        ll n,m;
        cin>>n>>m;
        if(!(n&1)&& (m&1)|| (n>m))
        PNO;
        else
        {
            PYES;
            if(m%n==0)
            {
                rep(i,0,n)
                cout<<m/n<<" ";
            }
            else if(n%2==1){
                rep(i,0,n-1)
                cout<<1<<" ";
                cout<<m-n+1;
            }
            else
            {
                rep(i,0,n-2)
                cout<<1<<" ";
                cout<<(m-n+2)/2<<" "<<(m-n+2)/2;
            }
            cout<<"\n";
        }
    }
}