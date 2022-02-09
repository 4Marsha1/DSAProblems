#include <bits/stdc++.h>
using namespace std;

int findFloor(int a[], int n, int k){
    int start=0,end=n-1,ans=-1;
    while(start<=end){
        int mid = (start+(end-start)/2);
        if(a[mid]==k)
            return mid;
        else if(a[mid]>k)
            end=mid-1;
        else{
            ans=mid;
            start=mid+1;
        }
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<< findFloor(a,n,k);
}