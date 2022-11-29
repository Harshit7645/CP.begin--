#include <iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    if(n%4==2 || n%4==1)
    cout<<"NO";
    else if(n%4==0)
    {
        cout<<"YES"<<endl;
        cout<<(n/2)<<endl;
        for(i=1;i<=n/2;i++)
        {
            if(i%2==1)
            {
                cout<<i<<" "<<n-i+1<<" ";
            }
        }
        cout<<endl;
        cout<<(n/2)<<endl;
        for(i=1;i<=n/2;i++)
        {
            if(i%2==0)
            {
                cout<<i<<" "<<n-i+1<<" ";
            }
        }
    }
    else if(n%4==3)
    {
        cout<<"YES"<<endl;
        cout<<((n/2)+1)<<endl;
        for(i=1;i<=(n-1)/2;i++)
        {
            if(i%2==1)
            cout<<i<<" "<<n-i<<" ";
        }
        cout<<endl;
        cout<<n/2<<endl;
        for(i=1;i<=(n-1)/2;i++)
        {
            if(i%2==0)
            cout<<i<<" "<<n-i<<" ";
        }
        cout<<n;
    }
}