#include <bits/stdc++.h>
using namespace std;

void update(int *fenWick, int n, int i, int updateValue) {
    while (i <= n) {  
        fenWick[i] += updateValue;
        i += (i & (-i));
    }
}

int* createFenwickTree(int *arr, int n) {
    if (n <= 0) return nullptr;
    
    int *fenWick = new int[n + 1]();
    
    for (int i = 0; i < n; i++) {
        update(fenWick, n, i + 1, arr[i]);
    }
    return fenWick;
}

int sum(const int *fenWick, int i) {
    int result = 0;
    while (i > 0) {
        result += fenWick[i];
        i -= (i & (-i));
    }
    return result;
}

int rangeSum(const int *fenWick, int l, int r) {
    if (l > r || l < 1) return 0;  
    return sum(fenWick, r) - sum(fenWick, l - 1);
}
void deleteFenwickTree(int* fenWick) {
    delete[] fenWick;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }
    
    int *arr = new int[n];
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int *fenWick = createFenwickTree(arr, n);
    
    cout << "Enter the left and right indices (1-based): ";
    int l, r;
    cin >> l >> r;
    
    if (l < 1 || r > n || l > r) {
        cout << "Invalid range! Indices must be between 1 and " << n << endl;
    } else {
        cout << "Sum from index " << l << " to " << r << " is: " 
             << rangeSum(fenWick, l, r) << endl;
    }
    
    // Clean up
    delete[] arr;
    deleteFenwickTree(fenWick);     
    return 0;
}