#include<bits/stdc++.h>
using namespace std;

int x[20]; 
int n;
bool visited[20];
bool check(int v, int k){
    if(visited[v] == true) return false;
    return true;
}

void solution(){
    for(int i=1; i<=n; i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
void Try(int k){
    for(int v=1; v<=n; v++){
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
    cin>>n;
    for(int i =1; i<=n; i++) visited[i] = false;
    Try(1);
    return 0;
}