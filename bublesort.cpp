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
