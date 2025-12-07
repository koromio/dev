#include<stdio.h>
#include<stdlib.h>
void push(int);
int pop();
int *pi,*tos;

int main()
{
    int v;
    pi=(int *)malloc(50*sizeof(int));
    if(!pi)
    {
        printf("allocation failure\n");
        exit(0);
    }
    tos=pi;
    do
    {
        printf("please input value,push it;enter 0 then pop;(enter -1 then stop)\n");
        scanf("%d",&v);
        if(v!=0)push(v);
        else printf("pop this is it %d\n",pop());
    } while (v!=-1);
}
void push(int i)
{
    pi++;
    if(pi==(tos+50))
    {
        printf("stack overflon\n");
        exit(0);
    }
    *pi=i;
}
int pop()
{
    if(pi==tos)
    {
        printf("stack underflow");
        exit(0);
    }
    pi--;
    return *(pi+1);
}