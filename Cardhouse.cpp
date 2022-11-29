#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a,b,c,d,e,x,i;
    cin>>a>>b>>c>>d>>e;
    vector<ll>v(5);
    v[0]=a;
    v[1]=b;
    v[2]=c;
    v[3]=d;
    v[4]=e;
    sort(v.begin(),v.end());
    i=0;
    if((v[i]==v[i+1] && v[i+1]==v[i+2]) &&(v[i+3]==v[i+4]) && (v[i]!=v[i+3]))
    cout<<"Yes\n";
    else if((v[i]==v[i+1]) &&(v[i+2]==v[i+3] && v[i+3]==v[i+4]) && (v[i]!=v[i+3]))
    cout<<"Yes\n";
    else
    cout<<"No\n";
    return 0;
}