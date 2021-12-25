#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
    struct listNode * prev;
};

struct listNode * list;

struct listNode * tail;

void initializeList()
{
    list = 0;  //initially set to NULL
    tail = 0;
}

int insertFirst(int item) //insert at the beginning
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;

	if(list==0) //inserting the first item
    {
        newNode->next = 0;
        newNode->prev = 0;
        list = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = list;
        list->prev = newNode;
        newNode->prev = 0;
        list = newNode;
    }
	return SUCCESS_VALUE ;
}


int deleteAfter(int item)
{
    //write your codes here
    if(list == NULL){
cout << "Empty list" << endl;
return NULL_VALUE;
}
if(list == tail){
cout << "Only one node is present" << endl;
return NULL_VALUE;
}
if(list->next == tail && list->item == item){
list->next = NULL;
delete tail;
tail = list;
return SUCCESS_VALUE;
}
listNode * cur = list;
while(cur->item != item && cur->next != NULL){
cur = cur->next;
}
if(cur->item != item && cur->next == NULL){
cout<< "Your input not found" << endl;
return NULL_VALUE;
}
if(cur->item == item && cur->next == NULL){
cout<< "No node exist after your input" << endl;
return NULL_VALUE;
}
if(cur->next == tail && cur->item == item){
tail = tail->prev;
delete tail->next;
tail->next = NULL;
return SUCCESS_VALUE;
}

listNode * del = cur->next;
cur->next = del->next;
del->next->prev = del->prev;

delete del;
return SUCCESS_VALUE;

}

int deleteLast()
{
    //write your codes here
if(list == NULL){
cout << "Empty list" << endl;
return NULL_VALUE;
}
if(list == tail){
int delValue = list->item;
delete list;
list = NULL;
tail = NULL;
return delValue;
}

tail = tail->prev;
int delValue = tail->next->item;
delete tail->next;
tail->next = NULL;
return delValue;
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

void printListForward()
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

void printListBackward()
{
	//will print the list backward starting from the tail position
if(list==NULL){
cout<<"Empty List" << endl;
}
listNode * cur = tail;
while(cur!=NULL){
cout << cur->item << "->" ;
cur = cur->prev;
}
cout << endl;

}


int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Delete item. 3. Search item. \n");
        printf("4. Print forward. 5. Print backward. 6. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertFirst(item);
        }
        else if(ch==2)
        {
            int item = deleteLast();
            if(item!=NULL_VALUE) printf("Deleted: %d\n", item);
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
            printListForward();
        }
        else if(ch==5)
        {
            printListBackward();
        }
        else if(ch==6)
        {
            break;
        }
    }

}
