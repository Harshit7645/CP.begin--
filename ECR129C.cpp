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
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int>>v(n),req;
        rep(i,0,n)
        {
            cin>>v[i].first;
        }
        rep(i,0,n)
        {
            cin>>v[i].second;
        }
        //cout<<1;
        rep(i,0,n)
        {
            rep(j,i+1,n)
            {
                if((v[i].first>v[j].first)||(v[i].first==v[j].first && v[i].second>v[j].second))
                {
                    req.push_back({i,j});
                    swap(v[i],v[j]);
                }
            }
        }
        int f=0;
        rep(i,0,n-1)
        {
            if(v[i].first>v[i+1].first || v[i].second>v[i+1].second)
            {
                f=1;
                break;
            }
        }
        if(f)
        cout<<"-1\n";
        else
        {
            cout<<req.size()<<"\n";
            for(auto x:req)
            {
                cout<<x.first+1<<" "<<x.second+1<<"\n";
            }
        }
    }
}