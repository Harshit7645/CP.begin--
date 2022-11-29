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
    ll n;
    cin>>n;
    ll arr[n];
    rep(i,0,n)
    cin>>arr[i];
    ll res=1,max=1;
    rep(i,1,n)
    {
        if((arr[i]/arr[i-1]<2) || (arr[i]/arr[i-1]==2 && arr[i]%arr[i-1]==0)) 
        res++;
        else
        res=1;
        if(res>max)
        max=res;
    }
    cout<<max<<endl;
}