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
        ll n,m;
        cin>>n>>m;
        ll arr[n][m];
        ll mx=0,maxi=0;
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                cin>>arr[i][j];   
                if(arr[i][j]>mx)
                {
                    mx=arr[i][j];
                    if(maxi<max(i,j))
                    maxi=max(i,j);
                }              
            }
        }
        cout<<(maxi+1)*(maxi+1)<<"\n";
    }
}