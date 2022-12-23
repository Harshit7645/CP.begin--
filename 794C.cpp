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
        ll arr[n];
        map<ll,vector<ll>>m;
        rep(i,0,n)
        {
            cin>>arr[i];
            m[arr[i]].push_back(i+1);
        }
        if(n%2==1)
        {
            PNO;
            continue;
        }
        ll f=0;
        for(auto x:m)
        {
            if(x.second.size()>n/2)
            {
                f=1;
                break;
            }
        }
        if(f)
        PNO;
        else
        {
            //PYES;
            sort(arr,arr+n);
            ll a[n],c=0,k=n/2;
            rep(i,0,n)
            {
                if(i%2==0)
                a[i]=arr[c++];
                else
                a[i]=arr[k++];
                //cout<<a[i]<<" ";
            }
            ll flag=0;
            rep(i,1,n-1)
            {
                if(i%2==0)
                {
                    if(a[i]>=a[i+1] || a[i]>=a[i-1])
                    {
                        flag=1;
                        break;
                    }
                }
                else
                {
                    if(a[i]<=a[i+1] || a[i]<=a[i-1])
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(a[0]>=a[n-1])
            flag=1;
            if(flag)
            {
                PNO;
                continue;
            }
            else
            {
                PYES;
                rep(i,0,n)
                {
                    cout<<a[i]<<" ";
                }
            }
            cout<<endl;
        }
    }
}