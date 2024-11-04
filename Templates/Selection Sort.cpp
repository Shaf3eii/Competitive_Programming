#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int>& a) {
    int swaps = 0;
    for (int i = 1; i <= n; i++) {
        int min_index = i;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if (i != min_index) {
            swap(a[i], a[min_index]);
            ++swaps;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    cout << swaps << '\n';
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
