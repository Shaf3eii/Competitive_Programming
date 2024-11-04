// https://www.hackerrank.com/challenges/countingsort2/problem

#include <bits/stdc++.h>

using namespace std;

void countSort(vector<int>& a) {
    int Max = *max_element(a.begin(), a.end());
    vector<int> freq(Max + 1, 0);
    for(auto& i : a)
        freq[i]++;
    for(int i = 0, idx = 0 ; i < Max + 1 ; i++)
        while(freq[i]--)
            arr[idx++] = i;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
