#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
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
        string s;
        cin>>s;
        //vector<ll>v;'
        map<string,ll>m;
        ll ind=0;
        string temp="";
        rep(i,0,n)
        {
            temp+='W';
        }
        ll red=0,black=0,f=0;
        rep(i,0,n)
        {
            red+=(s[i]=='R');
            black+=(s[i]=='B');
            if(s[i]=='W')
            {
                if((red>0 && black==0)|| (black>0 && red==0))
                {
                    f=1;
                    break;
                }
                red=0;
                black=0;
            }
        }
        if((red>0 && black==0)||(black>0 && red==0))
        {
            f=1;
        }
        if(f)
        {
            PNO;
            continue;
        }
        else
        PYES;
    }
}