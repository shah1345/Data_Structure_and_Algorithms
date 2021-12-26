#include<iostream>
using namespace std;

void bubbleSort(char array[], int size){
    for(int step = 0; step< size-1; step++){
        for(int i=0; i< size-step-1; i++){
            if(array[i] < array[i+1]){
                /*
                array[i] = array[i]  ^ array[i+1];
                array[i+1] = array[i] ^ array[i+1];
                array[i] = array[i] ^ array[i+1];
                */
                /*
                array[i] = array[i]  + array[i+1];
                array[i+1] = array[i] - array[i+1];
                array[i] = array[i] - array[i+1];
                */

                char temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
}

void printArray(char array[], int size){
    for(int i=0; i<size; i++){
        cout << array[i] << ", ";
    }
    cout<<endl;
}


int main(){
    char array[] = {'x', 'Z', 'y', 'A', 'm'};
    int length = sizeof(array)/sizeof(char);
    cout<<"Before Sorting : "<<endl;
    printArray(array, length);

    bubbleSort(array, length);

    cout<<"After Sorting : "<<endl;
    printArray(array, length);
    cout<<endl;
}



#include <iostream>

using namespace std;
void swap(int*,int*);


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
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"enter the size of the array:"<<endl;
    cin>>n;
    int array_of_numbers[n];
    cout<<"enter the elements of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>array_of_numbers[i];
    }
    cout<<"array as it was entered:"<<endl;
    display(array_of_numbers,n);
    bubble_sort(array_of_numbers,n);
    cout<<"array after bubble sort:"<<endl;
    display(array_of_numbers,n);
    return 0;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}





