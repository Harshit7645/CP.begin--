#include <iostream>
using namespace std;
int main()
{
    long long int n,i,k=0,c=0,gap=0,last=0,j=0;
    long long int l=0,r=0;
    cin>>n;
    long long int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    long long int temp;
    temp=arr[0];
    for (i = 1; i < n; i++)
    {
        if(arr[i]<=temp)
        {
            temp=arr[i];
            last=i;
        }
    }
    for (i = 0; i < n; i++)
    {
        if(arr[i]==temp)
        c++;
    }
    if(c==1)
    {
    cout<<n*temp + n-1;
    return 0;
    }
    if(c==n)
    {
    cout<<n*temp;
    return 0;
    }
    j=0;
    if(c>1)
    {
        for(j=0;j<n;j++)
        {
            if(arr[j]==temp){
            l=j;
            gap=(n-last-1)+l;
            break;}
        }
        j=l+1;
        while(j<n)
        {
            if(temp==arr[j])
            {
                r=j;
                if(r-l-1>gap)
                {
                gap=r-l-1;
                }
                l=r;
            }
            j++;
            
        }
    }
    if(c<n)
    cout<<(temp*n) + (gap) ;
    return 0;
}