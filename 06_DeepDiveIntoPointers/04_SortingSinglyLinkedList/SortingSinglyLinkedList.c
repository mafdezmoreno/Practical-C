/* Sort the linked list by bubble sort */
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next; //Pointer to the next node
};

void List_destroy(struct node * n);

void main()
{
    struct node *temp1,*temp2, *t,*newNode, *startList;
    int n,k,i,j;
    startList=NULL;
    printf("How many elements are there in the linked list?\n");
    scanf("%d",&n);
    //n = 2;
    printf("Enter elements in the linked list\n");
    for(i=1;i<=n;i++)
    {
        if(startList==NULL)
        {
            newNode=(struct node *)malloc(sizeof(struct node));
            scanf("%d",&newNode->data);
            //newNode->data = 1;
            newNode->next=NULL;
            startList = newNode;
            temp1=startList;
        }
        else
        {
            newNode=(struct node *)malloc(sizeof(struct node));
            scanf("%d",&newNode->data);
            //newNode->data = 2;
            newNode->next=NULL;
            temp1->next = newNode;
            temp1=newNode;
        }
    }
    for(i=n-2;i>=0;i--)
    {
        temp1=startList;
        temp2=temp1->next;
        for(j=0;j<=i;j++)
        {
            if(temp1->data > temp2->data)
            {
                k=temp1->data;
                temp1->data=temp2->data;
                temp2->data=k;
            }
            temp1=temp2;
            temp2=temp2->next;
        }
    }
    printf("Sorted order is: \n");
    t=startList;
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("\n");
    List_destroy(startList); //To freed the allocated memory
}


//https://stackoverflow.com/questions/29522264/correct-way-to-use-malloc-and-free-with-linked-lists
void List_destroy(struct node * n){
  
  if(n == NULL)
    return;
  List_destroy(n->next);
  //free(n->data); //It's generates a compilation error. The whole struct have to be freed
  free(n);
}