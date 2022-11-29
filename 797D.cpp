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
        ll n,k,i;
        cin>>n>>k;
        string s;
        cin>>s;
        ll ans=1e9,mx=0,maxi=0,cb=0,cw=0;
        rep(i,0,n)
        {   
            if(s[i]=='B')
            {
                cb++;
                }
            else if(cb>mx)
            {
                mx=cb;
                cb=0;
            }
            else
            cb=0;
            if(s[i]=='W')
            cw++;
        }
        mx=max(mx,cb);
        if(mx>k)
        {
            cout<<"0\n";
            continue;
        }
        else if(n==k)
        {
            cout<<cw<<endl;
            continue;
        }
        else 
        {
            //ll ans=0;
            vector<ll> pre(n + 1);
            rep(i,1,n+1)
            pre[i]=pre[i-1]+(ll)(s[i-1]=='W');
            rep(i,k,n+1)
            {
                if(ans>pre[i]-pre[i-k])
                ans=pre[i]-pre[i-k];
            }
        cout<<ans<< endl;
        }
        //cout<<maxi<<" 9898\n";
        //cout<<ans<<"\n";
    }
}