#include <bits/stdc++.h>
using namespace std;
// Iterative solution
int first_occ1(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
// Recursive solution
int first_occ(int arr[], int n, int i, int x)
{
    if (i == n)
        return -1;
    if (arr[i] == x)
        return i;
    else
        return first_occ(arr, n, i + 1, x);
}
// using recursive binary search
int first_occ2(int arr[], int low, int high, int x)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] > x)

        return first_occ2(arr, low, mid - 1, x);

    else if (arr[mid] < x)

        return first_occ2(arr, mid + 1, high, x);

    else
    {
        if (mid == 0 || arr[mid-1] != arr[mid])
            return mid;
        else
            return first_occ2(arr, low, mid - 1, x);
    }
}
// using iterative binary search(best approach)
int first_occ3(int arr[],int n, int x){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>x)
            high = mid-1;
        else if(arr[mid]<x)
            low = mid + 1;
        else{
            if(mid==0 || arr[mid-1]!=arr[mid])
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    // Find the index of first occurrence of a element in an array
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << first_occ1(arr, n, x) << "\n";
    cout << first_occ(arr, n, 0, x) << "\n";
    cout << first_occ2(arr, 0, n - 1, x) << "\n";
    cout<<first_occ3(arr,n,x)<<"\n";
    return 0;
}