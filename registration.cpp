#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,k;
    cin>>t;
    map<string,int>m;
    for(k=0;k<t;k++)
    {
        string s;
        cin>>s;
        int n=s.length();
        if(m.find(s)!=m.end())
        {
            m[s]++;
            auto it=m.find(s);
            cout<<(it->first)<<(it->second)<<endl;      
        }
        else{
            cout<<"OK"<<endl;
            m.insert({s,0});
        }
    }
}