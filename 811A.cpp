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
    for(ll x=0;x<t;x++)
    {
        ll n,H,M,i,flag=0;
        cin>>n>>H>>M;
        ll ho[n],min[n];
        vector<pair<ll,ll>>v;
        for(i=0;i<n;i++)
        {
            cin>>ho[i]>>min[i]; 
            v.push_back({ho[i],min[i]});
        }
        sort(v.begin(),v.end());
        for(i=0;i<v.size();i++)
        {
        if((v[i].first>H) ||((v[i].first==H) && (v[i].second>=M)))
        {
            flag=1;
            if(v[i].second<M)
            cout<<v[i].first-H-1<<" "<<v[i].second-M+60<<endl;
            else
            cout<<v[i].first-H<<" "<<v[i].second-M<<endl;
            break;
        }
        }
        if(flag==0){
            //auto itr=v.begin();
            if(v[0].second<M)
            cout<<v[0].first-H-1+24<<" "<<v[0].second-M+60<<endl;
            else 
            cout<<v[0].first-H+24<<" "<<v[0].second-M<<endl;
        }
    }

}
