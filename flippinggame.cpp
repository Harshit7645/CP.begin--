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
    ll n;
    cin>>n;
    ll arr[n],ones=0;
    rep(i,0,n)
    {
        cin>>arr[i];
        if(arr[i]==1)
        ones++;
    }
    if(ones==n)
    {
    cout<<n-1<<endl;
    return 0;
    }
    else if(ones==n-1)
    {
    cout<<n<<endl;
    return 0;
    }
    ll c=0;
    ll req[2*n],zero=0,one=0,ans=0;
    rep(i,0,n)
    {
        rep(j,i,n)
        {
            //zero=0,one=0,c=0;
            c=0;   
            rep(k,0,n)
            {
                ll t=arr[k];
                if(k>=i && k<=j)
                t=1-t;
                if(t)
                c++;
            }
            ans=max(ans,c);
        }
    }
    //ll ans=0;
    cout<<ans<<endl;
}