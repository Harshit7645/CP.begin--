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
    ll t,x;
    cin>>t;
    for(x=1;x<=t;x++)
    {
        cout<<"Case #"<<x<<": ";
        ll l,n;
        cin>>l>>n;
        ll d;
        char ch;
        ll sum=0,laps=0;
        vector<char>v;
        rep(i,0,n)
        {
            cin>>d>>ch;
            v.push_back(ch);
            if(ch=='A')
            {
                if(d>l)
                {
                    if(v[v.size()-2]!='C')
                    laps=laps+(d/l);
                    d=d-((d/l)*l);
                    cout<<laps<<" "<<sum<<"     1\n";
                }
                if(d<l)
                {
                    if(sum-d%l>d)
                    {
                        if(v[v.size()-2]!='C')
                        laps++;
                    }
                    sum=sum+(l-d)%l;   
                    cout<<laps<<" "<<sum<<"     2\n";
                }
                if(d==l)
                {
                    laps++;
                }
            }
            if(ch=='C')
            {
                if(d>l)
                {
                    if(v[v.size()-2]!='A')
                    laps=laps+ (d/l)-1;
                    d=d-((d/l)*l);
                    cout<<laps<<" "<<sum<<"     3\n";
                }
                if(d<l)
                {
                    if(sum+d%l<d){
                        if(v[v.size()-2]!='A')
                    laps++;
                    }

                    sum=(sum+d%l)%l;   
                    cout<<laps<<" "<<sum<<"     4\n";
                }   
                if(d==l)
                {
                    laps++;
                }
                //char temp=
            }
        }
        cout<<laps<<endl;
    }
}