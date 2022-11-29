#include<iostream>
using namespace std;
int main()
{
    long long int n,x,y=0;
    cin>>n;
    for (long long int i = 1; i<=n; i++)
    {
        if(i==1)
        {
        x=0;
        y=0;
        cout<<y<<endl;
        }
        else if(i>=2)
        {
        x=2*2*(i-1)*(i-2);
        y=i*i*((i*i)-1)/2 -x;
        cout<<y<<endl;
        }
    }
}