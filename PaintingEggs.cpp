#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b;i>=a;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
typedef vector<ll> vll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin>>n;
    ll a,g,ca=0,ga=0;
    //map<ll,ll>m;
    vector<ll>ass;
    rep(i,0,n)
    {
        cin>>a>>g;
        ass.push_back(a);
    }
    rep(i,0,n)
    {
        if(ga-ca==0)
        {
            if(ass[i]<=500)
            {        
                cout<<"A";   
                ca+=ass[i];
                continue;
            }
            else{
                cout<<"G";
            ga+=1000-ass[i];
            continue;
            }
        }
        else{
        if(abs(ga-(ca+ass[i]))<=500)
        {
            ca+=ass[i];
            cout<<"A";
            continue;
        }
        else 
        {
            ga+=1000-ass[i];
            cout<<"G";
            continue;
        }
    }
    }
    //cout<<ca<<" "<<ga;
    cout<<"\n";
}