#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
int main() 
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        ll arr[n];
        map<ll,ll>m;
        rep(i,0,n)
        {
            cin>>arr[i];
            if(m[arr[i]]>=0)
            {
                m[arr[i]]++;
            }
        }
        for(i=0;i<n;i++)
        {
            if(m[arr[i]]==1)
            m.erase(arr[i]);
        }
        for(i=0;i<n;i++)
        {
            if(m.size()!=0)
            {
                if(m[arr[i]]>=2)
                m[arr[i]]--;
                if(m[arr[i]]<2)
                m.erase(arr[i]);
            }
            else
            break;
        }
        for (auto x:m)
        cout<<x.first<<" ";
        cout<<i<<endl;
    }

}