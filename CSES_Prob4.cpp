#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    long long int c=0;
    int arr[n];
    for(i=0;i<n;i++)
    {
         cin>>arr[i];
    }
    c=0;
    for (i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            c=c+arr[i]-arr[i+1];
            arr[i+1]=arr[i];
        }
    }
    cout<<c;
    return 0;

}
