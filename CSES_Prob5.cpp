#include <iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    if(n==1)
    cout<<"1";
    else if(n==4)
    cout<<"2 4 1 3";
    else if (n==2 ||n==3)
    cout<<"NO SOLUTION"; 
    else
    {
        if(n%2==0)
        {
            for(i=n;i>=1;i-=2)
            {
                cout<<i<<" ";
            }
            for(i=n-1;i>=1;i-=2)
            {
                cout<<i<<" ";
            }
        }
        if(n%2==1)
        {
            for(i=n-1;i>=1;i-=2)
            {
                cout<<i<<" ";
            }
            for(i=n;i>=1;i-=2)
            {
                cout<<i<<" ";
            }
        }
    }
    return 0;
}