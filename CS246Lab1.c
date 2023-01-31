#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct Date
{
    int day, month,year;
};
struct Datetime
{
    int day,month,year;
    int hour,min,sec;
};

void randgenerate1()
{
    FILE *f1, *f2 , *f3, *f4, *f5,*f6,*f7,*f8,*f9,*f10;
    f1 = fopen("i10k.txt","w");
    for(int i=1;i<=10000;i++)
    {
        fprintf(f1,"%d\n",rand()%1000000);
    }
    fclose(f1);
    f2 = fopen("i20k.txt","w");
    for(int i=1;i<=20000;i++)
    {
        fprintf(f2,"%d\n",rand()%1000000);
    }
    fclose(f2);
    f3 = fopen("i40k.txt","w");
    for(int i=1;i<=40000;i++)
    {
        fprintf(f3,"%d\n",rand()%1000000);
    }
    fclose(f3);
    f4 = fopen("i80k.txt","w");
    for(int i=1;i<=80000;i++)
    {
        fprintf(f4,"%d\n",rand()%1000000);
    }
    fclose(f4);
    f5 = fopen("i160k.txt","w");
    for(int i=1;i<=160000;i++)
    {
        fprintf(f5,"%d\n",rand()%1000000);
    }
    fclose(f5);
    f6 = fopen("i320k.txt","w");
    for(int i=1;i<=320000;i++)
    {
        fprintf(f6,"%d\n",rand()%1000000);
    }
    fclose(f6);
    f7 = fopen("i640k.txt","w");
    for(int i=1;i<=640000;i++)
    {
        fprintf(f7,"%d\n",rand()%1000000);
    }
    fclose(f7);
    f8 = fopen("i1280k.txt","w");
    for(int i=1;i<=1280000;i++)
    {
        fprintf(f8,"%d\n",rand()%1000000);
    }
    fclose(f8);
    f9 = fopen("i2560k.txt","w");
    for(int i=1;i<=2560000;i++)
    {
        fprintf(f9,"%d\n",rand()%1000000);
    }
    fclose(f9);
    f10 = fopen("i5120k.txt","w");
    for(int i=1;i<=5120000;i++)
    {
        fprintf(f1,"%d\n",rand()%1000000);
    }
    fclose(f10);
}

