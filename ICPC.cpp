#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n;
        string s;
        cin>>n;
        cin>>s;
        int i,j,c=0;
        int arr[26];
        for(i=0;i<26;i++)
        {
            arr[i]=0;
        }
        for(i=0;i<26;i++)
        {
            for(j=0;j<n;j++)
            {
                if(s[j]==(char)(i+65))
                arr[i]++;
            }
        }
        for(i=0;i<26;i++)
        {
            if(arr[i]>1)
            c=c+(arr[i]-1)+2;
            else if(arr[i]>0)
            c=c+2;
        }
        cout<<c<<endl;
    }
}