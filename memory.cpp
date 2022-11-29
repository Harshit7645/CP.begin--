#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,k;
    cin>>t;
    for(k=0;k<t;k++)
    {
        string s;
        cin>>s;  
        int n,ct=1,c=0;
        n=s.length(); 
        map<char,int>m;
        for(char ch:s)
        {
            m[ch]++;
            if(m.size()>3)
            {
                ct++;
                m.clear();
                m[ch]++;
            }
        }
        cout<<ct<<endl;
    } 
    return 0;
}