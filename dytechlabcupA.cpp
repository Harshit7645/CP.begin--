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
        map<char,ll>m;
        rep(i,0,n)
        {
            m[s[i]]++;
        }
        vector<ll>count(26,0);
        for(auto x:m)
        {
            count[x.first-'a']=x.second;
        }
        i=k;
        string temp="";
        ll f=0,j=0,mx=0,req=0,tmep=k;
        while(tmep--)
        {
            f=1;
            j=0;req=n/k;
            if(req<26)
            mx=req;
            else
            mx=26;
            rep(i,0,mx)
            {
                if(count[i]==0)
                {
                    f=0;
                    break;
                }
                count[i]--;
                j++;
            }
            (f)?temp.push_back('a'+req): temp.push_back('a'+j);
        }
        cout<<temp<<endl;
    }
}