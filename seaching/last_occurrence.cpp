#include<bits/stdc++.h>
using namespace std;

// Naive solution
int last_occ1(int arr[], int n, int x){
    for(int i = n-1; i>=0; i--){
        if(arr[i]==x)
            return i;
    }
    return -1;
}
// recursive approach
int last_occ2(int arr[], int i, int x){
    if(i==-1)
        return -1;
    if(arr[i]==x)
        return i;
    else
        return last_occ2(arr,i-1,x);
}

// using binary search(recursive)
int last_occ3(int arr[],int n, int low, int high, int x){
    if(low>high)
        return -1;
    int mid = (low+high)/2;
    if(arr[mid]>x)
        return last_occ3(arr,n,low,mid-1,x);
    else if(arr[mid]<x)
        return last_occ3(arr,n,mid+1,high,x);
    else{
        if(mid==n-1 || arr[mid]!=arr[mid+1])
            return mid;
        else    
            return last_occ3(arr,n,mid+1,high,x);
    }
}
// using binary search iterative(best approach)
int last_occ4(int arr[], int n, int x){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>x)
            high = mid -1;
        else if(arr[mid]<x)
            low = mid + 1;
        else{
            if(mid==n-1 || arr[mid]!=arr[mid+1])
                return mid;
            else    
                low = mid+1;
        }
    }
    return -1;
}
int main(){
    // Find the last occurrence of an element in ana sorted array
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    cout<<last_occ1(arr, n, x)<<"\n";
    cout<<last_occ2(arr,n-1,x)<<"\n";
    cout<<last_occ3(arr,n,0,n-1,x)<<"\n";
    cout<<last_occ4(arr,n,x)<<"\n";

    return 0;
}