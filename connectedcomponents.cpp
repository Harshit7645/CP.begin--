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
        ll n,i;
        cin>>n;
        string s;
        cin>>s;
        ll ans=0;
        rep(i,0,n)
        {
            if(s[i]=='1')
            ans+=pow(2,n-i-1);
        }
        //cout<<ans<<endl;
        i=0;
        if(ans%2==0){
            i=0;
            while(1)
            {
                if(ans/(pow(2,i))<1)
                break;
                i++;
            }
        }
        else
        {
            i=0;
            while(1)
            {
                if(ans/(pow(2,i))==1)
                break;
                i++;
            }
        }
        cout<<i-1<<"\n";
    }
}