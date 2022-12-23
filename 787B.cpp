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
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        ll ans=0,f=0;
        repr(i,n-2,0)
        {
            if(arr[i]>=arr[i+1])
            {
            while(arr[i]>=arr[i+1])
            {
                ans++;
                arr[i]/=2;
                if(arr[i]==0)
                {
                    break;
                }
            }
            }
            if(arr[i]==arr[i+1])
            {
                f=-1;
            break;
            }
        }
        if(f==-1)
        cout<<-1<<endl;
        else
        cout<<ans<<endl;
        // rep(i,0,n)
        // {
        //     cout<<arr[i]<<" ";
        // }
    }
}