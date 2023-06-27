#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findMaxSubsetDistance(int N, int C, vector<int>& elements) {
    sort(elements.begin(), elements.end());  // Sort the elements in ascending order

    int left = 0;
    int right = elements[N - 1] - elements[0];  // Maximum possible distance between any two elements

    int maxDistance = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        int count = 1;  // Start with one element
        int prev = elements[0];

        for (int i = 1; i < N; ++i) {
            if (elements[i] - prev >= mid) {
                count++;
                prev = elements[i];
            }
        }

        if (count >= C) {
            maxDistance = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return maxDistance;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, C;
        cin >> N >> C;

        vector<int> elements(N);
        for (int i = 0; i < N; ++i) {
            cin >> elements[i];
        }

        int result = findMaxSubsetDistance(N, C, elements);
        cout << result << endl;
    }

    return 0;
}
