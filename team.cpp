#include <iostream>
using namespace std;
int main()
{
    int n,a,b,c,ct=0,final=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ct=0;
        cin>>a>>b>>c;
        if(a>0)
        ct++;
        if(b>0)
        ct++;
        if(c>0)
        ct++;
        if(ct>=2)
        final++;
    }
    cout<<final;

}