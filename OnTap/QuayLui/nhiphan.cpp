#include<bits/stdc++.h>
using namespace std;

int n;
int x[100];
bool check(int v, int k){
    return true;
}

void solution(){
    for(int i= 1; i<=n; i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
void Try(int k){
    for(int v = 0; v<=1; v++){
        if(check(v, k)){
            x[k] = v;
            if(k==n){
                solution();
            }
            else{
                Try(k+1);
            }
        }
    }
}

int main(){
    n=3;
    Try(1);
    return 0;
}