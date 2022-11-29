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
        ll a,b,n,i,flag=0;
        cin>>n>>a>>b;
        i=1;
        vector<ll>req;
        while(i<=n && a!=1)
        {
            req.push_back(i);
            i=i*a;
        }
        if(a==1 && (n-1)%b==0)
        flag=1;
        if(find(req.begin(),req.end(),n)!=req.end())
        flag=1;
        else{
            for(i=0;i<req.size();i++)
            {
                if((n-req[i])%b==0)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
        PYES;
        else
        PNO;
    }
}