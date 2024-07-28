#include <iostream>
#include <vector>
using namespace std;

/*
Time Complexity
avg case=O(nlogn)
best case=O(nlogn)
worst case=O(n^2)
*/

//space complexity=O(n);


void quickSort(vector<int> &arr,int start, int end){
    if (start >= end){
        return;
    }
    int pivot = end;
    int i = start;
    int j = end;

    // Handling elements
    while (i!=j){
        if (arr[i] < arr[pivot]){
            i++;
            continue;
        }

        j--;
        swap(arr[i],arr[j]);
    }

    // Putting Piviot in right place
    swap(arr[j],arr[pivot]);

    //left part
    quickSort(arr,start,i-1);

    //right part
    quickSort(arr,i+1,end);
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;

    for (int i=0 ;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }

    quickSort(arr,0,arr.size()-1);

    for (int i=0 ;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}