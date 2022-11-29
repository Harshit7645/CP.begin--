#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n,i,j,flag=0;
        cin>>n;
        string arr[n];
        map<string,int>m;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            m.insert({arr[i],1});
        }
        for(i=0;i<n;i++)
        {
            flag=0;
            for(j=1;j<arr[i].length();j++)
            {
                string s1=arr[i].substr(0,j);
                string s2=arr[i].substr(j,arr[i].length()-j);
                if(m[s1] && m[s2])
                flag=1;
            }
            if(flag==1)
            cout<<1;
            else
            cout<<0;
        }
        cout<<endl; 
    }
}