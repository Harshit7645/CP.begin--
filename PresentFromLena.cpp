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
    ll n,c=0,ct=2,sp,j,i;
    cin>>n;
    sp=n;
    rep(c,0,2*n+1)
    {
        i=c;
        for(j=1;j<=sp;j++)
        cout<<"  ";
        if(i>n){
        i=i-ct;ct+=2;}
        for(j=0;j<i;j++)
        {
        cout<<j<<" ";
        }
        cout<<i;
        if(i!=0)
        cout<<" ";
        for(j=i-1;j>0;j--){
        cout<<j<<" ";
        }
        if(i>0 && i<2*n+1)
        cout<<"0";
        if(c<n)
        sp--;
        else
        sp++;
        cout<<endl;
    }
}
