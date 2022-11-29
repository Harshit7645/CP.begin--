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
        string w,ans="\0";
        for(i=n-1;i>=0;i--)
        {
            if(s[i]=='0' && i>=2)
            {
                w=s.substr(i-2,2);
                int num = stoi(w);
                ans+=(char)(num+96);
                i-=2;
            }
            else
            {
                ans+=(char)((int)s[i]+48);
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
}