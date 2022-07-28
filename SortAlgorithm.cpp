#include <iostream>
#include <vector>


using namespace std;

template<typename T>
void Swap(T&a,T&b)
{
    T temp=a;
    a=b;
    b=temp;
}


template<typename T>
void BubbleSort(vector<T>& arr) //O(n^2)
{
   
   for(int i=0;i<arr.size();i++)
   {
    for(int j=i+1;j<arr.size();j++)
    {
        if(arr[j]<arr[i])
        {
            Swap(arr[i],arr[j]);
        }
    }
   }
    /*for(int i=arr.size()-1;i>0;i--)
    {
        bool swaped=false;
        for(int j=0;j<i;j++)
        {
          if(arr[j+1]<arr[j])
          {
            Swap(arr[j],arr[j+1]);
            swaped=true;
          }  
        }
        if(!swaped) false;
    }*/
}

template<typename T>
void SelectionSort(vector<T>& arr) //O(n^2)
{
    
    for(int i=0;i<arr.size();i++)
    {
        int min=i;
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[j]<arr[min])
            min=j;
        }
        if(min!=i)
            Swap(arr[min],arr[i]);
    }
}

template<typename T>
void InsertionSort(vector<T>& arr)//Best O(n) Worst O(n^2)
{
    for(int i=1;i<arr.size();i++)
    {
        int key=arr[i];
        int j=i-1;
        cout<<"Key: "<<key<<endl;
        while(key<arr[j]&&j>=0)
        {
            arr[j+1]=arr[j];
            --j;
            for(auto &i:arr)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        arr[j+1]=key;
        for(auto &i:arr)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        
    }
}

template<typename T>
void Merge(vector<T>& arr,int left,int right, int middle)
{
    
    int n1=middle-left+1;
    int n2=right-middle;

    vector<int>L;
    vector<int>R;
    
    for(int i=0;i<n1;i++)
        L.push_back(arr[i+left]);
    
   
    for(int i=0;i<n2;i++)
       R.push_back(arr[i+middle+1]);

    int i=0;
    int j=0;
    int k=left;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];          
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
        arr[k++]=L[i++];
    while(j<n2)
        arr[k++]=R[j++];
}
template<typename T>
void MergeSort(vector<T>& arr,int left,int right)
{
   if(left<right)
   {
    int middle=(left+right)/2;
   
    MergeSort(arr,left,middle);
    MergeSort(arr,middle+1,right);
    Merge(arr,left,right,middle);
   }
    
    
}


template<typename T>
void Print(const vector<T>& arr)
{   
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    cout<<endl<<endl;
}


int main()
{
    vector<int> arr={2,3,1,5,6,9,4};
    int arr1[]={2,3,1,5,6,9,4};
    Print(arr);
    //BubbleSort(arr);
    //SelectionSort(arr);
    //InsertionSort(arr);
    MergeSort(arr,0,arr.size()-1);
    

    cout<<endl;
    Print(arr);

    return 0;
}