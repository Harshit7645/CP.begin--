#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int fact(int n);
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
int fact(int n)
{
      if(n==0)
      return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    ll n=s1.length();
    double p1=0,n1=0,p2=0,n2=0,q=0,prob=0;
    rep(i,0,n)
    {
        if(s1[i]=='+')
        p1++;
        if(s1[i]=='-')
        n1++;
        if(s2[i]=='+')
        p2++;
        if(s2[i]=='-')
        n2++;
        if(s2[i]=='?')
        q++;
    }
    double temp1=abs(p2-p1)-abs(n2-n1);
    prob=(nCr(q,temp1))*fact(q-temp1)/pow(2,q);
    cout<<prob<<" "<<endl;
}