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
        ll m,s;
        cin>>m>>s;
        ll b[m];
        map<ll,ll>maa;
        ll sum=0;
        vector<ll>req;
        rep(i,0,m)
        {
            cin>>b[i];
            req.push_back(b[i]);
            maa[b[i]]++;
        }
            ll i=1,f=0;
            while(sum<s)
            {
                if(maa[i])
                i++;
                else{
                    req.push_back(i);
                    sum+=i;
                    i++;
                //cout<<sum<<" ";
                //req.push_back(i);
                }
                if(sum==s)
                {
                    f=1;
                    break;
                }                
            }
            //sort(req.begin(),req.end());
            ll mx=0;
            rep(i,0,req.size())
            {
                mx=max(mx,req[i]);
            }
            if(f)
            {
                //sort(req.begin(),req.end());
                if(mx== req.size())
                PYES;
                else
                PNO;
            }
            else
            PNO;
    }
}