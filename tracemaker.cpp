#include<iostream>
using namespace std;
int main()
{
    int i=0;
    FILE *f1=fopen("trace.txt","w");
    for(i=0;i<4000;i=i+4)
    {
        fprintf(f1,"%d 7d7d 0\n",i);
    }  
} // namespace std;

