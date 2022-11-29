#include <iostream>
using namespace std;
int main()
{
    long long int n,m,a,l=0,b=0;
    cin>>n>>m>>a;
    if(n%a==0)
    l=n/a;
    else
    l=n/a +1;
    if(m%a==0)
    b=m/a;
    else
    b=m/a +1;
    cout<<l*b;
}