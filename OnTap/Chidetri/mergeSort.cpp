#include<bits/stdc++.h>
using namespace std;
int x[100];
int A[100];
int n;
void merge(int A[], int l, int mid, int r){
    int i = l, j = mid+1;
    for(int k = l; k<=r; k++){
        if(i>mid){
            x[k] = A[j];
            j++;
        }
        else if(j>r){
            x[k] = A[i];
            i++;
        }
        else{
            if(A[i] < A[j]){
                x[k] = A[i];
                i++;
            }
            else{   
                x[k] = A[j];
                j++;
            }
        }
    }
    for(int k=l; k<=r; k++){
        A[k] = x[k];
    }
}

void mergeSort(int A[], int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(A, l, mid);
        mergeSort(A, mid+1, r);
        merge(A, l, mid, r);
    }
}
void input(){
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>A[i];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    mergeSort(A, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<A[i];
    }
    return 0;
}