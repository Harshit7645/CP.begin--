#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
char arr[501][501];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k,r,c;
        cin>>n>>k>>r>>c;
        rep(i,1,n+1)
        {
            rep(j,1,n+1)
            {
                arr[i][j]='.';
            }
        }
        rep(m,2,n*2+1)
        {
            if(abs(r+c-m)%k==0)
            {
                rep(i,1,n+1)
                {
                    rep(j,1,n+1)
                    {
                        if(i+j==m)
                        arr[i][j]='X';
                    }
                }
            }
        }
        rep(i,1,n+1)
        {
            rep(j,1,n+1)
            {
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }
}