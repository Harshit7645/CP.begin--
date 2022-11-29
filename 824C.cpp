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
        string s,ans="\0";
        cin>>s;
        map<char,ll>m1,m3;
        map<char,char>m2;
        rep(i,0,26)
        {
            m2[(char)(i+97)]='\0';
        }
        rep(i,0,26)
        {
            m1[(char)(i+97)]++;
        }
        rep(i,0,n)
        {
            for(auto x:m1)
            {
                if(x.second==1 && s[i]!=x.first && m3[s[i]]==0)
                {
                    m2[s[i]]=x.first;
                    m1.erase(x.first);
                    m3[s[i]]++;
                    break;
                }
            }
        }
        rep(i,0,n)
        {
            cout<<m2[s[i]];
        }
        //cout<<ans<<"\n";
        cout<<endl;
    }
}