#include <bits/stdc++.h>
using namespace std;
 
int n, m, r, c, mat[1000][1000];
struct Point
{
    int x;
    int y;
};
 
struct queueNode
{
    Point pt;  
    int dist;  
};
 
bool isValid(int row, int col)
{
    return (row >= 0) && (row < n) &&
           (col >= 0) && (col < m);
}
 
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
 
int BFS(Point src)
{
    if (mat[src.x][src.y] == 1)
        return -1;
 
    bool visited[n][m];
    memset(visited, false, sizeof visited);
     
    visited[src.x][src.y] = true;
 
    queue<queueNode> q;
     
    queueNode s = {src, 0};
    q.push(s);
 
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;
 
        if (pt.x == 0 || pt.x == n - 1 || pt.y == 0 || pt.y == m - 1) {
        	return curr.dist;
		}
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
             
            if (isValid(row, col) && mat[row][col] == 0 &&
               !visited[row][col])
            {
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},
                                      curr.dist + 1 };
                q.push(Adjcell);
            }
        }
    }
 
    return -1;
}
 
int main()
{
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cin >> mat[i][j];
		}
	}
    Point source = {r - 1, c - 1};
 
    int dist = BFS(source);
 
    cout << dist + 1 ;
    return 0;
}

