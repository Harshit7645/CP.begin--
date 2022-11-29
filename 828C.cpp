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
        char ch;
        cin>>ch;
        string s,req="\0";
        cin>>s;
        vector<ll>indi;
        ll ind=0;
        req=s;
        req+=s;
        rep(i,0,2*n)
        {
            if(req[i]=='g')
            indi.push_back(i);
        }
        map<ll,ll>m;
        ind=0;
        rep(i,0,n)
        {
            if(i<indi[ind])
            m[i]=indi[ind];
            else
            ind++;
        }
        if(ch=='g'){
        cout<<"0\n";
        continue;
        }
        else
        {
            ll ans=0;
            for(auto x:m)
            {
                //cout<<x.first<<" "<<x.second<<"\n";
                if(s[x.first]==ch)
                ans=max(ans,(x.second-x.first));
            }
            
            cout<<ans<<endl;
        }
    } 
}