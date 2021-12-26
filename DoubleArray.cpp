#include <iostream>
using namespace std;



void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}








int main(){

int Array[] = {10,20,30,50,4,58,6};

 int len = sizeof(Array)/sizeof(Array[0]);
 cout << "Before Sort" << endl;


  for(int i=0;i<len;i++){
    cout << Array[i] << " ";


 }
 cout << endl;

bubble_sort(Array,len);
 cout << "After Sort" << endl;

   for(int i=0;i<len;i++){
    cout << Array[i] << " ";


 } cout << endl;


 cout << "The smallest Number : " << Array[0]<< endl;
 cout << "The largest  Number : " << Array[len-1]<< endl;

 for(int i=0;i<len;i++){
    Array[i]= Array[i] *2;

    cout << Array[i] << " ";
 }




//cout << len ;

return 0;
}
