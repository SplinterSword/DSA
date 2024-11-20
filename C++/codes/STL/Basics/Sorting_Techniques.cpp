#include <iostream>
using namespace std;

void bubblesort(int arr[], int n){
    for (int i = 0; i<n;i++){
        for (int j=0; j<n-i-1;j++){
            if (arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selectionsort(int arr[], int n) {
    for (int i=0; i<n; i++) {
        int minPos = i;
        for (int j=i+1;j<n;j++){
            if (arr[minPos] > arr[j]){
                minPos = j;
            }
        }

        swap(arr[i],arr[minPos]);
    }
}

void insertionsort(int arr[], int n){
    for (int i=1;i<n;i++){
        int j = i-1;
        int key = arr[i];

        while (j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}


void print(int arr[]) {
    for (int i=0;i<5;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int bubble[5] = {1,2,36,5,4};
    int selection[5] = {2,4,56,7,8};
    int insertion[5] = {3,6,4,8,2};

    bubblesort(bubble,5);
    selectionsort(selection,5);
    insertionsort(insertion,5);

    print(bubble);
    print(selection);
    print(insertion);

    return 0;
}