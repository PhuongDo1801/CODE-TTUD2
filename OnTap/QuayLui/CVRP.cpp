#include<bits/stdc++.h>
using namespace std;

const int MAX_K = 10;
const int MAX_N = 20;
int N; // số khách hàng
int K; // Số xe
int Q; // Tải trọng 1 xe
int d[MAX_N]; // lượng hàng yêu cầu của KH v
int y[MAX_K]; // diểm đầu tiên trên lộ trình của xe thứ k
int x[MAX_N]; // điểm tiếp theo của điểm n
int visited[MAX_N]; // đánh dấu điểm n
int load[MAX_N]; // load[k] là tổng trọng tải trên lộ trình k
int segments; // Số chặng trên các lộ trình


void solution(){
    for(int k=1; k<=K; k++){
        cout<<"Route["<<k<<"]: 0";
        int v = y[k];
        while (v>0)
        {
            cout<<" - "<< v;
            v= x[v];
        }
        cout<<" - 0"<<endl;
    }

    cout<<"---------------------------"<<endl;
}
bool check(int v, int u, int k){
    if(v==0) return true;
    if(visited[v] == true) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}
void TryX(int u, int k){
    for(int v=0; v<=N; v++){
        if(check(v, u, k)){
            x[u] =v;
            visited[v] = true;
            load[k] += d[v];
            segments +=1;
            if(v==0){
                if(k ==K){
                    if(segments == N + K){
                        solution();
                    }
                }
                else{
                    TryX(y[k+1], k +1);
                }
            }
            else{
                TryX(v, k);
            }
            visited[v] = false;
            load[k] -= d[v];
            segments -= 1;
        }
    }

}

bool check(int v, int k){
    if(visited[v] == true) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}
void TryY(int k){
    for(int v=y[k-1] + 1; v<=N; v++){
        if(check(v, k)){
            y[k] = v;
            load[k] += d[v];
            visited[v] = true;
            segments +=1;
            if(k==K){
                TryX(y[1], 1);
            }
            else{
                TryY(k+1);
            }
            load[k] -= d[v];
            segments -=1;
            visited[v] = false;
        }
    }
}
void input(){
    cin>> N >> K >> Q;
    for(int i = 1; i<=N; i++) cin>>d[i];
}

void solve(){
    for(int i =1; i<=N; i++){
        visited[i] = false;
    }
    for(int k =1; k<=K; k++){
        load[k] = 0;
    }
    segments = 0;
    y[0] = 0;
    TryY(1);
}
int main(){
    input();
    solve();
    return 0;
}