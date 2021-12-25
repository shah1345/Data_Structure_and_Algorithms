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
struct listNode * tail;

void initializeList()
{
    list = NULL;  //initially set to NULL
    tail = NULL;
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

//add required codes to insert item at the beginning, remember to properly set the tail pointer!
int insertItem(int newItem)
{
    //write your codes here

    listNode * newitem = new listNode();
    newitem->item = newItem;
    if(list == NULL)
    {
        list = newitem;
        tail = newitem;
        tail->next = NULL;
        return SUCCESS_VALUE;
    }
    newitem->next = list;
    list = newitem;
    return SUCCESS_VALUE;



}

//add required codes to delete item, remember to properly set the tail pointer!
int deleteAfter(int item)
{

    if(list == NULL)
    {
        printf("List is empty");

        return NULL_VALUE;
    }
    if(list->item == item && list ->next == NULL)
    {
          printf("No node exist after your input");

        return NULL_VALUE;
    }
    if(list->next == tail && tail->item == item)
    {
        printf("Error");
        listNode * del = tail;
        tail = list;
        delete del;
        return SUCCESS_VALUE;
    }
    listNode * cur = list;
    while(cur->item != item && cur->next != NULL)
    {
        cur = cur->next;
    }
    if(cur->item != item && cur==tail)
    {
        printf("input index not found");
        return NULL_VALUE;
    }
    if(cur->item == item && cur==tail)
    {
         printf("No node exist after your input");

        return NULL_VALUE;
    }
    listNode * del = cur->next;
    cur->next = del->next;
    delete del;
    return SUCCESS_VALUE;

}

int insertLast(int item)
{
    //write your codes here

    listNode * newItem = new listNode();
    newItem->item = item;
    if(list == NULL)
    {
        list = newItem;
        tail = newItem;
        tail->next = NULL;
        return SUCCESS_VALUE;
    }
    tail->next = newItem;
    tail = newItem;
    return SUCCESS_VALUE;


}

int deleteBefore(int item)
{
    if(list == NULL)
    {
        printf("List is empty");

        return NULL_VALUE;
    }
    if(list == tail)
    {
          printf("No node exist before this value");

        return NULL_VALUE;
    }
    if(list->next == tail && tail->item==item)
    {
        listNode * del = list;
        list = tail;
        delete del;
        return SUCCESS_VALUE;
    }
    listNode * prevOld = NULL;
    listNode * prev = NULL;
    listNode * cur = list;

    int check = 1;
    while(cur->item != item && cur->next!=NULL)
    {
        if(check > 1)
        {
            prevOld = prev;
        }
        prev = cur;
        cur = cur->next;
        check += 1;
    }
    if(cur->item != item && cur->next == NULL)
    {
        printf("Your input does not exist");

        return NULL_VALUE;
    }
    delete prev;
    prevOld->next = cur;
    return SUCCESS_VALUE;

}







int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete before. 3. Search item. \n");
        printf("4. Delete after. 5. Print. 6. exit. 7. Insert last.\n");

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
            deleteBefore(item);
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
            int input;
            scanf("%d", &input);
            deleteAfter(input);
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            break;
        }
        else if(ch==7)
        {
            int input;
            scanf("%d", &input);
            insertLast(input);
        }
    }

}
