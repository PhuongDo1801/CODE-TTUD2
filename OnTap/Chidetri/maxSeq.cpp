#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> x;

void input(){
    cin>>n;
    x.resize(n);
    for(int i = 0; i<n; i++){
        cin>>x[i];
    }
}

int maxLeft(vector<int> a, int l, int r){
    int max = 1e-9;
    int s = 0;
    for(int i = r; i>= l; i--){
        s += a[i];
        if(s > max) max = s;
    }
    return max;
}

int maxRight(vector<int> a, int l, int r){
    int max = 1e-9;
    int s = 0;
    for(int i = l; i<=r; i++){
        s += a[i];
        if(s > max) max = s;
    }
    return max;
}

int seqMax(vector<int> a, int l, int r){
    if(l==r) return a[1];
    int max;
    int mid = (l+r)/2;
    int mL=seqMax(a, l, mid);
    int mR=seqMax(a, mid+1, r);
    int mLR= maxLeft(a, l, mid) + maxRight(a, mid+1, r);
    max = mL;
    if(mR > max) max = mR;
    if(mLR > max) max = mLR;
    return max;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    int res = seqMax(x, 0, n-1);
    cout<<res;
    return 0;
}