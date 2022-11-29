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
        ll n1,m;
        cin>>n1>>m;
        if((n1==2 && m==2) || (n1==1 ||m==1))
        {
            cout<<n1<<" "<<m<<"\n";
        }
        else if(n1==3 || m==3){
            cout<<n1/2+1<<" "<<m/2+1<<"\n";
            continue;
        }
        else
        {cout<<n1<<" "<<m<<"\n";
        continue;}
    }
}