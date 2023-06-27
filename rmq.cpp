#include <bits/stdc++.h>
using namespace std;
 
long long n, m, a[1000000], M[1000000][50];

void process() {
	long long i, j;
	
	for (i = 0; i < n; i++) {
		M[i][0] = i;
	}
	
	for (j = 1; 1 << j <= n; j++) {
		for (i = 0; i + (1 << j)- 1 < n; i++) {
			if (a[M[i][j - 1]] < a[M[i + (1 << (j - 1))][j - 1]])
				M[i][j] = M[i][j - 1];
			else M[i][j] = M[i + (1 << (j - 1))][j - 1];
		}
	}
}

long long solve(int i, int j) {
	int k = floor(log(j - i + 1) / log(2));
	if (a[M[i][k]] <= a[M[j - (1 << k) + 1][k]]) return a[M[i][k]];
	else return a[M[j - (1 << k) + 1][k]];
	
}
 
int main()
{
	long long rs = 0;
	
    cin >> n;
	for  (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	process();
	
	cin >> m;
	for (long long i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		rs += solve(tmp1, tmp2);
	}
	
	cout << rs;
	
    return 0;
}

