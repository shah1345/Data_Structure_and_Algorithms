#include<iostream>

using namespace std;

int LinearSearch(int array[],int n, int value){
    for(int i=0;i<n;i++){
        if(array[i] == value){
            return i;
        }
    }
    return -1;
}

int BinarySearchLoop(int array[], int n,int value){
    int low=0;
    int high=n-1;
    int mid;
    while(low <= high){
        mid = low + (high-low)/2;
        if(array[mid]==value){
            return mid;
        }
        else if(value > array[mid]){
            low = mid + 1;
        }
        else if(value < array[mid]){
            high = mid -1;
        }
    }
    return -1;
}

int BinarySearchRecursive(int array[], int n, int value, int low, int high){
    if(low<=high){
        int mid = low + (high-low)/2;
        if(array[mid] == value){
            return mid;
        }
        else if(value > array[mid]){
            return BinarySearchRecursive(array,n,value, mid+1,high);
        }
        else{
            return BinarySearchRecursive(array,n,value,low,mid-1);
        }
    }
    return -1;
}

int LinearSearch2(int array[], int n,int value){
    for(int i=n-1;i>=0;i--){
        if(array[i] == value){
            return i;
        }
    }
    return -1;
}
int main(){
    int array[] = {1,2,4,5,9,10,11,14,50,57,68,91,101,200,400,501,603};
    int value = 2;
    int size = sizeof(array)/sizeof(int);
    int index = BinarySearchRecursive(array,size,value,0,size-1);
    cout<<index<<endl;
    if(index == -1){
        cout<<"Not Found";
    }
    else{
        cout<<"Found";
    }
    return 0;
}
