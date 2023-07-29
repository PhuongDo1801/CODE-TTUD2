#include<bits/stdc++.h>
using namespace std;

const int MAX = 2000;

int N, K1, K2;
void input(){
    cin>>N>>K1>>K2;
}

void solve(){
    int S0[MAX];
    int S1[2000];
    for(int i=1; i<=N; i++){
        S0[i] = 0;
        S1[i] = 0;
    }
    S0[1] = 1; S1[K1] = 1; S0[0] = 1;
    for(int i =K1+1; i<=N; i++){
        S0[i] = S1[i-1];
        S1[i] = 0;
        for(int j=K1; j<=K2; j++){
            if(i-j>=0){
                S1[i] = S1[i] + S0[i-j];
            }
        }
    }
    int res = S0[N] + S1[N];
    cout<<res;
}

int main(){
    input();
    solve();
    return 0;
}


