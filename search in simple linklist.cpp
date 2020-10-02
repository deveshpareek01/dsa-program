#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int info;
    struct node *link;
};
struct node *start,*last,*temp,*new_node;
void create()
{
    int value,choice;
    do
    {
        struct node *new_node=(struct node*)malloc(sizeof(struct node));
        printf("enter value : ");
        scanf("%d",&value);
        if(start==NULL)
        {
            new_node->info=value;
            start=new_node;
            last=new_node;
        }
        else
        {
            new_node->info=value;
            last->link=new_node;
            last=new_node;
            last->link=NULL;
        }
        printf("want to add more 1/0");
        scanf("%d",&choice);
    }
    while(choice==1);
}
void display()
{
    printf("your linklist : ");
    temp=start;
    while(temp->link!=NULL)
    {
        printf("%d->",temp->info);
        temp=temp->link;
    }
    printf("%d->",temp->info);
    printf("NULL");
}
bool search(struct node* start, int x)
{
    struct node* current = start;  // Initialize current
    while (current != NULL)
    {
        if (current->info == x)
            return true;
        current = current->link;
    }
    return false;
}
int main()
{
    int item;
    create();
    display();
    printf("\nEnter item for search\n");
    scanf("%d",&item);
    search(start, item)? printf("Yes there is element") : printf("No element found");
    return 0;
}
