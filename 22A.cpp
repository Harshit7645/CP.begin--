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
        ll n,i,j;
        cin>>n;
        ll a[n],b[n],noz=0;
        vector<ll>ze,one;
        rep(i,0,n)
        {
            cin>>a[i];
            if(a[i]==0)
            noz++;
        }
        map<ll,ll>m;
        rep(i,0,n)
        {
            cin>>b[i];
            if(a[i]==0)
            {
                ze.push_back(b[i]);
            }
            else
            one.push_back(b[i]);
        }
        sort(b,b+n,greater<>());
        sort(ze.begin(),ze.end());
        reverse(ze.begin(),ze.end());
        sort(one.begin(),one.end());
        reverse(one.begin(),one.end());
        ll dam=0;
        if(noz==n/2 && n%2==0) 
        {
            dam=b[n-1];
            rep(i,0,n-1)
            {
                dam+=b[i]*2;
            }
        }
        else if(noz==0 || noz==n)
        {
            dam=0;
            rep(i,0,n)
            {
                dam+=b[i];
            }
        }
        else
        {
            i=0,j=0;dam=0;
            while(i<one.size() && j<ze.size())
            {
                dam+=ze[j]*2;
                dam+=one[i]*2;
                i++,j++;
            }
                rep(k,i,one.size())
                {
                    dam+=one[k];
                }
                rep(k,j,ze.size())
                {
                    dam+=ze[k];
                }
        }
        cout<<dam<<endl;
    }
}