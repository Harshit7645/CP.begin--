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
    string s;
    cin>>s;
    ll n=s.length();
    string s1,s2;
    s1=s.substr(0,1);
    s2=s.substr(1,n-1);
    transform(s1.begin(),s1.end(),s1.begin(),::toupper);
    cout<<s1+s2<<endl;
}