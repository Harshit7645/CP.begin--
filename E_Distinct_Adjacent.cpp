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
    ll n,m;
    cin>>n>>m;
    ll ans1=max(m-2,1ll);
    ll ans2=power(m-1,n-2);
    ll ans=(((ans2*ans1)%M)*m)%M;
    cout<<ans%M<<endl;
}   