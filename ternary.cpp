#include <iostream>
using namespace std;
int main()
{
    long long int t,i,j,n,m,flag=0;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        cin>>n>>m;
        long long int arr[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                arr[i][j]=0;
            }
        }
    flag=0;
    for(i=0;i<n/2;i++)
    {
        flag++;
        for(j=0;j<m;j++)
        {
            if(i==0)
            {
                if(j%2==1)
                {
                    flag++;
                    arr[i][j]=flag%2;
                }
                else
                {
                arr[i][j]=flag%2;
                }
            }
            else if(i==1) 
            {
                if(arr[i-1][j]%2==0)
                arr[i][j]=1;
                else
                arr[i][j]=0;
            }
            else{
                if(arr[i-2][j]%2==0)
                arr[i][j]=1;
                else
                arr[i][j]=0;
            }
        }
    }
    for(j=0;j<m;j++)
    {
        arr[0][j]=arr[0][j]%2;
    }
    for(i=0;i<n/2;i++)
    {
        for (j=0;j<m;j++)
        {
            arr[n/2-i][j]=arr[n/2-i][j]%2;
            arr[n/2+i][j]=(arr[n/2-i-1][j]++)%2;
        }
    }
    for(i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            /* code */
            cout<<arr[i][j]%2<<" ";
        }
        cout<<"\n";
    }
    }
    
    return 0;
}
