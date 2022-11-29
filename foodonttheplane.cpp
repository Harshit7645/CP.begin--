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
    ll n=0,i; 
    char ch; 
    cin>>n>>ch;
    ll ans=0,temp=0;
    n--;
    temp=n/4;
    if(n%2==1)
        ans+=(16*temp)+7;
    else
    ans+=16*temp;
    if(ch=='a')
    ans+=3;
    else if(ch=='b')
    ans+=4;
    else if(ch=='c')
    ans+=5;
    else if(ch=='d')
    ans+=2;
    else if(ch=='e')
    ans+=1;
    cout<<ans+1;//<<" "<<n<<" "<<ch<<" "<<endl;
}