#include<bits/stdc++.h>
using namespace std;

int x[100];
int n;
bool visited[100];

bool check(int v, int k){
    //if(x[k-1] == v && k>1) return false;
    return true;
}

void solution(){
    for(int i =1; i<=n; i++){
        cout<<x[i];
    }
    cout<<endl;
}

void Try(int k){
    for(int v=0; v<=1; v++){
        if(check(v, k)){
            //visited[v]=true;
            x[k]=v;
            if(k==n){
                solution();
            }
            else{
                Try(k+1);
            }
            //visited[v]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    memset(visited, false, sizeof(visited));
    // for(int i=1; i<=n; i++){
    //     visited[i]=false;
    // }
    Try(1);
    return 0;
}