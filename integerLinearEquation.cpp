#include <iostream>
#include <vector>

using namespace std;

int countSolutions(int n, int M, vector<int>& a, int sum, int index) {
    if (sum == M) {
        return 1;  // Found a valid solution
    }

    if (sum > M || index >= n) {
        return 0;  // Exceeded the target sum or reached the end of the array
    }

    int count = 0;

    // Include the current element and recursively search for the next element
    if (sum + a[index] <= M) {
        count += countSolutions(n, M, a, sum + a[index], index + 1);
    }

    // Exclude the current element and recursively search for the next element
    count += countSolutions(n, M, a, sum, index + 1);

    return count;
}

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int result = countSolutions(n, M, a, 0, 0);
    cout << result << endl;

    return 0;
}
