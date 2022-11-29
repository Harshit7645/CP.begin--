#include <iostream>
using namespace std;
int main()
{
    long long int t,y,x,i;
    long long int a,b,c;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>y>>x;
        if(y%2==1)
        a=(y-1)*(y-1) +1;
        else 
        a=y*y;

        if(x%2==0)
        b=(x-1)*(x-1) +1;
        else
        b=x*x;

        if(x==y)
        c=(a+b)/2;
        else if(x>y)
        {
            if(x%2==0)
            c=b+y-1;
            else
            c=b-y+1;
        }
        else if(x<y)
        {
            if(y%2==1)
            c=a+x-1;
            else
            c=a-x+1;
        }
        cout<<c<<endl;
        
        
    }
    return 0;
}