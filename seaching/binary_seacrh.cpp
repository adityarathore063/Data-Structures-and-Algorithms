#include<bits/stdc++.h>
using namespace std;

// Binary search Iterative
int bin_search(int arr[], int n, int x){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            high=mid-1;
        else
            low = mid+1;
    }
    return -1;
}
// Binary search recursive
int bin_search_rec(int arr[], int x, int low, int high){
    if(low>high)
        return-1;
    int  mid = (low + high)/2;

    if(arr[mid]==x)
        return mid;
    else if(arr[mid]>x){
        high = mid-1;
        return bin_search_rec(arr,x,low,high);
    }
    else{
        low = mid+1;
        return bin_search_rec(arr,x,low,high);
    }
}
int main(){

    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<bin_search(arr,n,x)<<"\n";
    cout<<bin_search_rec(arr,x,0,n-1)<<"\n";
    return 0;
}