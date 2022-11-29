#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n,x,i,j,temp=0;
        cin>>n>>x;
        int arr[2*n],flag[n];
        for(i=0;i<2*n;i++)
        {
            cin>>arr[i];
            if(i<n)
            flag[i]=0;
        }
        sort(arr,arr+2*n);
        for(i=0;i<n;i++)
        {
            if(arr[n+i]-arr[i]>=x)
            flag[i]=1;
        }
        temp=0;
        for(i=0;i<n;i++)
        {
            if(flag[i]==0)
            {
                temp=1;
                break;
            }
            
        }
        if(temp==1)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;

    }
    return 0;
}