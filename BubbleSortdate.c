#include<stdio.h>
#include<stdlib.h>
struct Date
{
    int day,month,year;
};
void bubbleSort1(struct Date arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
  
        
        for (j = 0; j < n - i - 1; j++)
            if (comparator1(arr[j+1],arr[j]))
                {
                    struct Date c = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = c;
                }
}
int comparator1(struct Date data1,struct Date data2)
{
    if(data1.year < data2.year)
    return 1;
    else if(data1.year == data2.year && data1.month<data2.month)
    return 1;
    else if(data1.year == data2.year && data1.month==data2.month && data1.day<data2.day)
    return 1;
    else
    return 0;
}
void bubblesortdate(FILE *f1,FILE *f2,int n)
{
    
    struct Date arr1[n];
    char ch[12];
    for(int i=0;i<n;i++)
    {
        fscanf(f1,"%s",ch);
        int date = (ch[0]-'0')*10 + ((int)ch[1]-'0');
        int mon;
        if(ch[3]=='j'&&ch[4]=='a'&&ch[5]=='n')
        mon = 1;
        if(ch[3]=='f'&&ch[4]=='e'&&ch[5]=='b')
        mon = 2;
        if(ch[3]=='m'&&ch[4]=='a'&&ch[5]=='r')
        mon = 3;
        if(ch[3]=='a'&&ch[4]=='p'&&ch[5]=='r')
        mon = 4;
        if(ch[3]=='m'&&ch[4]=='a'&&ch[5]=='y')
        mon = 5;
        if(ch[3]=='j'&&ch[4]=='u'&&ch[5]=='n')
        mon = 6;
        if(ch[3]=='j'&&ch[4]=='u'&&ch[5]=='l')
        mon = 7;
        if(ch[3]=='a'&&ch[4]=='u'&&ch[5]=='g')
        mon = 8;
        if(ch[3]=='s'&&ch[4]=='e'&&ch[5]=='p')
        mon = 9;
        if(ch[3]=='o'&&ch[4]=='c'&&ch[5]=='t')
        mon = 10;
        if(ch[3]=='n'&&ch[4]=='o'&&ch[5]=='v')
        mon = 11;
        if(ch[3]=='d'&&ch[4]=='e'&&ch[5]=='c')
        mon = 12;
        int year = (ch[7]-'0')*1000 + (ch[8]-'0')*100+ (ch[9]-'0')*10 + (ch[10]-'0');

        arr1[i].year = year;
        arr1[i].month = mon;
        arr1[i].day = date;
    }
    bubbleSort1(arr1,n);
     
    for(int i=0;i<n;i++)
    {
        fprintf(f2,"%d-",arr1[i].year);
        // fprintf(f2,"%d-",(arr1[i]/100)%100);
        int b = arr1[i].month;
        if(b==1)
        fprintf(f2,"jan-");
        if(b==2)
        fprintf(f2,"feb-");
        if(b==3)
        fprintf(f2,"mar-");
        if(b==4)
        fprintf(f2,"apr-");
        if(b==5)
        fprintf(f2,"may-");
        if(b==6)
        fprintf(f2,"jun-");
        if(b==7)
        fprintf(f2,"jul-");
        if(b==8)
        fprintf(f2,"aug-");
        if(b==9)
        fprintf(f2,"sep-");
        if(b==10)
        fprintf(f2,"oct-");
        if(b==11)
        fprintf(f2,"nov-");
        if(b==12)
        fprintf(f2,"dec-");
        fprintf(f2,"%d\n",(arr1[i].day));
    }    
}
int main()
{
    FILE *f1;
    FILE* f2;
    // f2 = fopen("bd10k.txt","w");
    // f1 = fopen("d10k.txt","r");
    // bubblesortdate(f1,f2,10000);
    // fclose(f1);
    // fclose(f2);
    f2 = fopen("bd20k.txt","w");
    f1 = fopen("d20k.txt","r");
    bubblesortdate(f1,f2,20000);
    fclose(f1);
    fclose(f2);
}