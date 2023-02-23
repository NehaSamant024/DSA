#include<iostream>
using namespace std;
int binarySearch(int arr[],int size,int key)
{
    int low=0;
    int high=size-1;
    int mid=(low+high)/2;
    //int mid=low+(high-low)/2;
    while(low<=high)
    {
        if(arr[mid]==key)
        {
            return mid;
        }
        if(arr[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        mid=(low+high)/2;
        //int mid=low+(high-low)/2;
    }return -1;
}
int main(){
    int key;
int arr[]={2,3,4,5,7,8,9,10};
//////cout<<"enter key\n";
//cin>>key;
int index=binarySearch(arr,8,10);
cout<<"key found at the index"<<index;
return 0;
}
