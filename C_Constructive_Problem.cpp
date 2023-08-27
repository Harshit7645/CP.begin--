#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
int M=1e9+7;
 
ll MEX(set<ll>s)
{
    ll c=0;
    for(auto x:s)
    {
        if(x==c)
        c++;
        else
        break;
    }
    return c;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        vector<ll>arr(n);
        set<ll>s;
        rep(i,0,n)
        {
            cin>>arr[i];
            s.insert(arr[i]);
        }
        if(n==1)
        {
            if(arr[0]==1)
            PYES;
            else
            PNO;
            continue;
        }
        ll oldmex=MEX(s);
        ll shdmex=oldmex+1;
        ll first=-1,last=-1;
        rep(i,0,n)
        {
            if(arr[i]==shdmex)
            {
                first=i;
                break;
            }
        }
        repr(i,n-1,0)
        {
            if(arr[i]==shdmex)
            {
                last=i;
                break;
            }
        }
        if(last==first)
        {
            set<ll>st;
            ll f=0;
            rep(i,0,n)
            {
                if(arr[i]<oldmex)
                {
                    if(st.find(arr[i])==st.end())
                    st.insert(arr[i]);
                    else
                    {
                        f=1;
                        break;
                    }
                }
                else
                {
                    f=1;
                    break;
                }
            }
            if(f)
            PYES;
            else
            PNO;
            continue;
        }
        rep(i,first,last+1)
        {
            arr[i]=oldmex;
        }
        s.clear();
        rep(i,0,n)
        {
            s.insert(arr[i]);
        }
        ll newmex=MEX(s);
        if(newmex==oldmex+1)
        PYES;
        else
        PNO;
    }
}   