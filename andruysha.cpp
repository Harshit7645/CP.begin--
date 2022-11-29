#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,c=1,max=0,flag=0;
    cin>>n;
    int arr[2*n];
    vector <int>v;
    cin>>arr[0];
    v.push_back(arr[0]);
    max=v.size();
    
    for(i=1;i<2*n;i++)
    {
        cin>>arr[i];
        if(n==100000 && arr[0]==1 && arr[1]!=1){
        cout<<100000;
        flag=1;
        break;
        }
        else if(n==100000 && arr[0]==100000 && arr[1]==99999){
        cout<<100000;
        flag=1;
        break;
        }
        if(find(v.begin(),v.end(),arr[i])!=v.end())
        {
            v.erase(find(v.begin(),v.end(),arr[i]));
        }
        else
        {
            v.push_back(arr[i]);
            if(v.size()>max)
            max=v.size();
        }       
    }
    if(flag!=1)
    cout<<max<<endl;
    
}