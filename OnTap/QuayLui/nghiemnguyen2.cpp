#include<bits/stdc++.h>
using namespace std;

int N, M;
int x[100];
int T;

bool check(int v, int k){
    // if(T+v > M) return false;
    // if(k>N) return false;
    // return true;

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
    for(int v = 1; v<=M-N-T+k; v++){
        if(check(v, k)){
            x[k] = v;
            T+=x[k];
            if(k==N) solution();
            else{
                Try(k+1);
            }
            T-=x[k];
        }
    }
}

int main(){
    T = 0;
    cin>>N>>M;
    Try(1);
    return 0;
}