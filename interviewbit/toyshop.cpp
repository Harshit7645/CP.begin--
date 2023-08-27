#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        ll arr[n],art[n];
        rep(i,0,n)
        {
            cin>>arr[i];
            art[i]=arr[i];
        }
        ll q;
        cin>>q;
        ll amt;
        sort(art,art+n);
        // rep(i,0,n)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<"\n";
        // rep(i,0,n)
        // {
        //     cout<<art[i]<<" ";
        // }
        // cout<<"\n";
        map<ll,ll>broken;
        ll presum[n];
        presum[0]=art[0];
        rep(i,1,n)
        {
            presum[i]=presum[i-1]+art[i];
        }
        // rep(i,0,n)
        // {
        //     cout<<presum[i]<<" ";
        // }
        // cout<<"\n";
        rep(i,0,q)
        {
            broken.clear();
            cin>>amt;
            ll k;
            cin>>k;
            rep(i,0,k)
            {
                ll x;
                cin>>x;
                broken[x-1]++;
            }
            ll ans=0;
            rep(i,0,n)
            {
                if(broken[art[i]])
                continue;
                else if(amt<=0)
                break;
                else
                {
                    ans++;
                    amt-=art[i];
                }
            }
            cout<<ans<<" ";
        }
    }
}   