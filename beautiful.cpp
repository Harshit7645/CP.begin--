#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,temp,t,flag=0;
    int arr[5][5];
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<abs(j-2) +abs(i-2)<<endl;
            break;
        }
    }

    
    
}
