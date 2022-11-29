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
    //ll t;
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        cin>>arr[i];
        ll t;
        cin>>t;
        for(ll l=0;l<t;l++)
        {
            ll s,i,j,f=0;
            cin>>s;
            for(i=0;i<n;i++)
            {
                for(j=i+1;j<=n;j++)
                {
                    if(arr[i]+arr[j]==s){
                        f=1;
                    cout<<i<<" "<<j<<"\n";
                    break;  
                    }
                }
                if(f==1)
                break;
            }
            if(f==0)
            cout<<"0\n";
        }
    
}
