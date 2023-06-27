#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLargestEvenSubsequence(vector<int>& sequence) {
    int n = sequence.size();
    int evenSum = 0;

    for (int i = 0; i < n; ++i) {
        if (sequence[i] % 2 == 0) {
            evenSum += sequence[i];
        }
    }

    // If there are no even numbers in the sequence, return -1 (NOT_FOUND)
    if (evenSum == 0) {
        return -1;
    }

    return evenSum;
}

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    int result = findLargestEvenSubsequence(sequence);
    if (result == -1) {
        cout << "NOT_FOUND" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
