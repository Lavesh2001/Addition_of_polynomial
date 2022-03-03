#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    int power;
    struct node *next;
}node;
void insert(node **head,int val,int p)
{
    node *newnode,*temp=*head;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->power=p;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void sort_list(node **head)
{
    node *temp=*head,*ptr=NULL;
    int num,p;
    while(temp->next!=NULL)
    {   
        ptr=temp->next;
        while(ptr!=NULL)
        {
            if((temp->power)>(ptr->power))
            {
                num=temp->data;
                p=temp->power;
                temp->data=ptr->data;
                temp->power=ptr->power;
                ptr->data=num;
                ptr->power=p;
            }
            ptr=ptr->next;
        }
        temp=temp->next;
    }
}
void display(node *head)
{   
    if(head==NULL)
    printf("list is empty \n");
    else
    {
    printf("polynomial is: ");
    while(head->next!=NULL)
    {
        printf("%d x^%d+ ",head->data,head->power);
        head=head->next;
    }
    printf("%d x^%d ",head->data,head->power);
    printf("\n");
    }
}
void add(node **head1,node **head2,node **head3)
{
    node *a=*head1,*b=*head2,*newnode,*temp=NULL;
    while(a!=NULL && b!=NULL)
    {  
     newnode=(node*)malloc(sizeof(node));
     newnode->next=NULL;
    if((a->power)==(b->power))
    {   
        newnode->data=(a->data)+(b->data);
        newnode->power=(a->power);
        if(*head3==NULL)
        {
            *head3=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        a=a->next;
        b=b->next;
    }
    else if((a->power)>(b->power))
    {   
        newnode->data=a->data;
        newnode->power=a->power;
        if(*head3==NULL)
        {
            *head3=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        } 
        a=a->next;
    }
    else
    {
        newnode->data=b->data;
        newnode->power=b->power;
        if(*head3==NULL)
        {
            *head3=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        b=b->next;
    }
    
    }
    while(a!=NULL)
    {
        newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        newnode->data=a->data;
        newnode->power=a->power;
        if(*head3==NULL)
        {
            *head3=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        a=a->next;
    }
    while(b!=NULL)
    {
        newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        newnode->data=b->data;
        newnode->power=b->power;
        if(*head3==NULL)
        {
            *head3=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        b=b->next;
    }
}
int main()
{
    int c,val,p;
    node *head1=NULL,*head2=NULL,*head3=NULL;
    printf("1-insert in list 1\n2-insert in list 2\n3-display list 1\n4-display list 2\n5-dispaly list 3\n");
    printf("6-sort list 1\n7-sort list 2\n8-add two polynomial\n9-exit\n");
    do
    {
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("enter the coefficient and its power: ");
            scanf("%d",&val);
            scanf("%d",&p);
            insert(&head1,val,p);
            break;
            case 2:printf("enter the data and its power: ");
            scanf("%d",&val);
            scanf("%d",&p);
            insert(&head2,val,p);
            break;
            case 3:display(head1);
            break;
            case 4:display(head2);
            break;
            case 5:display(head3);
            break;
            case 6:sort_list(&head1);
            break;
            case 7:sort_list(&head2);
            break;
            case  8:add(&head1,&head2,&head3);
            break;
            case 9:break;
            default :printf("invalid choice\n");
        }
    }while(c!=9);
    
    return 0;
    
}




