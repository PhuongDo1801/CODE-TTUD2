#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
int x[MAX];
int N, M;
int T; // tổng hiện tại
bool check(int v, int k){
    if(k<N) return true;
    return T + v == M;
}

void solution(){
    for(int i =1; i<=N; i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
void Try(int k){
    for(int v= 1; v <= M-T-(N-k); v++){
        if(check(v, k)){
            x[k] = v;
            T += x[k];
            if(k==N){
                solution();
            }
            else{
                Try(k+1);
            }
            T -= x[k];
        }
    }
}

int main(){
    cin>>N>>M;
    T = 0;
    Try(1);
    return 0;
}