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
        ll arr[n],mx=0;
        map<ll,ll>m;
        rep(i,0,n){
        cin>>arr[i];
        m[arr[i]]=1;
        mx=max(mx,arr[i]);
        ll y=arr[i];
        while(y>1)
        {
            m[y]=1;
            y/=2;
        }
        }
        ll q;
        cin>>q;
        sort(arr,arr+n);
        rep(i,0,q)
        {
            ll x;
            cin>>x;
            if(x>=mx)
            {
                cout<<mx<<"\n";
                continue;
            }
            else
            {
                ll maxi=0;
                repr(j,x-1,1)
                {
                    if(m[j])
                    {
                        maxi=j;
                        break;
                    }                 
                }
                cout<<maxi<<endl;
            }
        }

    }
}