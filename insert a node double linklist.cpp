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
void insert()
{
    int choice,pos,item,i;
    printf("***choice***\n1.insert at beg\n2. insert at end\n3. insert at specfic postion\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("enter element : ");
        scanf("%d",&item);
        new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node==NULL)
        {
            printf("out of memory\n");
            exit(1);
        }
        new_node->info=item;
        new_node->pre=NULL;
        new_node->next=start;
        start->pre=new_node;
        start=new_node;
        break;
        case 2:
        printf("enter element : ");
        scanf("%d",&item);
        new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node==NULL)
        {
            printf("out of memory\n");
            exit(1);
        }
        new_node->info=item;
        new_node->next=NULL;
        new_node->pre=last;
        last->next=new_node;
        last=new_node;
        break;
        case 3:
        printf("enter element  and positon: ");
        scanf("%d%d",&item,&pos);
        new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node==NULL)
        {
            printf("out of memory\n");
            exit(1);
        }
        new_node->info=item;
        temp=start;
        for(i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        new_node->next=temp->next;
        temp->next->pre=new_node;
        temp->next=new_node;
        new_node->pre=temp;
        break;
        default:
        printf("wrong choice");
        break;
    }
}
int main()
{
    create();
    display();
    printf("\n");
    insert();
    display();
}
