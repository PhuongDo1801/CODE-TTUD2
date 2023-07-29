#include<bits/stdc++.h>
using namespace std;

int A[100];
int n;
int x;

int bSearch(int A[], int start, int finish){
    if(start == finish && A[start] == x) return start;
    else{
        int mid = (start + finish)/2;
        if(A[mid] == x) return mid;
        if(A[mid] > x){
            bSearch(A, start, mid);
        }
        else return bSearch(A, mid+1, finish);
    }
    return -1;
}


int main(){
    cin>>n;
    cin>>x;
    for(int i = 0; i<n; i++){
        cin>>A[i];
    }
    cout<<bSearch(A, 0, n-1);
    return 0;
}