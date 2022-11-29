#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
int main()
{
    string s;
    cin>>s;
    ll c=0,n=s.length(),i;
    rep(i,0,n)
    {
        if(s[i]=='.')
        cout<<"0";
        else if(s[i]=='-' && s[i+1]=='.'){
        cout<<"1";i++;}
        else if(s[i]=='-' && s[i+1]=='-'){
        cout<<"2";
        i++;}
    }
    cout<<"\n";
}