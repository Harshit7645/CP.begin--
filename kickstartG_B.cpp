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
        ll rs,rh;
        cin>>rs>>rh;
        ll n;
        cin>>n;
        ll scorered=0,scoreyel=0;
        double x,y;
        double distance=0;
        vector<double>dr;
        rep(i,0,n)
        {
            cin>>x>>y;
            distance=sqrt((x*x)+(y*y));
            if(distance<=rs+rh)
            dr.push_back(distance);
        }
        ll m,i,j;
        cin>>m;
        if(m==0)
        {
            cout<<dr.size()<<" 0\n";
            continue;
        }
        double z,w;
        vector<double>dy;
        rep(i,0,m)
        {
            cin>>z>>w;
            distance=sqrt((z*z)+(w*w));
            if(distance<=rs+rh)
            dy.push_back(distance);
        }
        ll ans1=0,ans2=0;
        rep(i,0,dr.size())
        {
            ll flag=true;
            rep(j,0,dy.size())
            {
                if (dy[j]<dr[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag==true)
                ans1++;
        }
        rep(i,0,dy.size())
        {
            ll flag=true;
            rep(j,0,dr.size())
            {
                if (dr[j]<dy[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag==true)
                ans2++;
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
}