#include<bits/stdc++.h>
using namespace std;

// Naive solution
int count(int arr[], int n){
    for(int i = 0; i<n; i++){
        if(arr[i]==1)
            return (n-i);
    }
    return 0;
}
// using binary search
int count1(int arr[], int n){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==0){
            low = mid+1;
        }
        else{
            if(mid==0 || arr[mid-1]==0){
                return (n-mid);
            }
            else{
                high=mid-1;
            }
        }
    }
    return 0;
}
int main(){
    // count the number of 1s in a sorted binary array
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<count(arr, n)<<"\n";
    cout<<count1(arr, n)<<"\n";
    return 0;
}