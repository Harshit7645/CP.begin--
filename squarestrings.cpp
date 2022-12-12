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
        ll n=s.length();
        if(n%2==0)
        {
            string s1,s2;
            s1=s.substr(0,n/2);
            s2=s.substr(n/2,n/2);
            if(s1==s2)
            PYES;
            else
            PNO;
        }
        else
        PNO;
    }    
}