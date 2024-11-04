#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int>& a) {
    for (int i = 1; i <= n; i++) {
        int j = i - 1, x = a[i];
        while (j >= 1 and a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& i : arr) cin >> i;
    countSort(arr);
    for(auto& i : arr)
        cout << i << ' ';
    return 0;
}
