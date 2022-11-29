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
        ll arr[n];
        map<ll,ll>req;
        rep(i,0,n)
        {
            cin>>arr[i];
            req[arr[i]]=i+1;
        }
        ll ans=-1,f=0;
        if(1==arr[n-1])
        {
            f=1;
        cout<<2*n<<endl;
        continue;
        }
        rep(i,1,1001)
        {
            rep(j,1,1001)
            {
                if(!req[i] || !req[j]) continue;
			if(gcd(i,j) != 1) continue;
            f=1;
			ans = max(ans,req[i]+req[j]);
            }
        }
        if(f)
        cout<<ans<<endl;
        else
        cout<<"-1\n";
    } 
}