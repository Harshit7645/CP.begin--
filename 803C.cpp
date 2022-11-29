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
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        cin>>arr[i];
        map<int,int>m;
        ll pos=0,neg=0;
        vector<ll>v;
        rep(i,0,n)
        {
            if(arr[i]>0)
            {
                pos++;
            }
            else if(arr[i]<0)
            {
                neg++;
                //v.push_back(arr[i]);
            }
            m[arr[i]]++;
        }
        ll f=0;
        if(pos>2 || neg>2)
        {
            PNO;
            continue;
        }
        ll te=0;
        for(auto x:m)
        {
            te=min(x.second,3);
            rep(j,0,te)
            {
                v.push_back(x.first);
            }
        }
        rep(i,0,v.size())
        {
            f=0;
            rep(j,i+1,v.size())
            {
                rep(k,j+1,v.size())
                {
                    if(m[v[i]+v[j]+v[k]]==0)
                    {
                        //cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<"\n";
                        f=1;
                        break;
                    }
                }
                if(f==1)
                break;
            }
            if(f==1)
            break;
        }
        if(f==1)
        PNO;
        else
        PYES;
        // for(auto x:m)
        // cout<<x.first<<" ";
        // cout<<endl;
    }
}