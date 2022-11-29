#include <iostream>
using namespace std;
int main()
{
    long long int t,i,a,b;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>a>>b;
        if((b-2*a)%3==0 && (a-2*b)%3==0 && (b-2*a)<=0 && (a-2*b)<=0)
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    }
}