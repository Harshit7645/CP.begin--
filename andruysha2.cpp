#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,max;
    cin>>n;
    int arr[2*n];
    map<int,int>m;
    for(i=0;i<2*n;i++)
    {
        cin>>arr[i];
        m.insert(arr[i],i);
    }
    
}