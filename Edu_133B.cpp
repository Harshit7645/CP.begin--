#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n],f=n;
        rep(i,0,n)
        {
            arr[i]=i+1;
        }
        f=n;
        cout<<f<<"\n";
        rep(i,0,n)
        cout<<arr[i]<<" ";
        cout<<endl;
        rep(i,0,n-1)
        {
            swap(arr[i],arr[i+1]);                
            rep(j,0,n)
            {
                cout<<arr[j]<<" ";
            }
            cout<<endl;
        }
    }
}