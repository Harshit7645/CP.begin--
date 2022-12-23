#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
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
        string s;
        cin>>s;
        ll ans=0;
        ans+=((s[0]-'a')*25)+(s[1]-'a');
        if(s[0]<s[1])
        ans--;
        cout<<ans+1<<endl;
    }
}