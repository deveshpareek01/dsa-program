#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    struct node *pre;
    int info;
    struct node *next;
}*new_node,*start,*last,*temp;
void create()
{
    int value,choice;
   do{
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter element : ");
    scanf("%d",&value);
    new_node->pre=NULL;
    new_node->info=value;
    new_node->next=NULL;
    if(start==NULL)
    {
        start=new_node;
        last=new_node;
    }
    else
    {
        last->next=new_node;
        new_node->pre=last;
        last=new_node;
    }
    printf("Wnat to add more for 1\0");
    scanf("%d",&choice);
   }while(choice);
}
void display()
{
    printf("your linklist in right direction : ");
    printf("NULL<->");
    temp=start;
    while(temp->next!=NULL)
    {
        printf("%d<->",temp->info);
        temp=temp->next;
    }
    printf("%d<->",temp->info);
    printf("NULL\n");
    printf("your linklist in left direction : ");
    printf("NULL<->");
    temp=last;
    while(temp->pre!=NULL)
    {
        printf("%d<->",temp->info);
        temp=temp->pre;
    }
    printf("%d<->",temp->info);
    printf("NULL");
}
void deletenode()
{
    int choice,pos,i;
    printf("***choice***\n1.delete at beg\n2. delete at end\n3. delete at specfic postion\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node==NULL)
        {
            printf("out of memory\n");
            exit(1);
        }
        temp=start;
        start=temp->link;
        temp->link=NULL;
        break;
        case 2:
        new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node==NULL)
        {
            printf("out of memory\n");
            exit(1);
        }
        temp=start;
        while(temp->link!=last)
        {
            temp=temp->link;
        }
        temp->link=NULL;
        last=temp;
        break;
        case 3:
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter postion : ");
        scanf("%d",&pos);
        if(new_node==NULL)
        {
            printf("out of memory\n");
            exit(1);
        }
        temp=start;
        for(i=0;i<pos-1;i++)
        {
            temp=temp->link;
        }
        temp=temp->link;
        temp->link=temp->link->link;
        break;
        default:
        printf("wrong choice\n ");
    }
}
int main()
{
    create();
    display();
}
