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
        ll n,q;
        cin>>n>>q;
        ll arr[n];
        rep(i,0,n)
        cin>>arr[i];
        vector<ll>odd,even;
        ll sum=0;
        rep(i,0,n)
        {
            sum+=arr[i];
            if(arr[i]%2==0)
            even.push_back(arr[i]);
            else
            odd.push_back(arr[i]);
        }
        ll type,a;
        ll o=odd.size(),e=even.size();
        rep(i,0,q)
        {
            cin>>type>>a;
            //ll sum=0;
            if(type==0 && a%2==0)
            {
                sum+=e*a;
            }
            else if(type==1 && a%2==0)
            {
                sum+=o*a;
            }
            else if(type==1 && a%2==1)
            {
                sum+=o*a;
                e=n;
                o=0;
                //swap(o,e);
            }
            else if(type==0 && a%2==1)
            {
                sum+=e*a;
                o=n;
                e=0;
            }
            cout<<sum<<endl;
        }
    } 
}