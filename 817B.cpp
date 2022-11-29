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
        ll n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        ll f=0;
        rep(i,0,n)
        {
            if((s1[i]=='R' && s2[i]=='R'))
            continue;
            else if((s1[i]=='G') && (s2[i]=='G' || s2[i]=='B') ||((s1[i]=='B') && (s2[i]=='G' || s2[i]=='B')))
            continue;
            else
            {
                f=1;
                break;
            }
            //f=1;
        }
        if(f==1)
        PNO;
        else
        PYES;
    }
}