#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll fact(ll n)
{
    ll ans=1;
    rep(i,1,n)
    {
        ans*=i;
    }
    return ans;
}
ll nCr(ll n,ll r)
{
    return (fact(n)/((fact (r))*(fact(n-r))));
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        if(n==1 || n==2)
        {
            cout<<n<<endl;
            continue;
        }
        else
        {
            char ch='\0';
            ch=s[n/2];
            ll ans=0;
            rep(i,n/2,n)
            {
                if(s[i]==ch)
                ans++;
                else
                break;
            }
            if(n%2==1)
            cout<<2*ans-1<<endl;
            else
            cout<<2*ans<<endl;
        }
    }
}