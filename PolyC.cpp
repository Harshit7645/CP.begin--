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
        string s;
        cin>>s;
        cout<<1<<" ";
        ll arr[n-1];
        rep(i,0,n-1)
        {
            arr[i]=0;
        }
        arr[0]=1;
        rep(i,1,s.length())
        {
            if(s[i]!=s[i-1])
            arr[i]=i+1;
            else
            arr[i]=arr[i-1];
        }
        rep(i,1,n-1)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}