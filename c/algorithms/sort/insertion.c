#include<stdio.h>
void *INSERTIONSORT(int *A,int n);
int main()
{
    int a[5]={5,4,3,2,1};
    int *p=INSERTIONSORT(a,5);
    for(int i=0;i<5;i++) printf("%d",a[i]);   
}
void *INSERTIONSORT(int *A,int n)
{
    for(int i=1;i<n;i++)
    {
        int key=A[i];
        int j=i-1;
        while(j>=0&&A[j]>key)
        {
            A[j+1]=A[j];
            j=j-1;
            A[j+1]=key;
        }
    }
}