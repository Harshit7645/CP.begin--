#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,j,flag=0;
    cin>>n>>m;
    char arr[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='.' &&((i%2==0 && j%2==0)||(i%2==1 &&j%2==1)))
            arr[i][j]='B';
            else if(arr[i][j]=='.' && ((i%2==1 && j%2==0)||(i%2==0 &&j%2==1)))
            arr[i][j]='W';
            
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}