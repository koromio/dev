#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct address
{
    char name[30];
    char street[40];
    char city[20];
    char state[10];
    char zip[6];
    struct address *next;
} list_entry;
void inputs(const char *, char *, int);
void dls_store(struct address *);
void display(struct address *top);
int main()
{
    struct address *info;
    info = (struct address *)malloc(sizeof(list_entry));
    struct address *start=info;
    int i;
    for (i = 0; i < 5; i++)
    {
        inputs("enter name:",info->name,30);
        inputs("enter street:",info->street,40);
        inputs("enter city:",info->city,20);
        inputs("enter state:",info->state,10);
        inputs("enter zip:",info->zip,6);
        dls_store(info);
        info = (struct address *)malloc(sizeof(list_entry));
    }
    display(start);
}
void inputs(const char *prompt,char *s,int count)
{
    char p[255];
    do
    {
        printf("%s",prompt);
        gets(p);
        if(strlen(p)>count) printf("too long\n");
    }
    while (strlen(p)>count);
    strcpy(s,p);
}
void dls_store(struct address *in)
{
    static struct address *last=NULL;
    if(!last) last=in;
    else last->next=in;
    in->next=NULL;
    last=in;
}
void display(struct address *top)
{
    while(top)
    {
        printf(top->name);
        top=top->next;
    }
}