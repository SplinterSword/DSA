#include <bits/stdc++.h>
using namespace std;

void buildSegmentTree(int *arr, int *segTree, int index, int start, int end) {
    if (start > end) return;  // Add bounds check
    if (start == end) {
        segTree[index] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildSegmentTree(arr, segTree, 2*index+1, start, mid);
    buildSegmentTree(arr, segTree, 2*index+2, mid+1, end);
    segTree[index] = max(segTree[2*index+1], segTree[2*index+2]);
    return;
}


int querySegmentTree(int *segTree, int index, int start, int end, int requiredStart, int requiredEnd) {
    // completely inside
    if (requiredStart <= start && requiredEnd >= end) {
        return segTree[index];
    }

    // completely outside
    if (start > requiredEnd || end < requiredStart) {
        return INT_MIN;
    }
    
    // Overlap both Partial and Fully
    int mid = (start + end) / 2;
    int left = querySegmentTree(segTree, 2*index+1, start, mid, requiredStart, requiredEnd);
    int right = querySegmentTree(segTree, 2*index+2, mid + 1, end, requiredStart, requiredEnd);
    return max(left, right);
}

int main() {
    int n;
    cout << "Enter the size of the array-";
    cin >> n;
    int *arr = new int[n];
    
    cout << "Enter the elements of the array-";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int *segTree = new int[4*n];
    buildSegmentTree(arr, segTree, 0, 0, n-1);

    int q;
    cout << "Enter the number of queries-";
    cin >> q;

    cout << "Enter the queries (0-based indexing)-";
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l < 0 || r >= n || l > r) {
            cout << "Invalid range!" << endl;
            continue;
        }
        cout << "The maximum of elements in the range [" << l << ", " << r << "] is " 
             << querySegmentTree(segTree, 0, 0, n-1, l, r) << endl;
    }

    delete[] arr;
    delete[] segTree;
    return 0;
}
