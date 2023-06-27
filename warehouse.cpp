#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxGoodsPickedUp(int N, int T, int D, vector<int>& goods, vector<int>& pickupTime) {
    vector<int> dp(T + 1, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = T; j >= pickupTime[i]; --j) {
            dp[j] = max(dp[j], dp[j - pickupTime[i]] + goods[i]);
        }
    }

    return dp[T];
}

int main() {
    int N, T, D;
    cin >> N >> T >> D;

    vector<int> goods(N);
    vector<int> pickupTime(N);

    for (int i = 0; i < N; ++i) {
        cin >> goods[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> pickupTime[i];
    }

    int result = findMaxGoodsPickedUp(N, T, D, goods, pickupTime);
    cout << result << endl;

    return 0;
}