void randgener2(FILE *f1,int n){
    //month 1 to 12
    //year 1947 to 2022
    //date 1 to 30
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        a=1+(rand())%30;
        b=1+(rand())%12;
        c=1947+(rand())%76;
        if(c==1947 && b<8)
        {
            i--;
            continue;
        }
        if(c==1947 && b==8 && c<15)
        {
            i--;
            continue;
        }
        fprintf(f1,"%d%d-",a/10,a%10);
        // fprintf(f1,"%d-",b);
        if(b==1)
        fprintf(f1,"jan-");
        if(b==2)
        fprintf(f1,"feb-");
        if(b==3)
        fprintf(f1,"mar-");
        if(b==4)
        fprintf(f1,"apr-");
        if(b==5)
        fprintf(f1,"may-");
        if(b==6)
        fprintf(f1,"jun-");
        if(b==7)
        fprintf(f1,"jul-");
        if(b==8)
        fprintf(f1,"aug-");
        if(b==9)
        fprintf(f1,"sep-");
        if(b==10)
        fprintf(f1,"oct-");
        if(b==11)
        fprintf(f1,"nov-");
        if(b==12)
        fprintf(f1,"dec-");
        fprintf(f1,"%d\n",c);
    }
}
void randgenerate2()
{
    FILE *f1;
    f1 = fopen("d10k.txt","w");
    randgener2(f1,10000);
    fclose(f1);
    
    f1 = fopen("d20k.txt","w");
    randgener2(f1,20000);
    fclose(f1);
    
    f1 = fopen("d40k.txt","w");
    randgener2(f1,40000);
    fclose(f1);

    f1 = fopen("d80k.txt","w");
    randgener2(f1,80000);
    fclose(f1);

    f1 = fopen("d160k.txt","w");
    randgener2(f1,160000);
    fclose(f1);

    f1 = fopen("d320k.txt","w");
    randgener2(f1,320000);
    fclose(f1);

    f1 = fopen("d640k.txt","w");
    randgener2(f1,640000);
    fclose(f1);

    f1 = fopen("d1280k.txt","w");
    randgener2(f1,1280000);
    fclose(f1);

    f1 = fopen("d2560k.txt","w");
    randgener2(f1,2560000);
    fclose(f1);

    f1 = fopen("d5120k.txt","w");
    randgener2(f1,5120000);
    fclose(f1);

}
void randgener3(FILE *f1,int n){
    //month 1 to 12
    //year 1947 to 2022
    //date 1 to 30
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        a=1+(rand())%30;
        b=1+(rand())%12;
        c=1947+(rand())%76;
        if(c==1947 && b<8)
        {
            i--;
            continue;
        }
        if(c==1947 && b==8 && c<15)
        {
            i--;
            continue;
        }
        fprintf(f1,"%d%d-",a/10,a%10);
        // fprintf(f1,"%d-",b);
        if(b==1)
        fprintf(f1,"jan-");
        if(b==2)
        fprintf(f1,"feb-");
        if(b==3)
        fprintf(f1,"mar-");
        if(b==4)
        fprintf(f1,"apr-");
        if(b==5)
        fprintf(f1,"may-");
        if(b==6)
        fprintf(f1,"jun-");
        if(b==7)
        fprintf(f1,"jul-");
        if(b==8)
        fprintf(f1,"aug-");
        if(b==9)
        fprintf(f1,"sep-");
        if(b==10)
        fprintf(f1,"oct-");
        if(b==11)
        fprintf(f1,"nov-");
        if(b==12)
        fprintf(f1,"dec-");
        fprintf(f1,"%d_",c);
        int k1 = rand()%24;
        fprintf(f1,"_%d%d:", k1/10,k1%10);
        int k2 = rand()%60;
        fprintf(f1,"%d%d:",k2/10,k2%10);
        int k3 = rand()%60;
        fprintf(f1,"%d%d\n",k3/10,k3%10);
    }
}
void randgenerate3()
{
    FILE *f1;
    f1 = fopen("dt10k.txt","w");
    randgener3(f1,10000);
    fclose(f1);
    
    f1 = fopen("dt20k.txt","w");
    randgener3(f1,20000);
    fclose(f1);
    
    f1 = fopen("dt40k.txt","w");
    randgener3(f1,40000);
    fclose(f1);

    f1 = fopen("dt80k.txt","w");
    randgener3(f1,80000);
    fclose(f1);

    f1 = fopen("dt160k.txt","w");
    randgener3(f1,160000);
    fclose(f1);

    f1 = fopen("dt320k.txt","w");
    randgener3(f1,320000);
    fclose(f1);

    f1 = fopen("dt640k.txt","w");
    randgener3(f1,640000);
    fclose(f1);

    f1 = fopen("dt1280k.txt","w");
    randgener3(f1,1280000);
    fclose(f1);

    f1 = fopen("dt2560k.txt","w");
    randgener3(f1,2560000);
    fclose(f1);

    f1 = fopen("dt5120k.txt","w");
    randgener3(f1,5120000);
    fclose(f1);

}
void reading(){
    FILE *f1;
    f1 = fopen("dt10k.txt","r");
    fclose(f1);
    f1 = fopen("dt20k.txt","r");
    fclose(f1);
    f1 = fopen("dt40k.txt","r");
    fclose(f1);
    f1 = fopen("dt80k.txt","r");
    fclose(f1);
    f1 = fopen("dt160k.txt","r");
    fclose(f1);
    f1 = fopen("dt320k.txt","r");
    fclose(f1);
    f1 = fopen("dt640k.txt","r");
    fclose(f1);
    f1 = fopen("dt1280k.txt","r");
    fclose(f1);
    f1 = fopen("dt2560k.txt","r");
    fclose(f1);
    f1 = fopen("dt5120k.txt","r");
    fclose(f1);
    f1 = fopen("d10k.txt","r");
    fclose(f1);
    f1 = fopen("d20k.txt","r");
    fclose(f1);
    f1 = fopen("d40k.txt","r");
    fclose(f1);
    f1 = fopen("d80k.txt","r");
    fclose(f1);
    f1 = fopen("d160k.txt","r");
    fclose(f1);
    f1 = fopen("d320k.txt","r");
    fclose(f1);
    f1 = fopen("d640k.txt","r");
    fclose(f1);
    f1 = fopen("d1280k.txt","r");
    fclose(f1);
    f1 = fopen("d2560k.txt","r");
    fclose(f1);
    f1 = fopen("d5120k.txt","r");
    fclose(f1);

}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                {
                    int c = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = c;
                }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i
        = (low
           - 1); 
  
    for (int j = low; j <= high - 1; j++) {
       
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        
        int pi = partition(arr, low, high);
  
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void bubblesortingintegers()
{
     
    FILE* f1;
    f1 = fopen("i10k.txt","r");
    int *arr1;
    arr1 = (int*) malloc(10000*sizeof(int));
    for(int i=0;i<10000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
   
    bubbleSort(arr1,10000);
   
     FILE* f2;
    f2 = fopen("bi10k.txt","w");
    for(int i=0;i<10000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);
   
   
    f1 = fopen("i20k.txt","r");
    arr1 = realloc(arr1, 20000*sizeof(int));
    for(int i=0;i<20000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    bubbleSort(arr1,20000);
  
    f2 = fopen("bi20k.txt","w");
    for(int i=0;i<20000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i40k.txt","r");
    arr1 = realloc(arr1, 40000*sizeof(int));
    for(int i=0;i<40000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    bubbleSort(arr1,40000);
  
    f2 = fopen("bi40k.txt","w");
    for(int i=0;i<40000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i80k.txt","r");
    arr1 = realloc(arr1, 80000*sizeof(int));
    for(int i=0;i<80000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    bubbleSort(arr1,80000);
  
    f2 = fopen("bi80k.txt","w");
    for(int i=0;i<80000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i160k.txt","r");
    arr1 = realloc(arr1, 160000*sizeof(int));
    for(int i=0;i<160000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    bubbleSort(arr1,160000);
  
    f2 = fopen("bi160k.txt","w");
    for(int i=0;i<160000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i320k.txt","r");
    arr1 = realloc(arr1, 320000*sizeof(int));
    for(int i=0;i<320000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    bubbleSort(arr1,320000);
  
    f2 = fopen("bi320k.txt","w");
    for(int i=0;i<320000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i640k.txt","r");
    arr1 = realloc(arr1, 640000*sizeof(int));
    for(int i=0;i<640000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    bubbleSort(arr1,640000);
  
    f2 = fopen("bi640k.txt","w");
    for(int i=0;i<640000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i1280k.txt","r");
    arr1 = realloc(arr1, 1280000*sizeof(int));
    for(int i=0;i<1280000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    bubbleSort(arr1,1280000);
  
    f2 = fopen("bi1280k.txt","w");
    for(int i=0;i<1280000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i2560k.txt","r");
    arr1 = realloc(arr1, 2560000*sizeof(int));
    for(int i=0;i<2560000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    bubbleSort(arr1,2560000);
  
    f2 = fopen("bi2560k.txt","w");
    for(int i=0;i<2560000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);
    
    f1 = fopen("i5120k.txt","r");
    arr1 = realloc(arr1, 5120000*sizeof(int));
    for(int i=0;i<5120000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    bubbleSort(arr1,5120000);
   
    f2 = fopen("bi5120k.txt","w");
    for(int i=0;i<5120000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);
}
void quicksortingintegers()
{
     
    FILE* f1;
    f1 = fopen("i10k.txt","r");
    int *arr1;
    arr1 = (int*) malloc(10000*sizeof(int));
    for(int i=0;i<10000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
   
    quickSort(arr1,0,10000-1);
   
     FILE* f2;
    f2 = fopen("qi10k.txt","w");
    for(int i=0;i<10000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);
   
   
    f1 = fopen("i20k.txt","r");
    arr1 = realloc(arr1, 20000*sizeof(int));
    for(int i=0;i<20000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    quickSort(arr1,0,20000-1);
  
    f2 = fopen("qi20k.txt","w");
    for(int i=0;i<20000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i40k.txt","r");
    arr1 = realloc(arr1, 40000*sizeof(int));
    for(int i=0;i<40000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    quickSort(arr1,0,40000-1);
  
    f2 = fopen("qi40k.txt","w");
    for(int i=0;i<40000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i80k.txt","r");
    arr1 = realloc(arr1, 80000*sizeof(int));
    for(int i=0;i<80000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    quickSort(arr1,0,80000-1);
  
    f2 = fopen("qi80k.txt","w");
    for(int i=0;i<80000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i160k.txt","r");
    arr1 = realloc(arr1, 160000*sizeof(int));
    for(int i=0;i<160000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    quickSort(arr1,0,160000-1);
  
    f2 = fopen("qi160k.txt","w");
    for(int i=0;i<160000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i320k.txt","r");
    arr1 = realloc(arr1, 320000*sizeof(int));
    for(int i=0;i<320000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    quickSort(arr1,0,320000-1);
  
    f2 = fopen("qi320k.txt","w");
    for(int i=0;i<320000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i640k.txt","r");
    arr1 = realloc(arr1, 640000*sizeof(int));
    for(int i=0;i<640000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    quickSort(arr1,0,640000-1);
  
    f2 = fopen("qi640k.txt","w");
    for(int i=0;i<640000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i1280k.txt","r");
    arr1 = realloc(arr1, 1280000*sizeof(int));
    for(int i=0;i<1280000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    quickSort(arr1,0,1280000-1);
  
    f2 = fopen("qi1280k.txt","w");
    for(int i=0;i<1280000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);

    f1 = fopen("i2560k.txt","r");
    arr1 = realloc(arr1, 2560000*sizeof(int));
    for(int i=0;i<2560000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    quickSort(arr1,0,2560000-1);
  
    f2 = fopen("qi2560k.txt","w");
    for(int i=0;i<2560000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);
    
    f1 = fopen("i5120k.txt","r");
    arr1 = realloc(arr1, 5120000*sizeof(int));
    for(int i=0;i<5120000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    quickSort(arr1,0,5120000-1);
   
    f2 = fopen("qi5120k.txt","w");
    for(int i=0;i<5120000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);
}

int comparator1(struct Date d1,struct Date d2)
{
    if(d1.year < d2.year)
    return 1;
    if(d1.year == d2.year && d1.month<d2.month)
    return 1;
    if(d1.year == d2.year && d1.month==d2.month && d1.day<d2.day)
    return 1;

    return 0;
}
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
void timeprint()
{
    FILE * f3;
    f3 = fopen("finaltime.txt","w");
    fprintf(f3,"%s","BUBBLE SORT ->\n");
     FILE* f1;
    f1 = fopen("i10k.txt","r");
     fprintf(f3,"%s","for 10k -- ");
    int arr1[10000];
    for(int i=0;i<10000;i++)
    {
        fscanf(f1,"%d",&arr1[i]);
    }
    clock_t t,t1;
    t = clock();
    bubbleSort(arr1,10000);
    t1 = clock() - t;
    double time_taken = ((double)t1)/CLOCKS_PER_SEC;
    fprintf(f3,"%g , ",time_taken);
     FILE* f2;
    f2 = fopen("si10k.txt","w");
    for(int i=0;i<10000;i++)
    {
        fprintf(f2,"%d\n",arr1[i]);
    }
    fclose(f1);
    fclose(f2);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(f3,"%g\n",time_taken);



    fprintf(f3,"%s","for 20k -- ");
    f1 = fopen("i20k.txt","r");
    int arr2[20000];
    for(int i=0;i<20000;i++)
    {
        fscanf(f1,"%d",&arr2[i]);
    }
    
    t = clock();
    bubbleSort(arr2,20000);
    t1 = clock() - t;
    time_taken = ((double)t1)/CLOCKS_PER_SEC;
    fprintf(f3,"%g , ",time_taken);
    f2 = fopen("si20k.txt","w");
    for(int i=0;i<20000;i++)
    {
        fprintf(f2,"%d\n",arr2[i]);
    }
    fclose(f1);
    fclose(f2);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(f3,"%g\n",time_taken);


    fprintf(f3,"%s","for 40k -- ");
    f1 = fopen("i40k.txt","r");
    int arr3[40000];
    for(int i=0;i<40000;i++)
    {
        fscanf(f1,"%d",&arr3[i]);
    }
    t = clock();
    bubbleSort(arr3,40000);
    t1 = clock() - t;
    time_taken = ((double)t1)/CLOCKS_PER_SEC;
    fprintf(f3,"%g , ",time_taken);
    f2 = fopen("si40k.txt","w");
    for(int i=0;i<40000;i++)
    {
        fprintf(f2,"%d\n",arr3[i]);
    }
    fclose(f1);
    fclose(f2);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(f3,"%g\n",time_taken);

    fprintf(f3,"%s","for 80k -- ");
    f1 = fopen("i80k.txt","r");
    int arr4[80000];
    for(int i=0;i<80000;i++)
    {
        fscanf(f1,"%d",&arr4[i]);
    }
    t = clock();
    bubbleSort(arr4,80000);
    t1 = clock() - t;
    time_taken = ((double)t1)/CLOCKS_PER_SEC;
    fprintf(f3,"%g , ",time_taken);
    f2 = fopen("si80k.txt","w");
    for(int i=0;i<80000;i++)
    {
        fprintf(f2,"%d\n",arr4[i]);
    }
    fclose(f1);
    fclose(f2);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(f3,"%g\n",time_taken);


        
    // fprintf(f3,"%s","for 160k -- ");
    // f1 = fopen("i160k.txt","r");
    // int arr5[160000];
    // for(int i=0;i<160000;i++)
    // {
    //     fscanf(f1,"%d",&arr5[i]);
    // }
    // bubbleSort(arr5,160000);
  
    // f2 = fopen("si160k.txt","w");
    // for(int i=0;i<160000;i++)
    // {
    //     fprintf(f2,"%d\n",arr5[i]);
    // }
    // fclose(f1);
    // fclose(f2);

    // f1 = fopen("i320k.txt","r");
    // int arr6[320000];
    // for(int i=0;i<320000;i++)
    // {
    //     fscanf(f1,"%d",&arr6[i]);
    // }
    // bubbleSort(arr6,320000);
  
    // f2 = fopen("si320k.txt","w");
    // for(int i=0;i<320000;i++)
    // {
    //     fprintf(f2,"%d\n",arr6[i]);
    // }
    // fclose(f1);
    // fclose(f2);

    // f1 = fopen("i640k.txt","r");
    // int arr7[640000];
    // for(int i=0;i<640000;i++)
    // {
    //     fscanf(f1,"%d",&arr7[i]);
    // }
    // bubbleSort(arr7,640000);
  
    // f2 = fopen("si640k.txt","w");
    // for(int i=0;i<640000;i++)
    // {
    //     fprintf(f2,"%d\n",arr7[i]);
    // }
    // fclose(f1);
    // fclose(f2);

    // f1 = fopen("i1280k.txt","r");
    // int arr8[1280000];
    // for(int i=0;i<1280000;i++)
    // {
    //     fscanf(f1,"%d",&arr8[i]);
    // }
    // bubbleSort(arr8,1280000);
  
    // f2 = fopen("si1280k.txt","w");
    // for(int i=0;i<1280000;i++)
    // {
    //     fprintf(f2,"%d\n",arr8[i]);
    // }
    // fclose(f1);
    // fclose(f2);

    // f1 = fopen("i2560k.txt","r");
    // int arr9[2560000];
    // for(int i=0;i<2560000;i++)
    // {
    //     fscanf(f1,"%d",&arr9[i]);
    // }
    // bubbleSort(arr9,2560000);
  
    // f2 = fopen("si2560k.txt","w");
    // for(int i=0;i<2560000;i++)
    // {
    //     fprintf(f2,"%d\n",arr9[i]);
    // }
    // fclose(f1);
    // fclose(f2);
    // FILE *f1;
    // f1 = fopen("i5120k.txt","r");
    // int arr[5120000];
    // for(int i=0;i<5120000;i++)
    // {
    //     fscanf(f1,"%d",&arr[i]);
    // }
    // bubbleSort(arr,5120000);
    // FILE *f2;
    // f2 = fopen("si5120k.txt","w");
    // for(int i=0;i<5120000;i++)
    // {
    //     fprintf(f2,"%d\n",arr[i]);
    // }
    // fclose(f1);
    // fclose(f2);
}
void quicksortingall2(FILE *f1,FILE *f2,int n)
{
    
    int *arr;
    arr = (int*)malloc(n*sizeof(int));
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

        arr[i] = year*10000 + mon*100 + date;

    }
    quickSort(arr,0,n-1);
     
    for(int i=0;i<n;i++)
    {
        fprintf(f2,"%d-",arr[i]/10000);
        // fprintf(f2,"%d-",(arr1[i]/100)%100);
        int b = (arr[i]/100)%100;
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
        fprintf(f2,"%d\n",(arr[i]%100));
    }
   
    free(arr);
    
}
void quicksortingdates()
{
    FILE *f1;
    FILE* f2;
    f2 = fopen("qd10k.txt","w");
    f1 = fopen("d10k.txt","r");
    quicksortingall2(f1,f2,10000);
    fclose(f1);
    fclose(f2);
    f2 = fopen("qd20k.txt","w");
    f1 = fopen("d20k.txt","r");
    quicksortingall2(f1,f2,20000);
    fclose(f1);
    fclose(f2);
    f2 = fopen("qd40k.txt","w");
    f1 = fopen("d40k.txt","r");
    quicksortingall2(f1,f2,40000);
    fclose(f1);
    fclose(f2);
    f2 = fopen("qd80k.txt","w");
    f1 = fopen("d80k.txt","r");
    quicksortingall2(f1,f2,80000);
    fclose(f1);
    fclose(f2);
    f2 = fopen("qd160k.txt","w");
    f1 = fopen("d160k.txt","r");
    quicksortingall2(f1,f2,160000);
    fclose(f1);
    fclose(f2);

    f2 = fopen("qd320k.txt","w");
    f1 = fopen("d320k.txt","w");
    quicksortingall2(f1,f2,320000);
    fclose(f1);
    fclose(f2);
    
    f2 = fopen("qd640k.txt","w");
    f1 = fopen("d640k.txt","w");
    quicksortingall2(f1,f2,640000);
    fclose(f1);
    fclose(f2);
    
    f2 = fopen("qd1280k.txt","w");
    f1 = fopen("d1280k.txt","w");
    quicksortingall2(f1,f2,1280000);
    fclose(f1);
    fclose(f2);
    
    f2 = fopen("qd2560k.txt","w");
    f1 = fopen("d2560k.txt","w");
    quicksortingall2(f1,f2,2560000);
    fclose(f1);
    fclose(f2);
    
    f2 = fopen("qd5120k.txt","w");
    f1 = fopen("d5120k.txt","w");
    quicksortingall2(f1,f2,5120000);
    fclose(f1);
    fclose(f2);
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
void bubbleSortingdates()
{
    FILE *f1;
    FILE* f2;
    f2 = fopen("bd10k.txt","w");
    f1 = fopen("d10k.txt","r");
    bubblesortdate(f1,f2,10000);
    fclose(f1);
    fclose(f2);
    f2 = fopen("bd20k.txt","w");
    f1 = fopen("d20k.txt","r");
    bubblesortdate(f1,f2,20000);
    fclose(f1);
    fclose(f2);
    f2 = fopen("bd40k.txt","w");
    f1 = fopen("d40k.txt","r");
    bubblesortdate(f1,f2,40000);
    fclose(f1);
    fclose(f2);
    f2 = fopen("bd80k.txt","w");
    f1 = fopen("d80k.txt","r");
    bubblesortdate(f1,f2,80000);
    fclose(f1);
    fclose(f2);
    f2 = fopen("bd160k.txt","w");
    f1 = fopen("d160k.txt","r");
    bubblesortdate(f1,f2,160000);
    fclose(f1);
    fclose(f2);

    // f2 = fopen("bd320k.txt","w");
    // f1 = fopen("d320k.txt","w");
    // bubblesortdate(f1,f2,320000);
    // fclose(f1);
    // fclose(f2);
    
    // f2 = fopen("bd640k.txt","w");
    // f1 = fopen("d640k.txt","w");
    // bubblesortdate(f1,f2,640000);
    // fclose(f1);
    // fclose(f2);
    
    // f2 = fopen("bd1280k.txt","w");
    // f1 = fopen("d1280k.txt","w");
    // bubblesortdate(f1,f2,1280000);
    // fclose(f1);
    // fclose(f2);
    
    // f2 = fopen("bd2560k.txt","w");
    // f1 = fopen("d2560k.txt","w");
    // bubblesortdate(f1,f2,2560000);
    // fclose(f1);
    // fclose(f2);
    
    // f2 = fopen("bd5120k.txt","w");
    // f1 = fopen("d5120k.txt","w");
    // bubblesortdate(f1,f2,5120000);
    // fclose(f1);
    // fclose(f2);
}

int comparator2(struct Datetime d1,struct Datetime d2)
{
    if(d1.year < d2.year)
    return 1;
    if(d1.year == d2.year && d1.month<d2.month)
    return 1;
    if(d1.year == d2.year && d1.month==d2.month && d1.day<d2.day)
    return 1;
    if(d1.year == d2.year && d1.month==d2.month && d1.day==d2.day && d1.hour<d2.hour)
    return 1;
    if(d1.year == d2.year && d1.month==d2.month && d1.day==d2.day && d1.hour==d2.hour && d1.min<d2.min)
    return 1;
    if(d1.year == d2.year && d1.month==d2.month && d1.day==d2.day && d1.hour==d2.hour && d1.min==d2.min && d1.sec<d2.sec)
    return 1;

    return 0;
}
void bubbleSort2(struct Datetime arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
  
        
        for (j = 0; j < n - i - 1; j++)
            if (comparator2(arr[j+1],arr[j]))
                {
                    struct Datetime c = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = c;
                }
}
void bubblesortdatetime(FILE *f1,FILE *f2,int n)
{
    
    struct Datetime arr1[n];
    char ch[25];
    for(int i=0;i<n;i++)
    {
        fscanf(f1,"%s",ch);
        int date = (ch[0]-'0')*10 + (ch[1]-'0');
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
        arr1[i].hour=(ch[13]-'0')*10 + (ch[14]-'0');
        arr1[i].min=(ch[16]-'0')*10 + (ch[17]-'0');
        arr1[i].sec=(ch[19]-'0')*10 + (ch[20]-'0');
        
    }
    bubbleSort2(arr1,n);
     
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
        fprintf(f2,"%d  ",(arr1[i].day));
        fprintf(f2,"%d:",(arr1[i].hour));
        fprintf(f2,"%d:",(arr1[i].min));
        fprintf(f2,"%d\n",(arr1[i].sec));
    }
   
    
    
}
void bubbleSortingdatestimes()
{
    FILE *f1;
    FILE* f2;
    f2 = fopen("bdt10k.txt","w");
    f1 = fopen("dt10k.txt","r");
    bubblesortdatetime(f1,f2,10000);
    fclose(f1);
    fclose(f2);
    f2 = fopen("bdt20k.txt","w");
    f1 = fopen("dt20k.txt","r");
    bubblesortdatetime(f1,f2,20000);
    fclose(f1);
    fclose(f2);
    f2 = fopen("bdt40k.txt","w");
    f1 = fopen("dt40k.txt","r");
    bubblesortdatetime(f1,f2,40000);
    fclose(f1);
    fclose(f2);
    f2 = fopen("bdt80k.txt","w");
    f1 = fopen("dt80k.txt","r");
    bubblesortdatetime(f1,f2,80000);
    fclose(f1);
    fclose(f2);
    f2 = fopen("bdt160k.txt","w");
    f1 = fopen("dt160k.txt","r");
    bubblesortdatetime(f1,f2,160000);
    fclose(f1);
    fclose(f2);

    // f2 = fopen("bdt320k.txt","w");
    // f1 = fopen("dt320k.txt","w");
    // bubblesortdatetime(f1,f2,320000);
    // fclose(f1);
    // fclose(f2);
    
    // f2 = fopen("bdt640k.txt","w");
    // f1 = fopen("dt640k.txt","w");
    // bubblesortdatetime(f1,f2,640000);
    // fclose(f1);
    // fclose(f2);
    
    // f2 = fopen("bdt1280k.txt","w");
    // f1 = fopen("dt1280k.txt","w");
    // bubblesortdatetime(f1,f2,1280000);
    // fclose(f1);
    // fclose(f2);
    
    // f2 = fopen("bdt2560k.txt","w");
    // f1 = fopen("dt2560k.txt","w");
    // bubblesortdatetime(f1,f2,2560000);
    // fclose(f1);
    // fclose(f2);
    
    // f2 = fopen("bdt5120k.txt","w");
    // f1 = fopen("dt5120k.txt","w");
    // bubblesortdatetime(f1,f2,5120000);
    // fclose(f1);
    // fclose(f2);
}
void main(){
    // randgenerate1(); //can be used to print random numbers
    // randgenerate2(); //random dates
     randgenerate3();    //random date & time
    // bubblesortingintegers();  //to sort all integer files
    // quicksortingintegers(); //to soert all integer files
    // quicksortingdates();

    // bubbleSortingdates();
    bubbleSortingdatestimes();
 }
