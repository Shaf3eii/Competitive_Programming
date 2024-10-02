#include <bits/stdc++.h>

using namespace std;

struct coordinate_compression {
private:
    vector<long long> comp;
    void compression(vector<long long> &v) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(),v.end()), v.end());
    }
public:
    coordinate_compression(vector<long long> &v) {
        comp = v;
        compression(comp);
    }
    int get_index(long long val) {
        return lower_bound(comp.begin(), comp.end(), val) - comp.begin(); // if we need to make it 1-based index add + 1
    }
    long long get_origin(int idx) {
        return comp[idx];
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
