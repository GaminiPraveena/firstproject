//single non circular linked list in DS
#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *header=NULL;
void add_beg();
void add_end();
void delete_beg();
void delete_end();
void display();
void reverse();
int main()
{
    int n;
    do
    {
        printf("\n1.add_beg\n2.add_end\n3.delete_beg\n4.delete_end\n5.display\n6.reverse\n7.exit\n");
        printf("enter function u want");
        scanf("%d",&n);
        switch(n)
            {
                case 1:add_beg();break;
                case 2:add_end();break;
                case 3:delete_beg();break;
                case 4:delete_end();break;
                case 5:display();break;
                case 6:reverse();break;
                default:printf("invalid");
        
            }
    }while(n!=7);
}
void add_beg()
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    int data;
    
    printf("Get a pull request");
        
    scanf("%d",&data);
    t->data=data;
    if(header==NULL)
    {
        header=t;
        t->link=NULL;
    }
    else
    {
        t->link=header;
        header=t;
    }
}
void display()
{
    struct node *ptr;
    ptr=header;
    if(header==NULL)
    {
        printf("no node");
    }
    else
    {
        printf("%d ",ptr->data);
        while(ptr->link!=NULL)
        {
            //printf("%d ",ptr->data);
            ptr=ptr->link;
            printf("%d ",ptr->data);
        }
    }
           
}
    

void add_end()
{
    struct node *ptr,*t;
    t=(struct node *)malloc(sizeof(struct node));
    int data;
    scanf("%d",&data);
    t->data=data;
    ptr=header;
    if(header==NULL)
    {
        header=t;
        t->link=NULL;
    }
    else
    {
        ptr=header;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=t;
        t->link=NULL;
    }
    
}
void delete_beg()
{
    struct node *ptr;
    ptr=header;
    if(header==NULL)
    {
        printf("no node to delete");
    }
    else
    {
        header=header->link;
        free(ptr);
    }
}
void delete_end()
{
    struct node *ptr,*ptr1;
    if(header==NULL)
    {
        printf("no node to delete");
    }
    else if(header->link==NULL)
    {
        ptr=header;
       // ptr=ptr->header;
        free(ptr);
        header=NULL;
    }
    else
    {
        ptr=header;
        while(ptr->link->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr1=ptr->link;
        free(ptr1);
        ptr->link=NULL;
    }
}

void reverse()
{
    struct node *prevnode,*currentnode,*nextnode;
    if(header==NULL)
    {
        printf("no node");
    }
    else
    {
        currentnode=nextnode=header;
        prevnode=0;
        while(nextnode!=0)
        {
            nextnode=nextnode->link;
            currentnode->link=prevnode;
            prevnode=currentnode;
            currentnode=nextnode;
        }
        header=prevnode;
    }
}






















