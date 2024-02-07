#include<iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define all(x) x.begin(),x.end()
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ord_set;
int M=1e9+7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll>>v(n);
        map<ll,ll>m;
        ord_set os;
        rep(i,0,n){
            cin>>v[i].first>>v[i].second;
            m[v[i].first]=0;
            m[v[i].second]=1;
        }
        // for(auto x:m)
        // {
        //     cout<<x.first<<" "<<x.second<<"\n";
        // }
        // cout<<endl;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        rep(i,0,n)
        {
            os.insert(v[i].second);
        }
        ll ans=0,f=0;
        repr(i,n-1,0)
        {   
            auto it=os.find(v[i].second);
            ans+=os.order_of_key(v[i].second);
            os.erase(it);
        }
        cout<<ans<<"\n";
    }
} 