#include <iostream>
using namespace std;
int main()
{
    long long int m,n,x1,x2,y1,y2,x3,y3,x4,y4,t,i,j,k,c=0;
    cin>>t;
    long long int b,w;
    for (k=0;k<t;k++)
    {
        c=0;
        b=0,w=0;
        cin>>n>>m;
        cin>>x1>>y1>>x2>>y2;
        cin>>x3>>y3>>x4>>y4;
        
        for(i=n;i>=1;i--)
        {
            for(j=1;j<=m;j++)
            {
                if((j%2==0 && i%2==0) || (j%2==1 && i%2==1))
                w++;
                else
                b++;
            }
        }
        for(i=y2;i>=y1;i--)
        {
            for(j=x1;j<=x2;j++)
            {
                if((j%2==1 && i%2==0) || (j%2==0 && i%2==1))
                {
                    w++;
                    b--;
                }
            }
        }
        for(i=y4;i>=y3;i--)
        {
            for(j=x3;j<=x4;j++)
            {
                
            }
        }
        

    }
    return 0;
    
}