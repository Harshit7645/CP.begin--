#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n,i,j,ct=0,tz=0,nodig;
        cin>>n;
        int arr[n][n];
        string rs;
        for(i=0;i<n;i++)
        {
            cin>>rs;
            for(j=0;j<n;j++)
            {
                arr[i][j]=(int)(rs[j])-48;
            }
        }
        ct=0;
        for(i=0;i<n/2;i++)
        {
            tz=0;
            for(j=0;j<n/2;j++)
            {
                tz=0;
                if(arr[i][j]==0)
                tz++;
                if(arr[n-i-1][n-j-1]==0)
                tz++;
                if(arr[j][n-i-1]==0)
                tz++;
                if(arr[n-j-1][i]==0)
                tz++;
                if(tz==1 || tz==3)
                ct++;
                else if(tz==2)
                ct+=2;
            }
            tz=0;
            if(n%2==1)
            {
                if(arr[i][n/2]==0)
                tz++;
                if(arr[n/2][n-1-i]==0)
                tz++;
                if(arr[n-1-i][n/2]==0)
                tz++;
                if(arr[n/2][i]==0)
                tz++;
                if(tz==1 || tz==3)
                ct++;
                else if(tz==2)
                ct+=2;
            }
        }
        cout<<ct<<endl;
    }

}
