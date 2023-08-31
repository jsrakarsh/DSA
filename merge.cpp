#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> brr;
    int i = low;
    int j = mid+1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            brr.push_back(arr[i]);
            i++;
        } else {
            brr.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        brr.push_back(arr[i]);
        i++;
    }
    while (j <= high) {
        brr.push_back(arr[j]);
        j++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = brr[i-low];
    }
}

void ms(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    ms(arr, low, mid);
    ms(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main() {
    vector<int> a = {1, 7, 5, 8, 10, 12, 16, 17, 19, 23};
    int n = a.size();
    cout << "Before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    ms(a, 0, n-1);
    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
