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
        ll d,k;
        string x;
        string s="a",t="a";
        rep(i,0,n)
        {
            cin>>d>>k>>x;
            if(d==1)
            {
                rep(i,0,k)
                s+=x;
                sort(s.begin(),s.end());
                if(lexicographical_compare(s.begin(),s.end(),t.begin(),t.end()))
                {
                    PYES;
                    continue;
                }
                else
                PNO;
            }
            if(d==2)
            {
                rep(i,0,k)
                t+=x;
                sort(t.begin(),t.end(),greater<char>());
                if(lexicographical_compare(s.begin(),s.end(),t.begin(),t.end()))
                {
                    PYES;
                    continue;
                }
                else
                PNO;
            }
        }
    } 
}