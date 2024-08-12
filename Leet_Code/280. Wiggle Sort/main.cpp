#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto& i : arr)
        cin >> i;
    sort(arr.begin(),arr.end());
    for(int i = 1 ; i < n - 1 ; i += 2)
        swap(arr[i],arr[i + 1]);
    for(auto i : arr)
        cout << i << " ";
    cout << '\n';    return 0;
}
