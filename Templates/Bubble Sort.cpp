#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int>& a) {
    int swaps = 0;
    for (int step = 1; step <= n - 1; step++) {
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                ++swaps;
            }
        }
    }
    cout << "Array is sorted in " << swaps << " swaps.\n";
    cout << "First Element: " << a[0] << '\n';
    cout << "Last Element: " << a[n - 1] << '\n';
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
