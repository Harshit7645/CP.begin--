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
        char arr[8][8];
        map<ll,ll>rowr,colb;
        ll f=0;
        rep(i,0,8)
        {
            ll c1=0,c2=0;
            rep(j,0,8)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='R')
                c1++;
                
            }
            rowr[i]=c1;
        }
        // for(auto x:row)
        // cout<<x.first<<" "<<x.second<<"\n";
        for(auto x:rowr)
        {
            if(x.second==8)
            {
                f=1;
                cout<<"R\n";
                break;
            }
        }
        if(f==1)
        continue;

        rep(j,0,8)
        {
            ll c1=0,c2=0;
            rep(i,0,8)
            {
                if(arr[i][j]=='B')
                c2++;
            }
            colb[j]=c2;
        }
        for(auto x:colb)
        {
            if(x.second==8)
            {
                f=1;
                cout<<"B\n";
                break;
            }
        }
        if(f==1)
        continue;
    } 
}