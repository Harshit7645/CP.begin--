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
        ll k,n;
        cin>>k>>n;
        ll c=1,d=1;
        ll arr[k];
        map<ll,ll>m;
        rep(i,0,k)
        {
            if(c<=n)
            {
                m[c]++;
                c+=d;
                d++;
            }
            else
            break;
        }
        repr(i,n,1)
        {
            if(m.size()==k)
            break;
            if(m[i])
            continue;
            else
            m[i]++;
        }
        for(auto x:m)
        cout<<x.first<<" ";
        cout<<endl;
    }
}