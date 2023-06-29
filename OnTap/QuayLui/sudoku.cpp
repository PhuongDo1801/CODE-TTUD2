#include<bits/stdc++.h>
using namespace std;

int x[9][9];
bool markR[9][10], markC[9][10];
bool markS[3][3][10];

void solution(){
    for(int i =1; i<=9; i++){
        for(int j =1; j<=9; j++){
            cout<<x[i][j];
        }
        cout<<endl;
    }
    cout<<"------------------"<<endl;
}

bool check(int r, int c, int v){
    if(markR[r][v] == true) return false;
    if(markC[c][v] == true) return false;
    if(markS[r/3][c/3][v] == true) return false;
    return true;
}
void Try(int r, int c){
    for(int v=1; v<=9; v++){
        if(check(r, c, v)){
            markC[c][v] = true;
            markR[r][v] = true;
            markS[r/3][c/3][v] = true;
            x[r][c] = v;
            if(r == 8 && c== 8){
                solution();
            }
            else{
                if(c==8){
                    Try(r+1, 1);
                }
                else{
                    Try(r, c+1);
                }
            } 
            markC[c][v] = false;
            markR[r][v] = false;
            markS[r/3][c/3][v] = false;      
        }
    }
}
int main() {
    for(int v=1; v<=9; v++){
        for(int r=0; r<=8; r++) markR[r][v] = false;
        for(int c=0; c<=8; c++) markC[c][v] = false;
        for(int I= 0; I<=2; I++){
            for(int J=0; J<=2; J++){
                markS[I][J][v] = false;
            }
        }
    }
    Try(0, 0);
    return 0;
}