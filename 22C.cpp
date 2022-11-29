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
        vector<ll>odd,even;
        rep(i,0,n)
        {
            cin>>arr[i];
            if(arr[i]%2==0)
            even.push_back(arr[i]);
            else
            odd.push_back(arr[i]);
        }
        if(even.size()==n)
        {
            cout<<"Alice\n";
            continue;
        }
        else
        {
            ll c1=odd.size(),c2=even.size();
            if(c2%2==0)
            {
                //cout<<c1<<" ";
                if(c1%4==1 || c1%4==2)
                {
                    cout<<"Bob\n";
                    continue;
                }
                else if(c1%4==0 || c1%4==3)
                {
                    cout<<"Alice\n";
                    continue;
                }
            }
            else
            {
                if((c1-1)%4==0 || (c1-1)%4==3 || c1%4==3)
                {
                    cout<<"Alice\n";
                    continue;
                }
                else
                {
                    cout<<"Bob\n";
                    continue;
                }
            }
        }
    }
}