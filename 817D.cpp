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
        vector<ll>v,ans;
        ll scores=0;
        rep(i,0,n)
        {
            if(s[i]=='L')
            scores+=i;
            else
            scores+=n-i-1;
            if(s[i]=='L' && i<(n-i-1))
            {
                v.push_back(n-1-2*i);
            }
            else if(s[i]=='R' && i>(n-i-1))
            {
                v.push_back(2*i-n+1);
            }
        }
        sort(v.rbegin(),v.rend());
        ll sums=0;
        rep(i,0,v.size())
        {
            sums+=v[i];
            ans.push_back(scores+sums);
        }
        //ll szx=v.size();
        for(i=v.size();i<n;i++)
        {
            ans.push_back(scores+sums);
        }
        for(ll x:ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}