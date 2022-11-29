#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    for(long long int k=0;k<t;k++)
    {
        long long int n,i;
        cin>>n;
        long long int arr[n];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        cout<<arr[0]+arr[1]<<"\n";
    }
}