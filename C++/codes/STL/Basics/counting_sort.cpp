#include <iostream>
#include <map>
using namespace std;

void countingSort(int arr[], int n){
    map<int,int> frequency;

    // frequency count
    for(int i=0;i<n;i++){
        frequency[arr[i]]++;
    }


    int main = 0;

    auto iter = frequency.begin();

    while(iter != frequency.end()) {
        while(iter->second != 0) {
            arr[main++] = iter->first;
            iter->second--;
        }
        iter++;
    }
}

void print(int arr[]) {
    for (int i=0;i<5;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {52,3,1,1,5};
    countingSort(arr,5);
    print(arr);

    return 0;
}