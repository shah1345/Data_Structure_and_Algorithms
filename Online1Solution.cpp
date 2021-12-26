#include<iostream>

using namespace std;

void bubbleSort(int array[], int n)
{
    for(int step = 0; step< n-1; step++)
    {
        for(int i=0; i< n-step-1; i++)
        {
            if(array[i] < array[i+1])
            {
                char temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
}

bool binarySearch(int array[], int n, int value, int low, int high)
{
    if(low<=high)
    {
        int mid = low + (high-low)/2;
        if(array[mid] == value || array[low]==value || array[high]==value)
        {
            return true;
        }
        else if(value > array[mid])
        {
            return binarySearch(array,n,value, mid+1 ,high);
        }
        else
        {
            return binarySearch(array,n,value,low,mid-1);
        }
    }
    return false;
}

void problem1To4(int array[], int n, int problem)
{
    bubbleSort(array,n);
    if(problem == 1)
    {
        cout<<array[n-1]<<", "<<array[n-2]<<", "<<array[n-3]<<endl;
    }
    else if(problem == 2)
    {
        cout<<array[0]<<", "<<array[n-1]<<endl;
    }
    else if(problem == 3)
    {
        cout<<array[2]<<", "<<array[1]<<", "<<array[0]<<endl;
    }
    else
    {
        cout<<array[n-1]<<", "<<array[n-2]<<endl;
    }
}

void problem5(int array[], int n, int sum)
{
    bubbleSort(array,n);
    for(int i=0; i<n-1; i++)
    {
        if(binarySearch(array,n,sum-array[i],i+1,n-1))
        {
            cout<<array[i]<<" , "<<sum-array[i]<<endl;
            break;
        }
    }
}

int main()
{
    int problem, n,sum;
    while(true)
    {
        cin>>problem;
        if(problem == 5)
        {
            cin>>n;
            int array2[n];
            for(int i=0; i<n; i++)
            {
                cin>>array2[i];
            }
            cin>>sum;
            problem5(array2, n, sum);
        }
        else
        {
            cin>>n;
            int array1[n];
            for(int i=0; i<n; i++)
            {
                cin>>array1[i];
            }
            problem1To4(array1, n, problem);
        }



    }
    return 0;
}
