#include<bits/stdc++.h>
using namespace std;

int x[10];
bool visited[10];
int n;

bool check(int v, int k){
    if(visited[v] == true) return false;
    return true;
}

void input(){
    cin>>n;
    for(int i=1; i<=n; i++){
        visited[i] = false;
    }
}
void solution(){
    for(int i =1; i<=n; i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
void Try(int k){
    for(int v = 1; v<=n; v++){
        if(check(v, k)){
            visited[v] = true;
            x[k] = v;
            if(k==n){
                solution();
            }
            else{
                Try(k+1);
            }
            visited[v] = false;
        }
    }
}

int main(){
    input();
    Try(1);
    return 0;
}