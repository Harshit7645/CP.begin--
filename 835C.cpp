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
        ll s[n],temp[n];
        ll mx=0;
        rep(i,0,n)
        {
            cin>>s[i];
            temp[i]=s[i];
            mx=max(mx,s[i]);
        }
        sort(temp,temp+n);
        ll mx1=temp[n-1],mx2=temp[n-2];
        if(mx1!=mx2){
        rep(i,0,n)
        {
            if(s[i]!=mx)
            cout<<s[i]-mx<<" ";
            else
            cout<<s[i]-mx2<<" ";
        }
        }
        else
        {
           rep(i,0,n)
            {
            cout<<s[i]-mx<<" ";
            } 
        }
        cout<<endl;
    }
}