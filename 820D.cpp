#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll n,arr[200001];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        // vector<ll>x(n+1,0);
        cin>>n;
        rep(i,1,n+1)
        {
            cin>>arr[i];
        }
        rep(i,1,n+1)
        {
            ll temp;
            cin>>temp;
            arr[i]=temp-arr[i];
        }
        sort(arr+1,arr+n+1);
        ll j=1,ans=0,i=n;
        while(1)
        {
            for(;j<=n && -1*arr[i]>arr[j];) 
                j++;
            if(j>=i) 
            break;
            ans++;
            i--;
            j++;
        }
        cout<<ans<<endl;
    }
}