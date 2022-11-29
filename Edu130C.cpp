#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b;i>=a;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
typedef vector<ll> vll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        if(n==1)
        {
            PNO;
            continue;
        }
        if(s==t)
        {
            PYES;
            continue;
        }
        ll c1=0,c2=0,c3=0;
        rep(i,0,n)
        {
            if(s[i]=='a')
            c1++;
            if(s[i]=='b')
            c2++;
            if(s[i]=='c')
            c3++;
        }
        ll t2=0;
        ll t1=0,t3=0;
        rep(i,0,n)
        {
            if(s[i]=='a')
            t1++;
            if(s[i]=='b')
            t2++;
            if(s[i]=='c')
            t3++;
        }
        ll noa=c1,noc=c3;
        if(t2==c2 && t1==c1 && t3==c3)
        {
            cout<<"og\n";
            string og="\0",tg="\0";
            rep(i,0,n)
            {
                if(s[i]!='b')
                og+=s[i];
                if(t[i]!='b')
                tg+=s[i];
            }
            vector<ll>sas,scs,tas,tcs;
            //c1=0,c2=0;
            rep(i,0,og.size())
            {
                if(og[i]=='a')
                sas.push_back(i);
                else if(og[i]=='c')
                scs.push_back(i);
            }
            //c1=0,c2=0;
            rep(i,0,tg.size())
            {
                if(tg[i]=='a')
                tas.push_back(i);
                else if(tg[i]=='c')
                tcs.push_back(i);
            }
            ll f=0;
            rep(i,0,sas.size())
            {
                if(sas[i]>tas[i])
                {
                    f=1;
                    break;
                }
            }
            if(f)
            {
                PNO;
                continue;
            }
            rep(i,0,tcs.size())
            {
                if(scs[i]<tcs[i])
                {
                    f=1;
                    break;
                }
            }
            if(f)
            {
                PNO;
                continue;
            }
            if(f==0)
            {
                PYES;
                continue;
            }
        }
        else
        {
            PNO;
            continue;
        }
    } 
}