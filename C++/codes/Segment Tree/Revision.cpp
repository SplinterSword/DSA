#include <bits/stdc++.h>
using namespace std;

void buildSegmentTree(int *arr, int *segTree, int start, int end, int index) {
    if (start > end) return;

    if (start == end) {
        segTree[index] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildSegmentTree(arr,segTree,start,mid,2*index+1);
    buildSegmentTree(arr,segTree,mid+1,end,2*index+2);
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

    // overlapping partially or fully
    int mid = (start + end) / 2;

    int left = querySegmentTree(segTree,2*index+1,start,mid,requiredStart,requiredEnd);
    int right = querySegmentTree(segTree,2*index+2,mid+1,end,requiredStart,requiredEnd);

    return left + right;
}

void pointUpdate (int *segTree, int index , int start, int end, int updateIndex, int updateValue){
    if (start > end) return;

    if (start == end && start == updateIndex) {
        segTree[index] += updateValue;
        return;
    }

    int mid = (start + end) / 2;
    
    if (updateIndex <= mid) {
        pointUpdate(segTree,2*index+1,start,mid,updateIndex,updateValue);
    } 
    else {
        pointUpdate(segTree,2*index+2,mid+1,end,updateIndex,updateValue);
    }

    segTree[index] = segTree[2*index+1] + segTree[2*index+2];

    return;
}

// lazy propogation

void rangeUpdate(int *segTree, int *lazyTree, int index, int start, int end, int requiredStart, int requiredEnd, int updateValue) {
    // handle lazy
    if (lazyTree[index] != 0) {
        int range = end - start + 1;
        int value = range * lazyTree[index];
        segTree[index] += value;

        if (start != end) {
            lazyTree[2*index+1] += lazyTree[index];
            lazyTree[2*index+2] += lazyTree[index];
        }

        lazyTree[index] = 0;
    }

    // completely inside
    if (start >= requiredStart && end <= requiredEnd) {
        int range = end - start + 1;
        int value = range * updateValue;
        segTree[index] += value;

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
    // handle lazy
    if (lazyTree[index] != 0) {
        int range = end - start + 1;
        int value = range * lazyTree[index];
        segTree[index] += value;

        if (start != end) {
            lazyTree[2*index+1] += lazyTree[index];
            lazyTree[2*index+2] += lazyTree[index];
        }

        lazyTree[index] = 0;
    }

    // completely inside
    if (start >= requiredStart && end <= requiredEnd) {
        return segTree[index];
    }

    // completely outside
    if (start > requiredEnd || end < requiredStart) {
        return 0;
    }

    // overlapping partially or fully
    int mid = (start + end) / 2;

    int left = querySegmentTree(segTree,2*index+1,start,mid,requiredStart,requiredEnd);
    int right = querySegmentTree(segTree,2*index+2,mid+1,end,requiredStart,requiredEnd);

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
    buildSegmentTree(arr, segTree, 0, n-1, 0);

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
        cout << "The sum of elements in the range [" << l << ", " << r << "] is " 
             << querySegmentTree(segTree, 0, 0, n-1, l, r) << endl;
    }

    pointUpdate(segTree,0, 0, n-1, 1, 1);

    cout << "The sum of elements in the range [" << 0 << ", " << 2 << "] is " 
             << querySegmentTree(segTree, 0, 0, n-1, 0, 2) << endl;

    // Lazy Propogations
    rangeUpdate(segTree, lazyTree, 0, 0, n-1, 0, 2, 1);

    cout << "The sum of elements in the range [" << 0 << ", " << 9 << "] is " 
             << queryLazy(segTree, lazyTree, 0, 0, n-1, 0, 9) << endl;


    delete[] arr;
    delete[] segTree;
    delete[] lazyTree;
    return 0;
}
