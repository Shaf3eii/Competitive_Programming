#include <bits/stdc++.h>

using namespace std;

struct coordinate_compression {
private:
    vector<long long> comp;
    void compress() {
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
    }
public:
    coordinate_compression(vector<long long> & v) {
        comp = v;
        compress();
    }
    int get_index(long long val) {
        return lower_bound(comp.begin(), comp.end(), val) - comp.begin(); // if we need to make it 1-based index add + 1
    }
    int get_origin(size_t idx) {
        return comp[idx];
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
