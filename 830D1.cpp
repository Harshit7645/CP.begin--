#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
using namespace std;
int main()
{
    ll n;
    cin>>n;
    map<ll,ll>m;
    set<ll>s;
    rep(p,0,n)
    {
        char ch;
        ll x;
        cin>>ch>>x;
        //cout<<ch<<"$\n";
        if(ch=='+')
        s.insert(x);
        else
        {
            ll y=x;
            // for(auto x:m)
            // {
            //     cout<<x.first<<" "<<x.second<<"\n";
            // }
            if(m[x])
            y=m[x];
            while(s.find(y)!=s.end())
            {
                y+=x;
                //cout<<"%";
            }
            m[x]=y;
            cout<<y<<"\n";
        }
    }
}
