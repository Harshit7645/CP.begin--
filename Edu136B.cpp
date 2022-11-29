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
        ll d[n];
        rep(i,0,n)
        {
            cin>>d[i];
        }
        ll sum1=d[0],sum2=d[0],f=0;
        rep(i,1,n)
        {
            if((sum1+d[i]>=0 && sum2-d[i]>=0) && sum1+d[i]!=sum2-d[i])
            {
                f=1;
                cout<<-1<<endl;
                break;
            }
            else
            {
                sum1+=d[i];
                sum2+=d[i];
            }
        }
        if(f==0)
        {
            sum1=0;
            rep(i,0,n)
            {
                sum1+=d[i];
                cout<<sum1<<" ";
            }
            cout<<"\n";
        }
    }
}