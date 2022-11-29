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
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        char s[56];
        for(int i=0;i<=55;i++)
        s[i] ='a';
        cout<<s<<endl;
        for(int i=0;i<n;i++)
        {
            s[arr[i]]=(char)((int)s[arr[i]]+1);
            if(s[arr[i]]==(char)123)
            s[arr[i]]='a';
            cout<<s<<endl; 
        }
    }
}