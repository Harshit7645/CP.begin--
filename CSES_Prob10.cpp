#include <iostream>
using namespace std;
int main()
{
    long long int n,c=0,d=1;
    cin>>n;
    for(long long int i=1;;i++)
    {
        if(n/d!=0)
        {
        d=5*d;
        c=c+n/d;
        }
        else
        break;
    }
    cout<<c;
}
