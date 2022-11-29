#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,num,i,j,flag=0,k;
    cin>>n;
    num=pow(2,n);
    int arr[n][num];
    int b[n][num];
    for(i=0;i<n;i++)
    {
        for(j=0;j<num;j++)
        {
            arr[i][j]=0;
        }
    }
    flag=0;
    for(i=0;i<n;i++)
    {
        k=pow(2,i);
        for(j=0;j<num;j++)
        {
            if(j<k)
            {
                arr[i][j]=flag%2;
            }
            else
            {
                flag++;
                arr[i][j]=flag%2;
                k=k+pow(2,i+1);
            }
        }
    }
    
    
    for(j=0;j<num;j++)
    {
        i=0;
        while(i<n)
        {
        cout<<arr[i][j];
        i++;
        }
        cout<<endl;
    }

}