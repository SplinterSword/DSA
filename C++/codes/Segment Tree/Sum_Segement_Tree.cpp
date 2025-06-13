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
    segTree[index] = segTree[2*index+1] + segTree[2*index+2];
    return;
}


int querySegmentTree(int *segTree, int index, int start, int end, int requiredStart, int requiredEnd) {
    // completely inside
    if (requiredStart <= start && requiredEnd >= end) {
        return segTree[index];
    }

    // completely outside
    if (start > requiredEnd || end < requiredStart) {
        return 0;
    }
    
    // Overlap both Partial and Fully
    int mid = (start + end) / 2;
    int left = querySegmentTree(segTree, 2*index+1, start, mid, requiredStart, requiredEnd);
    int right = querySegmentTree(segTree, 2*index+2, mid + 1, end, requiredStart, requiredEnd);
    return left + right;
}

void pointUpdate(int *segTree, int index , int start, int end, int updateIndex, int updateValue) {
    if (start == end && start == updateIndex) {
        segTree[index] += updateValue;
        return;
    }

    int mid = (start + end) / 2;
    
    if (updateIndex > mid) {
        pointUpdate(segTree, 2*index+2, mid + 1, end, updateIndex, updateValue);
    }
    else {
        pointUpdate(segTree, 2*index+1, start, mid, updateIndex, updateValue);
    }

    segTree[index] = segTree[2*index+1] + segTree[2*index+2];

    return;
}

// Lazy Propogation

void rangeUpdate(int *segTree, int *lazyTree, int index, int start, int end, int requiredStart, int requiredEnd, int updateValue) {
    
    //check for suspended update and if there update
    if (lazyTree[index] != 0) {
        segTree[index] = (end - start + 1) * lazyTree[index];
        if (start != end) {
            lazyTree[2*index+1] += lazyTree[index];
            lazyTree[2*index+2] += lazyTree[index];
        }
        lazyTree[index] = 0;
    }

    // completely inside
    if (requiredStart <= start && requiredEnd >= end) {
        segTree[index] = (end - start + 1) * updateValue;
        if (start != end) {
            lazyTree[2*index+1] += updateValue;
            lazyTree[2*index+2] += updateValue;
        }
        return;
    }

    // completely outside
    if (start > requiredEnd || end < requiredStart) {
        return;
    }
    
    // Overlap both Partial and Fully
    int mid = (start + end) / 2;
    rangeUpdate(segTree, lazyTree, 2*index+1, start, mid, requiredStart, requiredEnd, updateValue);
    rangeUpdate(segTree, lazyTree, 2*index+2, mid + 1, end, requiredStart, requiredEnd, updateValue);
    segTree[index] = segTree[2*index+1] + segTree[2*index+2];
    return;
}

int queryLazy(int *segTree, int *lazyTree, int index, int start, int end, int requiredStart, int requiredEnd) {

    //check for suspended update and if there update
    if (lazyTree[index] != 0) {
        segTree[index] = (end - start + 1) * lazyTree[index];
        if (start != end) {
            lazyTree[2*index+1] += lazyTree[index];
            lazyTree[2*index+2] += lazyTree[index];
        }
        lazyTree[index] = 0;
    }

    // completely inside
    if (requiredStart <= start && requiredEnd >= end) {
        return segTree[index];
    }

    // completely outside
    if (start > requiredEnd || end < requiredStart) {
        return 0;
    }
    
    // Overlap both Partial and Fully
    int mid = (start + end) / 2;
    int left = queryLazy(segTree, lazyTree, 2*index+1, start, mid, requiredStart, requiredEnd);
    int right = queryLazy(segTree, lazyTree, 2*index+2, mid + 1, end, requiredStart, requiredEnd);
    return left + right;
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
    int *lazyTree = new int[4*n]();
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

    pointUpdate(segTree,0, 0, n-1, 1, 1);

    cout << "The maximum of elements in the range [" << 0 << ", " << 2 << "] is " 
             << querySegmentTree(segTree, 0, 0, n-1, 0, 2) << endl;

    // Lazy Propogations
    rangeUpdate(segTree, lazyTree, 0, 0, n-1, 0, 2, 1);

    cout << "The maximum of elements in the range [" << 0 << ", " << 9 << "] is " 
             << queryLazy(segTree, lazyTree, 0, 0, n-1, 0, 9) << endl;


    delete[] arr;
    delete[] segTree;
    delete[] lazyTree;
    return 0;
}
