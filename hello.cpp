#include <iostream>

using namespace std;

void swap(int*a ,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int  partition(int nums[],int low ,int high)
{
    int pivot=nums[high];
    int i=low-1;
    for(int j=low;i<high;i++)
    {
        if(nums[j]<pivot)
        {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }
    i++;
    swap(&nums[i], &nums[high]);
    return i;
}
void quicksort(int nums[],int low , int high) 
{
    if(low<high)
    {
        int mid=partition(nums,low,high);
        quicksort(nums,low,mid-1);
        quicksort(nums,mid+1,high);
    }
}
int main()
{
    
    int nums[10]={1,3,4,2,5,6,8,10,9};

    quicksort(nums,0,9);
    for(int i=0;i<9;i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}