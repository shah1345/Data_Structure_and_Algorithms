#include<stdio.h>
#include<stdlib.h>


#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * list;

void initializeList()
{
    list = 0;  //initially set to NULL
}

int insertItem(int item) //insert at the beginning of the linked list
{
    struct listNode * newNode ;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
    newNode->item = item ;
    newNode->next = list ; //point to previous first node
    list = newNode ; //set list to point to newnode as this is now the first node
    return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
    struct listNode *temp, *prev ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) break ;
        prev = temp;
        temp = temp->next ; //move to next node
    }
    if (temp == 0) return NULL_VALUE ; //item not found to delete
    if (temp == list) //delete the first node
    {
        list = list->next ;
        free(temp) ;
    }
    else
    {
        prev->next = temp->next ;
        free(temp);
    }
    return SUCCESS_VALUE ;
}


struct listNode * searchItem(int item)
{
    struct listNode * temp ;
    temp = list ; //start at the beginning
    while (temp != 0)
    {
        if (temp->item == item) return temp ;
        temp = temp->next ; //move to next node
    }
    return 0 ; //0 means invalid pointer in C, also called NULL value in C
}

void printList()
{
    struct listNode * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}







int insertLast(int item)
{


    struct listNode * newNode, *Temp;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;

    Temp=list;
    newNode->item = item;
    newNode->next = NULL;
    //if newNode is NULL, it is an empty list

    if(newNode == NULL)
    {
        newNode = newNode;
    }
    //Otherwise, find the last node and add the newNode
    else
    {
        //last node's next address will be NULL.
        while(Temp->next != NULL && Temp != NULL)
        {
            Temp = Temp->next;
        }

        //add the newNode at the end of the linked list
        Temp->next = newNode;

        return SUCCESS_VALUE ;
    }

return 0;

    //write your codes here
}

int insertBefore(int oldItem, int newItem)
{

    struct listNode * newNode ,*temp, *position;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;

printList();
if(newNode == NULL)
    {
       newNode=newNode;
    }
    else
    {
        newNode->item = newItem; // Link data part
        newNode->next = NULL;

        temp = list;
        position=list;

        /*
         * Traverse to the n-1 position
         */
         int P=0;
             while(position!=0){
                   if(position->item != oldItem) {
                    P++;

                   } else break;


        position = position->next;
    }





        for(int i=2; i<=P; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            /* Link address part of new node */
            newNode->next = temp->next;

            /* Link address part of n-1 node */
            temp->next = newNode;
printList();
printf("DATA INSERTED SUCCESSFULLY\n");

        }
        else
        {
printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }


    }


    return SUCCESS_VALUE ;
    //write your codes here
}

int deleteAfter(int item)
{

        struct listNode *Temp, *secondLastNode, *position,*toDelete, *prevNode;


    Temp=list;
 position=list;
    secondLastNode = list;



             int P=1;
             while(position!=0){
                    Count++;
                   if(position->item != item) {
                    P++;

                   } else break;

        printf("%d\n", P);
        position = position->next;
    }



int i;


    if(Temp == NULL)
    {
        printf("List is already empty.");
    }
    else
    {


        toDelete = Temp;
        prevNode = Temp;

        for(i=2; i<=P+1; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == Temp)
                Temp = Temp->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;

            /* Delete nth node */
            free(toDelete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to delete.");
        }



    }








    //write your codes here
}

int deleteLast()
{


    struct listNode * newNode, *Temp, *secondLastNode;
    newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;

    Temp=list;

    secondLastNode = list;


    //last node's next address will be NULL.
    while(Temp->next != NULL && Temp != NULL)
    {
        secondLastNode=Temp;
        Temp = Temp->next;
    }

            if(Temp == list)
        {
            list = NULL;
        }
        else
        {
            /* Disconnect link of second last node with last node */
            secondLastNode->next = NULL;
        }

        /* Delete the last node */
        free(Temp);


    return SUCCESS_VALUE ;

    //write your codes here
}



int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. insertLast. 5. Print. 6. exit.\n");
        printf("7. insertBefore. 8. deleteAfter. 9. deleteLast.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            insertLast(item);

        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==7)
        {

            int oldItem,newItem;
            scanf("%d%d", &oldItem,&newItem);
            insertBefore(oldItem,newItem);
            printf("%d%d",oldItem,newItem);

        }
        else if(ch==8)
        {
            int item;
            scanf("%d", &item);
            deleteAfter(item);




        }
        else if(ch==9)
        {

            deleteLast();
        }



        else if(ch==6)
        {
            break;
        }
    }

}
