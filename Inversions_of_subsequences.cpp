#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=998244353;

ll power(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        result=(result*a)%M;
        a=(a*a)%M;
        b/=2;
    }
    return result%M;
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        vector<int>left(n,1),right(n,1);
        ll maxm=arr[0];
        rep(i,0,n)
        {
            maxm=max(maxm,arr[i]);
            if(maxm!=arr[i])
            left[i]=0;
        }
        maxm=arr[n-1];
        repr(i,n-1,0)
        {
            maxm=min(maxm,arr[i]);
            if(maxm!=arr[i])
            right[i]=0;
        }
        ll ans=0;
        rep(i,0,n)
        {
            if(left[i] && right[i])
            ans++;
        }
        if(ans==n)
        cout<<power(2,n)-1<<endl;
        else
        cout<<power(2,ans)<<"\n";
    }
}   