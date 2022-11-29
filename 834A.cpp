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
        string s;
        cin>>s;
        ll n=s.size();
        ll flag=1;
        rep(i,0,n)
        {
            if(s[i]!='Y' && s[i]!='e' && s[i]!='s')
            {
                flag=0;
            }
            if(i+1<n){
            if(s[i]=='Y' && s[i+1]!='e')
            flag=0;
            if(s[i]=='e' && s[i+1]!='s')
            flag=0;
            if(s[i]=='s' && s[i+1]!='Y')
            flag=0;
            }
        }
        if(flag)
        PYES;
        else
        PNO;
    }
}