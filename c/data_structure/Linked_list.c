#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stud_node
{
    int num;
    char name[20];
    int score;
    struct stud_node *next;
};
struct stud_node *Create_Stu_Doc();
struct stud_node *Insert_Doc(struct stud_node *head, struct stud_node *stud);
struct stud_node *Delete_Doc(struct stud_node *head, int num);
void Print_Doc(struct stud_node *head);

int main()
{
    struct stud_node *head, *p;
    int choice, num, score;
    char name[20];
    int size = sizeof(struct stud_node);

    do
    {
        printf("1. Create 2. Insert 3. Delete 4. Print 0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = Create_Stu_Doc();
            printf("Student document created successfully.\n");
            break;
        case 2:
            printf("Enter student number,name and score: ");
            scanf("%d %s %d", &num, name, &score);
            p = (struct stud_node *)malloc(size);
            if (p == NULL)
            {
                printf("Memory allocation failed.\n");
                exit(1);
            }
            p->num = num;
            strcpy(p->name, name);
            p->next = NULL;
            head = Insert_Doc(head, p);
            printf("Student inserted successfully.\n");
            break;
        case 3:
            printf("Enter student number to delete: ");
            scanf("%d", &num);
            head = Delete_Doc(head, num);
            break;
        case 4:
            Print_Doc(head);
            break;
        }
    } while (choice != 0);
}

struct stud_node *Create_Stu_Doc()
{
    struct stud_node *head = NULL, *p;
    int num, score;
    char name[20];
    int size = sizeof(struct stud_node);

    head = NULL;
    printf("Input student information (number name score):\n");
    while (num != 0)
    {
        p = (struct stud_node *)malloc(size);
        printf("Number: ");
        scanf("%d", &num);
        p->num = num;
        printf("Name: ");
        scanf("%s", name);
        strcpy(p->name, name);
        printf("Score: ");
        scanf("%d", &score);
        p->score = score;
        head = Insert_Doc(head, p);
    }
    return head;
}

struct stud_node *Insert_Doc(struct stud_node *head, struct stud_node *stud)
{
    struct stud_node *ptr, *ptr1, *ptr2;

    ptr2 = head;
    ptr = stud;
    if (head == NULL)
    {
        head = ptr;
        head->next = NULL;
    }
    else
    {
        while ((ptr->num > ptr2->num) && (ptr2->next != NULL))
        {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        if (ptr->num <= ptr2->num)
        {
            if (head == ptr2)
                head = ptr;
            else
                ptr1->next = ptr;
            ptr->next = ptr2;
        }
        else
        {
            ptr2->next = ptr;
            ptr->next = NULL;
        }
    }
    return head;
}

struct stud_node *Delete_Doc(struct stud_node *head, int num)
{
    struct stud_node *ptr1, *ptr2;

    while (head != NULL && head->num == num)
    {
        ptr2 = head;
        head = head->next;
        free(ptr2);
    }
    if (head == NULL)
        return NULL;
    ptr1 = head;
    ptr2 = head->next;
    while (ptr2 != NULL)
    {
        if (ptr2->num == num)
        {
            ptr1->next = ptr2->next;
            free(ptr2);
        }
        else
            ptr1 = ptr2;
        ptr2 = ptr1->next;
    }
    return head;
}

void Print_Doc(struct stud_node *head)
{
    struct stud_node *ptr = head;
    if (ptr == NULL)
    {
        printf("No student information available.\n");
        return;
    }
    printf("Student Information:\n");
    while (ptr != NULL)
    {
        printf("Number: %d, Name: %s, Score: %d\n", ptr->num, ptr->name, ptr->score);
        ptr = ptr->next;
    }
}