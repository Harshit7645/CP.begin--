#include <iostream>
using namespace std;
int swap(int,int);
int main()
{
    int n,i,j,min,t,k;
    cin>>n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (i = 0; i < n; i++)
    {
        min=arr[i];
        for (j=i;j<n;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                k=j;
            }
        }
        arr[k]=arr[i];
        arr[i]=min;
    }
    for (i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}