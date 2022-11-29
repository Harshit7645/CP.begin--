#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
int main()
{
    ll n,t,i,j;
    string s;
    char ch;
    cin>>n>>t;
    cin>>s;
    for(i=0;i<t;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(s[j]=='B' && s[j+1]=='G')
            {
                s[j+1]='B';
                s[j]='G';
                j++;
            }
        }
    }
    cout<<s<<"\n";
}