#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int i,j,k;
    for(k=0;k<t;k++)
    {
        string s;
        cin>>s;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        if(s=="yes")
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}