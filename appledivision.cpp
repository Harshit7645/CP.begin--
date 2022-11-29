#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,sum1,sum2;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    if(n==1)
    cout<<arr[0];
    else if(n==2) 
    cout<<abs(arr[1]-arr[0]);
    else{
    sum1=arr[n-1];
    sum2=arr[n-2];
    for(i=n-3;i>=0;i--)
    {
        if(sum1<sum2)
        sum1=sum1+arr[i];
        else
        sum2=sum2+arr[i];
    }
    if(sum2>sum1)
    cout<<sum2-sum1;
    else
    cout<<sum1-sum2;}
    return 0;
}