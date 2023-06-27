#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int start;
    int end;
};

bool compareSegments(const Segment& s1, const Segment& s2) {
    return s1.end < s2.end;
}

int findLargestNonIntersectingSubset(vector<Segment>& segments) {
    sort(segments.begin(), segments.end(), compareSegments);

    int count = 0;
    int prevEnd = -1;

    for (const Segment& segment : segments) {
        if (segment.start > prevEnd) {
            count++;
            prevEnd = segment.end;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<Segment> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].start >> segments[i].end;
    }

    int result = findLargestNonIntersectingSubset(segments);
    cout << result << endl;

    return 0;
}
