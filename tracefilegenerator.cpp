#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE* f1=fopen("tracefile.txt","r");
    FILE* f2=fopen("address.txt","w");
    for(int i=0;i<1250;i++)
    {
        int x,y;
        string h;
        fscanf(f1,"%d %s %d\n",&x ,h, &y);
        fprintf(f2,"Address = %s",h);
        fprintf(f2,";data_in = %d",y);
        fprintf(f2,"\n#100;");
    }
}