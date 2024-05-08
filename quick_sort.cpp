#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include<algorithm>
#include <vector>
int pivote(int arr[],int low,int high){
    int pivot = arr[high];
    int i =low-1;
    for(int j =low;j<=high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void QuickSort(int arr[],int low,int high){
    if(low<high){
        int pi = pivote(arr,low,high);
        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);
    }
}
int main(){
    int n;
    cout<<"Entre the size of array you want to sort:";
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        int temp;
        cout<<"Entre the "<<i<<"th element:" ;
        cin>>temp;
        arr[i]= temp;
    }
    // int arr[] = {5,2,3,8,7,9,0};
    // int n = sizeof(arr)/sizeof(arr[0]);
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(arr[0])<<endl;
    QuickSort(arr,0,n-1);
    cout<<"Sorted Array:";
    for(int  i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}