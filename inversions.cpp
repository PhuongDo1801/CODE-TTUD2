#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;    // Index for left subarray
    int j = mid + 1; // Index for right subarray
    int k = left;    // Index for merged subarray

    long long count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += mid - i + 1; // Count inversions
            count %= MOD;        // Take modulo to avoid overflow
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = left; p <= right; ++p) {
        arr[p] = temp[p];
    }

    return count;
}

long long mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        count += mergeSortAndCount(arr, temp, left, mid);
        count %= MOD;
        count += mergeSortAndCount(arr, temp, mid + 1, right);
        count %= MOD;
        count += mergeAndCount(arr, temp, left, mid, right);
        count %= MOD;
    }

    return count;
}

long long countInversions(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);

    long long count = mergeSortAndCount(arr, temp, 0, n - 1);
    count %= MOD;

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long result = countInversions(arr);
    cout << result << endl;

    return 0;
}
