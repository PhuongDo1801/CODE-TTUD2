#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, a[N][N], h[N], l[N], r[N];
// n và m là kích thước ma trận
int main() {
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j]; // nhập thông tin ma trận
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                h[j]++;
            } else {
                h[j] = 0;
            }
        }
        for (int j = 1; j <= m; j++) {
            l[j] = j;
            while (l[j] > 1 && h[j] <= h[l[j] - 1]) {
                l[j] = l[l[j] - 1];
            }
        }
        for (int j = m; j >= 1; j--) {
            r[j] = j;
            while (r[j] < m && h[j] <= h[r[j] + 1]) {
                r[j] = r[r[j] + 1];
            }
        }
        for (int j = 1; j <= m; j++) {
            res = max(res, h[j] * (r[j] - l[j] + 1));
        }
    }
    cout << res << endl;
    return 0;
}
