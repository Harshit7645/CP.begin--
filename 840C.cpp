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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n],sums=0,maxi=0;
        rep(i,0,n)
        {
            cin>>arr[i];
            sums+=arr[i];
            maxi=max(maxi,arr[i]);
        }
            //mx=0;
            if(n>3 || n==1)
            {
                cout<<maxi*n<<endl;
                continue;
            }
            else if(n==3)
            {
                maxi=sums;
                maxi=max(maxi,3*arr[0]);
                maxi=max(maxi,3*arr[2]);
                maxi=max(maxi,3*abs(arr[0]-arr[1]));
                maxi=max(maxi,3*abs(arr[1]-arr[2]));
                cout<<maxi<<endl;
                continue;
            }
            else
            {
                maxi=sums;
                maxi=max(maxi,2*abs(arr[0]-arr[1]));
                cout<<maxi<<endl;
                continue;
            }
           // continue;
    }
}