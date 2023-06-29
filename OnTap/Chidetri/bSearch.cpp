#include<bits/stdc++.h>
using namespace std;

int N;
int x[100];

void input(){
    cin>>N;
    for(int i = 0; i< N; i++){
        cin>>x[i];
    }
}

int bSearch(int start, int finish, int y){
    if(start == finish){
        if(x[start] == y) return start;
        else return -1;
    }
    else{
        int m = (start + finish)/2;
        if(x[m] == y) return m;
        if(x[m]<y) return bSearch(m+1, finish, y);
        else return bSearch(start, m-1, y);
    }

}

int main(){
    int y;
    cin>>y;
    input();
    int res = bSearch(0, N-1, y);
    cout<<res;
    return 0;
}