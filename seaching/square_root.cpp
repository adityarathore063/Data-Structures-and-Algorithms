#include<bits/stdc++.h>
using namespace std;

// Naive solution
int sqroot(int n){
    int i = 1;
    while(i*i<=n)
        i++;
    return (i-1);
}
// Efficient solution(using binary search)
int sqroot1(int n){
    int low = 1, high = n, ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        int mysqr = mid*mid;
        if(mysqr==n)
            return mid;
        else if(mysqr>n)
            high = mid - 1;
        else{
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
int main(){

    int n;
    cin>>n;
    cout<<sqroot(n)<<"\n";
    cout<<sqroot1(n)<<"\n";
    return 0;
}