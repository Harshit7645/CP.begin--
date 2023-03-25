#include<stdio.h>

int main()
{
    double *ptr=(double*)100;
    ptr=ptr+2;
    printf("%u",ptr);
}