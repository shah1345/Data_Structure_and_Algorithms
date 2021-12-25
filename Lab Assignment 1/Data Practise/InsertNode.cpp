#include<stdio.h>
#include<stdlib.h>



struct listNode{
int item;
struct listNode * node;
};


struct listNode * list;
 listNode * temp= new listNode();

int main(){



for(int i=0; i<10;i++){
        listNode * newItem = new listNode();
   newItem->item = i+10;

   if(list==NULL){
    list = newItem;
    continue;
   }

   newItem->node=list;
   list= newItem;

}



temp=list;
while(temp!=0){

    printf("%d->",temp->item);

    temp = temp->node;

}







}
