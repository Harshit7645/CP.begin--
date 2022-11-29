#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,temp;
    set <int>s;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        s.insert(arr[i]);
    }
    cout<<s.size()<<endl;
    temp=0;
    for(i=0;i<n;i++)
    {
        temp=i;
        if(i!=n-1){
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]==arr[temp])
            {
                temp=j;
                break;
            }
        }}
        else{
            cout<<arr[n-1];
        }
        if(temp==i && i!=n-1)
        cout<<arr[i]<<" ";
    }




}