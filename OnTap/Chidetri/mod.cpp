#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
// (x * y) % P = ((x % P) * (y % P)) % P

const ull P = 1e9+7;

ull exp(int x, ull N){
    x = x%P;
    if(N==1) return x;
    ull t = exp(x, N/2);
    t = (t*t)%P;
    if(N%2==1) t = (t*x) %P;
    return t;
}

int main(){
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ull x, N;
    cin>>x>>N;
    ull res = exp(x, N);
    cout<<res;
    return 0;
}