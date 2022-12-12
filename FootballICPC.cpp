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
    ll n,a,b;
    cin>>n>>a>>b;
    ll d=0;
    if(n==1 && a==b)
    d++;
    else
    d+=max(0ll,(n-(a+b)));
    cout<<d<<endl;
    while(n>2)
    {
        if(a>0)
        {
            a--;
            cout<<"1:0\n";
        }
        else if(b>0)
        {
            b--;
            cout<<"0:1\n";
        }
        else
        {
            //d++;
            cout<<"0:0\n";
        }
        n--;
    }
    if(n>=2)
    {
        if(a>0 && b>0)
        {
            cout<<a<<":0\n";
            cout<<"0:"<<b<<endl;
        }
        else if(b>1 && a==0)
        {
            cout<<"0:1\n";
            cout<<"0:"<<b-1<<"\n";
        }
        else if(a>1 && b==0)
        {
            cout<<"1:0\n";
            cout<<a-1<<":0\n";
        }
        else if(a==1 && b==0)
        {
            cout<<"1:0\n";
            cout<<"0:0\n";
        }
        else if(a==0 && b==1)
        {
            cout<<"0:1\n";
            cout<<"0:0\n";
        }
        else
        {
            cout<<"0:0\n";
            cout<<"0:0\n";
        }
        //else if(b>0)
    }
    else
    {
        if(a>=0 && b>=0)
        cout<<a<<":"<<b<<"\n";
    }
    if(a==0)
    d++;
    if(b==0)
    d++;
    //cout<<d<<endl;
}