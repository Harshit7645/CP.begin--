#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
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
        string s;
        cin>>s;
        ll q=0,a=0,f=0;
        rep(i,0,n)
        {
            if(s[i]=='Q')
            q++;
            else
            a++;
            if(q-a<0)
            {
                q=a;
            }
        }
        if(q!=a)
        PNO;
        else
        PYES;
    }
}