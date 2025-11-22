#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int prime(int n);

int main()
{
    int n=2,count=0;
    FILE *fp;

    if((fp = fopen("prime.txt","w"))==NULL){
        printf("Error: Cannot open file 'prime.txt'. Please make sure the file exists.\n");
        return 1;
    }

    while(count < 100)
    {
        if(prime(n))
        {
            fprintf(fp,"%d\n",n);
            count++;
        }
        n++;
    }
    fclose(fp);
    return 0;
}

int prime(int n)
{
    if(n<=1) return 0;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}